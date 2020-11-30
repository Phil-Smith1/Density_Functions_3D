#include "Surrounding_Cloud.h"
#include "Compute_Brillouin_Zones.h"
#include "Extract_Data_Pts.h"
#include "Combine_And_Write_Extracted_Data.h"

void Brillouin_Algorithm ( Framework_Parameters const& f_p, Input& input, Experiment_Data& e_d )
{
    cout << "Computing Brillouin zones for " << input.base_pts.size() << " point(s):" << endl;

    vector<double> zone_volume( input.zone_limit, 0 ); // Records the area of the zone for each k.
    vector<vector<double>> results; // Will contains sampled values of the density functions.
    
    for (int counter = 0; counter < input.base_pts.size(); ++counter) // Looping over base points.
    {
        clock_t check_point_1 = clock(); // Starts the clock that measures the time of Brillouin zone computations.
        
        vector<double> max_radii; // Contains the maximum radius of each zone from the base point.
        vector<vector<Tetrahedron>> tetras; // Contains the Brillouin zones, stored as a vector of tetrahedrons for each zone.
        multimap<double, P3> cloud; // The cloud surrounding the base point.
        
        Surrounding_Cloud( input, counter, cloud ); // Computing the surrounding cloud.
        
        Compute_Brillouin_Zones( f_p, input, input.base_pts[counter], cloud, zone_volume, max_radii, tetras, e_d ); // Computing the Brillouin zones.
        
        clock_t check_point_2 = clock();
        
        e_d.num_runs[input.motif_iter][input.k_iter] += 1;
        e_d.m_time[input.motif_iter].second[input.k_iter].second += check_point_2 - check_point_1;
        
        if (f_p.extract_data) Extract_Data_Pts( f_p, input, input.base_pts[counter], max_radii, tetras, results ); // Computing the intersection of the base point with its Brillouin zones for varying radii.
    }

    if (f_p.extract_data) Combine_And_Write_Extracted_Data( f_p, input, zone_volume, results ); // Writing results.
}
