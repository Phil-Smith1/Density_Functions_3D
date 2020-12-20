#include "Framework_Parameters.h"
#include "Input.h"

void Data_File_Name ( Framework_Parameters const& f_p, Input const& input, int index, string& data_file )
{
    if (f_p.T2)
    {
        if (!f_p.experimental_T2)
        {
            data_file = f_p.output_dir + "Data/T2/" + to_string( index ) + ".txt";
        }
        
        else
        {
            if (f_p.experimental_T2_label == "a")
            {
                data_file = f_p.output_dir + "Data/Experimental_T2/Alpha.txt";
            }
            
            if (f_p.experimental_T2_label == "b")
            {
                data_file = f_p.output_dir + "Data/Experimental_T2/Beta.txt";
            }
            
            if (f_p.experimental_T2_label == "b2")
            {
                data_file = f_p.output_dir + "Data/Experimental_T2/Beta2.txt";
            }
            
            if (f_p.experimental_T2_label == "c")
            {
                data_file = f_p.output_dir + "Data/Experimental_T2/Gamma.txt";
            }
            
            if (f_p.experimental_T2_label == "d")
            {
                data_file = f_p.output_dir + "Data/Experimental_T2/Delta.txt";
            }
            
            if (f_p.experimental_T2_label == "e")
            {
                data_file = f_p.output_dir + "Data/Experimental_T2/Epsilon.txt";
            }
        }
    }
    
    else if (f_p.T2L)
    {
        data_file = f_p.output_dir + "Data/T2L/T2L_Centres_0" + input.T2L_label + ".csv";
    }
    
    else if (input.FCC) data_file = f_p.output_dir + "Data/Custom/FCC.txt";
    
    else if (input.HCP) data_file = f_p.output_dir + "Data/Custom/HCP.txt";
    
    else if (input.homometric) data_file = f_p.output_dir + "Data/Custom/Homometric/Homometric.txt";
    
    else data_file = f_p.output_dir + "Data/Custom.txt";
}
