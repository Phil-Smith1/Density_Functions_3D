#include "Frac_To_Cart_Coords.h"

#include <string>
#include <vector>

using namespace std;

void Assign_Experimental_Pts ( string const& label, string const& type_of_experiment, double ** matrix, vector<P3>& pts )
{
    vector<P3> centres;
    vector<P3> oxygens;
    
    if (label == "a")
    {
        P3 p = P3( 0.764, 0.187, 0 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.187, 0.236, 0.5 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.813, 0.764, 0.5 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.236, 0.813, 0 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.13795, 0.51044, 0 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.54737, 0.86013, 0 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.03413, 1.06044, 0 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.86205, 0.48956, 0 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.45263, 0.13987, 0 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.96587, -0.06044, 0 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.48956, 0.13795, 0.5 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.13987, 0.54737, 0.5 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( -0.06044, 0.03413, 0.5 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.51044, 0.86205, 0.5 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.86013, 0.45263, 0.5 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 1.06044, 0.96587, 0.5 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
    }
    
    else if (label == "b")
    {
        P3 p = P3( 0.736, 0.663, 0.172 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.264, 0.337, 0.828 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.99574, 0.19939, 0.03063 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.46451, 1.26401, 0.03389 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.75010, 0.48915, 0.52199 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.00426, 0.80061, 0.96937 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.53549, -0.26401, 0.96611 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.24990, 0.51085, 0.47801 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
    }
    
    else if (label == "b2")
    {
        P3 p = P3( 0.769, 0.338, 0.328 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.231, 0.662, 0.672 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
    }
    
    else if (label == "c")
    {
        P3 p = P3( 0.333, 0.667, 0.75 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.667, 0.333, 0.25 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.51096, 0.48904, 0.75 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.51096, 1.02192, 0.75 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( -0.02192, 0.48904, 0.75 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.48904, 0.51096, 0.25 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.48904, -0.02192, 0.25 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 1.02192, 0.51096, 0.25 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
    }
    
    else if (label == "d")
    {
        P3 p = P3( 0.744, 0, 0.255 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.756, 0.5, 0.745 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.244, 0.5, 0.255 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.256, 0, 0.745 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 1.04320, -0.26340, 0.46580 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.74960, 0.51120, -0.02200 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.51280, 0.80180, 0.46930 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( -0.04320, 1.26340, 0.53420 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.25040, 0.48880, 1.02200 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
        
        p = P3( 0.48720, 0.19820, 0.53070 );
        Frac_To_Cart_Coords( matrix, p );
        oxygens.push_back( p );
    }
    
    else if (label == "e")
    {
        P3 p = P3( 0.667, 0.333, 0.75 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
        
        p = P3( 0.333, 0.667, 0.25 );
        Frac_To_Cart_Coords( matrix, p );
        centres.push_back( p );
    }
    
    if (type_of_experiment == "Molecule_Centres")
    {
        for (int counter = 0; counter < centres.size(); ++counter)
        {
            pts.push_back( centres[counter] );
        }
    }
    
    else if (type_of_experiment == "Molecule_Centres_with_Oxygens")
    {
        for (int counter = 0; counter < centres.size(); ++counter)
        {
            pts.push_back( centres[counter] );
        }
        
        for (int counter = 0; counter < oxygens.size(); ++counter)
        {
            pts.push_back( oxygens[counter] );
        }
    }
    
    else
    {
        for (int counter = 0; counter < oxygens.size(); ++counter)
        {
            pts.push_back( oxygens[counter] );
        }
    }
}
