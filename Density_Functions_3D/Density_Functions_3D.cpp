#include <gemmi/cif.hpp>

#include "Read_Framework_Parameters.h"
#include "Read_T2L_File_Names.h"
#include "Read_Experiment.h"
#include "Read_Input.h"
#include "Initialise_Lattice.h"
#include "Read_V.h"
#include "Threads.h"
#include "Write_Experiment_Data.h"
#include "Plot_Experiments.h"
#include "Print_Info.h"

int main( int, char*[] )
{
    clock_t start_code_runtime = clock(); // Starts the clock measuring the runtime of the code.
    
    chrono::time_point<chrono::steady_clock> start_absolute_time = chrono::steady_clock::now(); // Starts the clock measuring the absolute time to complete the code.
    
    srand( (int)time( 0 ) ); // Seeding the random number generator.
    
    Framework_Parameters f_p; // Class containing details of what functions to run etc.
    
    if (!Read_Framework_Parameters( f_p )) return 1; // Reading the framework parameters.
    
    vector<string> T2L_labels;
    
    if (f_p.T2L) Read_T2L_File_Names( f_p, T2L_labels );
    
    Experiment e; // Class containing information about the type of experiment to be performed.
    
    if (!Read_Experiment( f_p, e )) return 1; // Reading the experiment.
    
    ifstream ifs_1( f_p.input_dir + f_p.input_file ); // Opening the input file.
    
    if (!ifs_1.is_open())
    {
        cout << "Input file not found!" << endl;
        return 1;
    }
    
    int num_inputs = 0; // Counter for the number of inputs.
    string line_data; // Generic string.
    Experiment_Data e_d( e ); // Class containing all the statistics about the experiment.
    
    while (getline( ifs_1, line_data )) // Looping over the inputs.
    {
        ++num_inputs; // Increase number of inputs counter.
        
        Input input; // Class containing all the information about the input.
        input.num_input = num_inputs;
        
        if (!Read_Input( f_p, line_data, input )) return 1; // Reading the input.
        
        Initialise_Lattice( input ); // Computing the transformation matrix and the lattice vectors.
        
        ifstream ifs_2( f_p.input_dir + f_p.v_file ); // Opening the file containing 'V' point sets.
        
        if (!ifs_2.is_open())
        {
            cout << "V file not found!" << endl;
            return 1;
        }
        
        while ((f_p.uplusv && getline( ifs_2, line_data )) || input.num_v == 0) // If uplusv, looping over V, else goes once through.
        {
            ++input.num_v;
            
            if (f_p.uplusv && !Read_V( f_p, line_data, input )) return 1; // Reading the V file.
            
            for (int motif_iter = 0; motif_iter < e.motif_sizes.size(); ++ motif_iter) // Looping over motif sizes.
            {
                input.motif_iter = motif_iter;
                input.random_pts = e.motif_sizes[motif_iter] - (int)input.frac_base_pts.size();
                
                for (int k_iter = 0; k_iter < e.k.size(); ++k_iter) // Looping over maximum zone k.
                {
                    input.k_iter = k_iter;
                    input.zone_limit = input.perim = e.k[k_iter];
                    
                    vector<thread> thr;
                    thr.reserve( 2 );
                    
                    for (int rep_iter = f_p.T2_start_index; rep_iter < e.repetitions + f_p.T2_start_index; ++rep_iter) // Repeating e.repetitions times.
                    {
                        cout << "Repetition " << rep_iter << ":" << endl << endl;
                        
                        input.rep_iter = rep_iter;
                        if (f_p.T2L) input.T2L_label = T2L_labels[rep_iter - 1];
                        
                        if (f_p.use_threads_2)
                        {
                            thr.push_back( thread( Threads, f_p, input, rep_iter, e_d ) );
                        }
                        
                        else
                        {
                            Add_Random_Pts( input ); // Adding input.random_pts number of random points.
                        
                            Initialise_Pt_Cloud( f_p, input, rep_iter, f_p.uplusv ); // Producing the vector of base points in Cartesian coordinates.
                            
                            if (!f_p.replot) Brillouin_Algorithm( f_p, input, e_d ); // Main computations occur here.
                            
                            if (f_p.plot_graph) Plot_Graph( f_p, input ); // Plotting the graph.
                        }
                    }
                    
                    if (f_p.use_threads_2)
                    {
                        for (int rep_iter = f_p.T2_start_index; rep_iter < e.repetitions + f_p.T2_start_index; ++rep_iter) // Repeating e.repetitions times.
                        {
                            thr[rep_iter - 1].join();
                        }
                    }
                }
            }
        }
        
        ifs_2.close();
    }
    
    ifs_1.close();
    
    if (f_p.time_vary_k)
    {
        for (int counter_1 = 1; counter_1 < e.motif_sizes.size(); ++counter_1)
        {
            for (int counter_2 = 0; counter_2 < e.k.size(); ++counter_2)
            {
                e_d.m_time[0].second[counter_2].second += e_d.m_time[counter_1].second[counter_2].second;
            }
            
            e_d.num_runs[0][0] += e_d.num_runs[counter_1][0];
        }
        
        for (int counter = 0; counter < e.k.size(); ++counter)
        {
            e_d.m_time[0].second[counter].second = 1000 * e_d.m_time[0].second[counter].second / (double)(e_d.num_runs[0][0] * CLOCKS_PER_SEC);
        }
    }
    
    else if (f_p.vary_k)
    {
        for (int counter_1 = 1; counter_1 < e.motif_sizes.size(); ++counter_1)
        {
            for (int counter_2 = 0; counter_2 < e.k[0]; ++counter_2)
            {
                e_d.m_vertices[0].second[counter_2] += e_d.m_vertices[counter_1].second[counter_2];
                e_d.m_edges[0].second[counter_2] += e_d.m_edges[counter_1].second[counter_2];
                e_d.m_polys[0].second[counter_2] += e_d.m_polys[counter_1].second[counter_2];
                e_d.m_perim[0].second[counter_2] += e_d.m_perim[counter_1].second[counter_2];
            }
            
            e_d.num_runs[0][0] += e_d.num_runs[counter_1][0];
        }
        
        for (int counter = 0; counter < e.k[0]; ++counter)
        {
            e_d.m_vertices[0].second[counter] = e_d.m_vertices[0].second[counter] / (double)e_d.num_runs[0][0];
            e_d.m_edges[0].second[counter] = e_d.m_edges[0].second[counter] / (double)e_d.num_runs[0][0];
            e_d.m_polys[0].second[counter] = e_d.m_polys[0].second[counter] / (double)e_d.num_runs[0][0];
            e_d.m_perim[0].second[counter] = e_d.m_perim[0].second[counter] / (double)e_d.num_runs[0][0];
        }
    }
    
    else
    {
        for (int counter_1 = 0; counter_1 < e.motif_sizes.size(); ++counter_1)
        {
            for (int counter_2 = 0; counter_2 < e.k.size(); ++counter_2)
            {
                e_d.m_time[counter_1].second[counter_2].second = 1000 * e_d.m_time[counter_1].second[counter_2].second / (double)(e_d.num_runs[counter_1][0] * CLOCKS_PER_SEC);
            }
            
            for (int counter_2 = 0; counter_2 < e.k[0]; ++counter_2)
            {
                e_d.m_vertices[counter_1].second[counter_2] = e_d.m_vertices[counter_1].second[counter_2] / (double)(e_d.num_runs[counter_1][0]);
                e_d.m_edges[counter_1].second[counter_2] = e_d.m_edges[counter_1].second[counter_2] / (double)(e_d.num_runs[counter_1][0]);
                e_d.m_polys[counter_1].second[counter_2] = e_d.m_polys[counter_1].second[counter_2] / (double)(e_d.num_runs[counter_1][0]);
                e_d.m_perim[counter_1].second[counter_2] = e_d.m_perim[counter_1].second[counter_2] / (double)(e_d.num_runs[counter_1][0]);
            }
        }
    }
    
    if (!f_p.replot && f_p.extract_experiment_data) Write_Experiment_Data( f_p, e_d );
    
    if (f_p.plot_experiments) Plot_Experiments( f_p );
    
    Print_Info( start_code_runtime, start_absolute_time );
    
    return 0;
}
