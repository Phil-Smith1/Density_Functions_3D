#include <string>
#include <vector>

using namespace std;

void Assign_Experimental_Cell_Shape ( string const& label, vector<pair<string, double>>& cell_shape )
{
    cell_shape.reserve( 6 );
    
    if (label == "a")
    {
        cell_shape.push_back( pair<string, double>( "_cell_length_a", 22.5124 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_b", 22.5124 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_c", 7.3367 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_alpha", 90 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_beta", 90 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_gamma", 90 ) );
    }
    
    else if (label == "b")
    {
        cell_shape.push_back( pair<string, double>( "_cell_length_a", 7.246 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_b", 13.0328 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_c", 20.66 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_alpha", 72.464 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_beta", 86.349 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_gamma", 74.035 ) );
    }
    
    else if (label == "b2")
    {
        cell_shape.push_back( pair<string, double>( "_cell_length_a", 7.2523 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_b", 13.033 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_c", 20.693 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_alpha", 72.701 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_beta", 86.552 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_gamma", 73.915 ) );
    }
    
    else if (label == "c")
    {
        cell_shape.push_back( pair<string, double>( "_cell_length_a", 23.2209 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_b", 23.2209 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_c", 7.2864 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_alpha", 90 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_beta", 90 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_gamma", 120 ) );
    }
    
    else if (label == "d")
    {
        cell_shape.push_back( pair<string, double>( "_cell_length_a", 24.316 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_b", 7.284 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_c", 14.9 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_alpha", 90 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_beta", 119.038 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_gamma", 90 ) );
    }
    
    else if (label == "e")
    {
        cell_shape.push_back( pair<string, double>( "_cell_length_a", 12.6079 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_b", 12.6079 ) );
        cell_shape.push_back( pair<string, double>( "_cell_length_c", 7.4937 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_alpha", 90 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_beta", 90 ) );
        cell_shape.push_back( pair<string, double>( "_cell_angle_gamma", 120 ) );
    }
}
