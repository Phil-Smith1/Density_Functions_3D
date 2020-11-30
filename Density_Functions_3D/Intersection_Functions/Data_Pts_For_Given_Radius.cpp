#include "Input.h"
#include "Sphere_Tetrahedron_Intersection.h"

void Data_Pts_For_Given_Radius ( Input const input, int sample, P3 const& base_pt, vector<vector<Tetrahedron>>const& tetras, vector<double>const& max_radii, vector<double>& results )
{
    double radius = results[0];
    
    Sphere s( base_pt, radius );
        
    for (int counter_1 = 0; counter_1 < input.zone_limit; ++counter_1)
    {
        if (max_radii[counter_1] < radius + tiny_num)
        {
            for (int counter_2 = 0; counter_2 < tetras[counter_1].size(); ++counter_2)
            {
                results[counter_1 + 1] += tetras[counter_1][counter_2].volume();
            }
        }
        
        else
        {
            for (int counter_2 = 0; counter_2 < tetras[counter_1].size(); ++counter_2)
            {
                results[counter_1 + 1] += Sphere_Tetrahedron_Intersection( s, tetras[counter_1][counter_2] );
            }
        }
    }
}
