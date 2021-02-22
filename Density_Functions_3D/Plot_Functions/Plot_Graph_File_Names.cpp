#include "Framework_Parameters.h"
#include "Input.h"

void Plot_Graph_File_Names ( Framework_Parameters const& f_p, Input const& input, string& data_file_1, string& data_file_2, string& graph_file )
{
    if (f_p.T2)
    {
        if (f_p.experimental_T2)
        {
            if (f_p.experimental_T2_label == "a")
            {
                data_file_1 = "Data/Experimental_T2/Alpha.txt";
                
                if (f_p.superimposed) graph_file = "Graphs/Experimental_T2/Alpha_Sup.pdf";
                else graph_file = "Graphs/Experimental_T2/Alpha.pdf";
            }
            
            if (f_p.experimental_T2_label == "b")
            {
                data_file_1 = "Data/Experimental_T2/Beta.txt";
                
                if (f_p.superimposed) graph_file = "Graphs/Experimental_T2/Beta_Sup.pdf";
                else graph_file = "Graphs/Experimental_T2/Beta.pdf";
            }
            
            if (f_p.experimental_T2_label == "b2")
            {
                data_file_1 = "Data/Experimental_T2/Beta2.txt";
                
                if (f_p.superimposed) graph_file = "Graphs/Experimental_T2/Beta2_Sup.pdf";
                else graph_file = "Graphs/Experimental_T2/Beta2.pdf";
            }
            
            if (f_p.experimental_T2_label == "c")
            {
                data_file_1 = "Data/Experimental_T2/Gamma.txt";
                
                if (f_p.superimposed) graph_file = "Graphs/Experimental_T2/Gamma_Sup.pdf";
                else graph_file = "Graphs/Experimental_T2/Gamma.pdf";
            }
            
            if (f_p.experimental_T2_label == "d")
            {
                data_file_1 = "Data/Experimental_T2/Delta.txt";
                
                if (f_p.superimposed) graph_file = "Graphs/Experimental_T2/Delta_Sup.pdf";
                else graph_file = "Graphs/Experimental_T2/Delta.pdf";
            }
            
            if (f_p.experimental_T2_label == "e")
            {
                data_file_1 = "Data/Experimental_T2/Epsilon.txt";
                
                if (f_p.superimposed) graph_file = "Graphs/Experimental_T2/Epsilon_Sup.pdf";
                else graph_file = "Graphs/Experimental_T2/Epsilon.pdf";
            }
        }
        
        else
        {
            data_file_1 = "Data/T2/" + to_string( input.rep_iter ) + ".txt";
            graph_file = "Graphs/T2/" + to_string( input.rep_iter ) + ".pdf";
        }
    }
    
    else if (f_p.T2L)
    {
        if (f_p.type_of_experiment == "Molecule_Centres")
        {
            data_file_1 = f_p.output_dir + "Data/T2L/T2L_Centres_0" + input.T2L_label + ".csv";
            graph_file = "Graphs/T2L/T2L_Centres_0" + input.T2L_label + ".pdf";
        }
        
        else if (f_p.type_of_experiment == "Centres_Plus_Ox")
        {
            data_file_1 = f_p.output_dir + "Data/T2L_CO/T2L_CO_0" + input.T2L_label + ".csv";
            graph_file = "Graphs/T2L_CO/T2L_CO_0" + input.T2L_label + ".pdf";
        }
    }
    
    else if (input.FCC)
    {
        data_file_1 = "Data/Custom/FCC.txt";
        graph_file = "Graphs/Custom/FCC.pdf";
    }
    
    else if (input.HCP)
    {
        data_file_1 = "Data/Custom/HCP.txt";
        graph_file = "Graphs/Custom/HCP.pdf";
    }
    
    else if (input.homometric)
    {
        data_file_1 = "Data/Custom/Homometric/Density Functions/0.3.txt";
        graph_file = "Graphs/Custom/Homometric/Density Functions/Superimposed/0.3.pdf";
        
        if (f_p.superimposed) data_file_2 = "Data/Custom/Homometric/Density Functions/-0.3.txt";
    }
    
    else
    {
        data_file_1 = "Data/Custom.txt";
        graph_file = "Graphs/Custom.pdf";
    }
    
    if (f_p.superimposed)
    {
        if (f_p.T2)
        {
            if (f_p.experimental_T2)
            {
                if (f_p.experimental_T2_label == "a") data_file_2 = "Data/T2/99.txt";
                if (f_p.experimental_T2_label == "b") data_file_2 = "Data/T2/28.txt";
                if (f_p.experimental_T2_label == "b2") data_file_2 = "Data/T2/9.txt";
                if (f_p.experimental_T2_label == "c") data_file_2 = "Data/T2/62.txt";
                if (f_p.experimental_T2_label == "d") data_file_2 = "Data/T2/9.txt";
                if (f_p.experimental_T2_label == "e") data_file_2 = "Data/T2/1.txt";
            }
        }
        
        if (input.FCC)
        {
            data_file_2 = "Data/Custom/HCP.txt";
            graph_file = "Graphs/Custom/FCCHCP.pdf";
        }
    }
}
