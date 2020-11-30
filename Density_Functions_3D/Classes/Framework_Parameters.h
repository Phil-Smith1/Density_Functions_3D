#pragma once

#include <string>

using namespace std;

class Framework_Parameters
{
    public:
    
    bool replot, extract_data, densigram, plot_graph, zero_density, title, extract_experiment_data, plot_experiments, time_vary_k, time_vary_m, vary_k, vary_m, uplusv, superimposed, use_threads, T2, experimental_T2;
    int sample_rate, T2_start_index;
    string input_dir, output_dir, T2_dir, input_file, experiment_file, v_file, title_str, type_of_experiment, experimental_T2_label;
    
    Framework_Parameters();
    ~Framework_Parameters();
};
