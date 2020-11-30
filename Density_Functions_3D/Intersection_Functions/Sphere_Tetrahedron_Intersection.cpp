#include "General_Spherical_Cone.h"
#include "Extract_Tetra_Cell.h"

double Sphere_Tetrahedron_Intersection ( Sphere const& s, Tetrahedron const& t )
{
    double tetra_volume = t.volume();
    
    if (tetra_volume < tiny_num * 1e4) return 0;
    
    vector<Pl3> tetra;
    
    Extract_Tetra_Cell( s, t, tetra );
    
    double plane_dist_1 = sqrt( squared_distance( s.c, tetra[0] ) );
    
    if (plane_dist_1 > s.r - tiny_num)
    {
        if (tetra[0].oriented_side( s.c ) == ON_NEGATIVE_SIDE) return 0;
        
        else return General_Spherical_Cone( s, tetra[1], tetra[2], tetra[3] );
    }
    
    double plane_dist_2 = sqrt( squared_distance( s.c, tetra[1] ) );
    
    if (plane_dist_2 > s.r - tiny_num)
    {
        if (tetra[1].oriented_side( s.c ) == ON_NEGATIVE_SIDE) return 0;
        
        else return General_Spherical_Cone( s, tetra[0], tetra[2], tetra[3] );
    }
    
    double plane_dist_3 = sqrt( squared_distance( s.c, tetra[2] ) );
    
    if (plane_dist_3 > s.r - tiny_num)
    {
        if (tetra[2].oriented_side( s.c ) == ON_NEGATIVE_SIDE) return 0;
        
        else return General_Spherical_Cone( s, tetra[0], tetra[1], tetra[3] );
    }
    
    double plane_dist_4 = sqrt( squared_distance( s.c, tetra[3] ) );
    
    if (plane_dist_4 > s.r - tiny_num)
    {
        if (tetra[3].oriented_side( s.c ) == ON_NEGATIVE_SIDE) return 0;
        
        else return General_Spherical_Cone( s, tetra[0], tetra[1], tetra[2] );
    }
    
    double volume1 = General_Spherical_Cone( s, tetra[0], tetra[1], tetra[2] );
    
    if (volume1 < tiny_num) return 0;
    
    double volume = volume1 - Spherical_Cap( s, tetra[3].opposite() ) + General_Spherical_Wedge( s, tetra[0].opposite(), tetra[3].opposite() ) + General_Spherical_Wedge( s, tetra[1].opposite(), tetra[3].opposite() ) + General_Spherical_Wedge( s, tetra[2].opposite(), tetra[3].opposite() ) - General_Spherical_Cone( s, tetra[0].opposite(), tetra[1].opposite(), tetra[3].opposite() ) - General_Spherical_Cone( s, tetra[0].opposite(), tetra[2].opposite(), tetra[3].opposite() ) - General_Spherical_Cone( s, tetra[1].opposite(), tetra[2].opposite(), tetra[3].opposite() );
    
    return volume;
}
