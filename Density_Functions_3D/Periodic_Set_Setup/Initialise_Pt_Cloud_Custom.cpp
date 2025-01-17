#include "Input.h"
#include "Frac_To_Cart_Coords.h"

void Initialise_Pt_Cloud_Custom ( Input& input, bool uplusv )
{
    input.base_pts.clear();
    
    if (uplusv)
    {
        for (int counter_1 = 0; counter_1 < input.frac_base_pts.size(); ++counter_1)
        {
            for (int counter_2 = 0; counter_2 < input.frac_V.size(); ++counter_2)
            {
                double x, y, z;
                
                if (input.rep_iter % 2 == 0)
                {
                    x = to_double( input.frac_base_pts[counter_1].x() + input.frac_V[counter_2].x() );
                    y = to_double( input.frac_base_pts[counter_1].y() + input.frac_V[counter_2].y() );
                    z = to_double( input.frac_base_pts[counter_1].z() + input.frac_V[counter_2].z() );
                }
                
                else
                {
                    x = to_double( input.frac_base_pts[counter_1].x() - input.frac_V[counter_2].x() );
                    y = to_double( input.frac_base_pts[counter_1].y() - input.frac_V[counter_2].y() );
                    z = to_double( input.frac_base_pts[counter_1].z() - input.frac_V[counter_2].z() );
                }
                
                x = x - (long)x;
                y = y - (long)y;
                z = z - (long)z;
                
                if (x < 0) x += 1;
                if (y < 0) y += 1;
                if (z < 0) z += 1;
                
                input.base_pts.push_back( P3( x, y, z ) );
            }
        }
    }
    
    else
    {
        for (int counter = 0; counter < input.frac_base_pts.size(); ++counter)
        {
            input.base_pts.push_back( input.frac_base_pts[counter] );
        }
        
        for (int counter = 0; counter < input.frac_random_pts.size(); ++counter)
        {
            input.base_pts.push_back( input.frac_random_pts[counter] );
        }
    }
    
    for (int counter = 0; counter < input.base_pts.size(); ++counter)
    {
        Frac_To_Cart_Coords( input.matrix, input.base_pts[counter] );
    }
}
