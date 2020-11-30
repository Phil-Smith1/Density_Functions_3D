#pragma once

#include "Sphere.h"

#include <CGAL/Triangulation_3.h>

using namespace std;
using namespace CGAL;

typedef Tetrahedron_3<K> Tetrahedron;
typedef K::Plane_3 Pl3;

void Extract_Tetra_Cell ( Sphere const& s, Tetrahedron const& tetra, vector<Pl3>& tetra_cell );
