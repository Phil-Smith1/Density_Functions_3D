#include "Sphere.h"

#include <CGAL/Triangulation_3.h>

using namespace std;
using namespace CGAL;

typedef Tetrahedron_3<K> Tetrahedron;
typedef K::Plane_3 Pl3;

void Extract_Tetra_Cell ( Sphere const& s, Tetrahedron const& tetra, vector<Pl3>& tetra_cell )
{
    vector<P3> vertices;
    
    vertices.push_back( tetra.vertex( 0 ) );
    vertices.push_back( tetra.vertex( 1 ) );
    vertices.push_back( tetra.vertex( 2 ) );
    vertices.push_back( tetra.vertex( 3 ) );
            
    double precision = 1e12;
    
    long double x = (long long int)(vertices[0].x() * precision + 0.5);
    long double y = (long long int)(vertices[0].y() * precision + 0.5);
    long double z = (long long int)(vertices[0].z() * precision + 0.5);
    
    x = x / (long double)precision;
    y = y / (long double)precision;
    z = z / (long double)precision;
    
    vertices[0] = P3( x, y, z );
    
    x = (long long int)(vertices[1].x() * precision + 0.5);
    y = (long long int)(vertices[1].y() * precision + 0.5);
    z = (long long int)(vertices[1].z() * precision + 0.5);
    
    x = x / (long double)precision;
    y = y / (long double)precision;
    z = z / (long double)precision;
    
    vertices[1] = P3( x, y, z );
    
    x = (long long int)(vertices[2].x() * precision + 0.5);
    y = (long long int)(vertices[2].y() * precision + 0.5);
    z = (long long int)(vertices[2].z() * precision + 0.5);
    
    x = x / (long double)precision;
    y = y / (long double)precision;
    z = z / (long double)precision;
    
    vertices[2] = P3( x, y, z );
    
    x = (long long int)(vertices[3].x() * precision + 0.5);
    y = (long long int)(vertices[3].y() * precision + 0.5);
    z = (long long int)(vertices[3].z() * precision + 0.5);
    
    x = x / (long double)precision;
    y = y / (long double)precision;
    z = z / (long double)precision;
    
    vertices[3] = P3( x, y, z );
    
    tetra_cell.push_back( Pl3( vertices[0], vertices[1], vertices[2] ) );
    tetra_cell.push_back( Pl3( vertices[0], vertices[1], vertices[3] ) );
    tetra_cell.push_back( Pl3( vertices[0], vertices[2], vertices[3] ) );
    tetra_cell.push_back( Pl3( vertices[1], vertices[2], vertices[3] ) );
    
    long double a = (long long int)(tetra_cell[0].a() * precision + 0.5);
    long double b = (long long int)(tetra_cell[0].b() * precision + 0.5);
    long double c = (long long int)(tetra_cell[0].c() * precision + 0.5);
    long double d = (long long int)(tetra_cell[0].d() * precision + 0.5);
    
    a = a / (long double)precision;
    b = b / (long double)precision;
    c = c / (long double)precision;
    d = d / (long double)precision;
    
    tetra_cell[0] = Pl3( a, b, c, d );
    
    a = (long long int)(tetra_cell[1].a() * precision + 0.5);
    b = (long long int)(tetra_cell[1].b() * precision + 0.5);
    c = (long long int)(tetra_cell[1].c() * precision + 0.5);
    d = (long long int)(tetra_cell[1].d() * precision + 0.5);
    
    a = a / (long double)precision;
    b = b / (long double)precision;
    c = c / (long double)precision;
    d = d / (long double)precision;
    
    tetra_cell[1] = Pl3( a, b, c, d );
    
    a = (long long int)(tetra_cell[2].a() * precision + 0.5);
    b = (long long int)(tetra_cell[2].b() * precision + 0.5);
    c = (long long int)(tetra_cell[2].c() * precision + 0.5);
    d = (long long int)(tetra_cell[2].d() * precision + 0.5);
    
    a = a / (long double)precision;
    b = b / (long double)precision;
    c = c / (long double)precision;
    d = d / (long double)precision;
    
    tetra_cell[2] = Pl3( a, b, c, d );
    
    a = (long long int)(tetra_cell[3].a() * precision + 0.5);
    b = (long long int)(tetra_cell[3].b() * precision + 0.5);
    c = (long long int)(tetra_cell[3].c() * precision + 0.5);
    d = (long long int)(tetra_cell[3].d() * precision + 0.5);
    
    a = a / (long double)precision;
    b = b / (long double)precision;
    c = c / (long double)precision;
    d = d / (long double)precision;
    
    tetra_cell[3] = Pl3( a, b, c, d );
    
    if (tetra_cell[0].oriented_side( vertices[3] ) == ON_NEGATIVE_SIDE) tetra_cell[0] = tetra_cell[0].opposite();
    if (tetra_cell[1].oriented_side( vertices[2] ) == ON_NEGATIVE_SIDE) tetra_cell[1] = tetra_cell[1].opposite();
    if (tetra_cell[2].oriented_side( vertices[1] ) == ON_NEGATIVE_SIDE) tetra_cell[2] = tetra_cell[2].opposite();
    if (tetra_cell[3].oriented_side( vertices[0] ) == ON_NEGATIVE_SIDE) tetra_cell[3] = tetra_cell[3].opposite();
}

