#include "Framework_Parameters.h"
#include "Input.h"

void Graph_Title ( Framework_Parameters const& f_p, Input const& input, int index, string& title_str )
{
    if (f_p.T2)
    {
        if (f_p.experimental_T2)
        {
            if (f_p.superimposed)
            {
                if (f_p.experimental_T2_label == "a") title_str = "Density Functions for T2-{/Symbol a} and Entry 99";
                if (f_p.experimental_T2_label == "b") title_str = "Density Functions for T2-{/Symbol b} and Entry 28";
                if (f_p.experimental_T2_label == "b2") title_str = "Density Functions for T2-{/Symbol b}'' and Entry 9";
                if (f_p.experimental_T2_label == "c") title_str = "Density Functions for T2-{/Symbol g} and Entry 62";
                if (f_p.experimental_T2_label == "d") title_str = "Density Functions for T2-{/Symbol d} and Entry 9";
                if (f_p.experimental_T2_label == "e") title_str = "Density Functions for T2-{/Symbol e} and Entry 1";
            }
            
            else
            {
                if (f_p.experimental_T2_label == "a") title_str = "Density Functions for T2-{/Symbol a}";
                if (f_p.experimental_T2_label == "b") title_str = "Density Functions for T2-{/Symbol b}";
                if (f_p.experimental_T2_label == "b2") title_str = "Density Functions for T2-{/Symbol b}''";
                if (f_p.experimental_T2_label == "c") title_str = "Density Functions for T2-{/Symbol g}";
                if (f_p.experimental_T2_label == "d") title_str = "Density Functions for T2-{/Symbol d}";
                if (f_p.experimental_T2_label == "e") title_str = "Density Functions for T2-{/Symbol e}";
            }
        }
        
        else
        {
            title_str = "Density Functions for T2 Entry " + to_string( index );
        }
    }
    
    else if (input.FCC)
    {
        if (f_p.superimposed) title_str = "Density Functions for FCC and HCP";
        
        else title_str = "Density Functions for FCC";
    }
    
    else if (input.HCP) title_str = "Density Functions for HCP";
    
    else if (input.homometric) title_str = "Density Functions for u = " + to_string( input.u );
    
    else title_str = f_p.title_str;
}
