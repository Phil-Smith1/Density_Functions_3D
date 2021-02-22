#include "Framework_Parameters.h"

#include <fstream>
#include <sstream>
#include <iostream>

bool Read_Framework_Parameters ( Framework_Parameters& f_p )
{
    ifstream ifs( "/Users/philsmith/Documents/Work/Xcode Projects/Density_Functions_3D/Input/Framework_Parameters.csv" );
    
    if (!ifs.is_open())
    {
        cout << "Framework parameters file not found!" << endl;
        return false;
    }
    
    string line_data, val;
    
    getline( ifs, line_data );
    
    stringstream stream;
    
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.input_dir = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.output_dir = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.T2_dir = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.T2L_dir = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.input_file = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.experiment_file = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.v_file = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.replot = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.extract_data = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.sample_rate = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.densigram = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.plot_graph = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.zero_density = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.title = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.title_str = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.extract_experiment_data = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.plot_experiments = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.time_vary_k = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.time_vary_m = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.vary_k = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.vary_m = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.uplusv = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.superimposed = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.use_threads_1 = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.use_threads_2 = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.T2 = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.T2L = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.type_of_experiment = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.experimental_T2 = stoi( val );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.experimental_T2_label = val;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, val, ',' );
    getline( stream, val, ',' );
    
    f_p.T2_start_index = stoi( val );
    
    ifs.close();
    
    return true;
}

