#pragma once

#include "B_Poly.h"

#include <fstream>

using namespace std;

typedef K::Point_3 P3;
typedef Polyhedron::Vertex_iterator vertex_iterator;
typedef Polyhedron::Halfedge_iterator halfedge_iterator;
typedef Polyhedron::Face_iterator face_iterator;
typedef Polyhedron::Facet::Halfedge_around_facet_circulator face_he_circulator;

void Write_Poly_VTK_File ( vector<B_Poly>const& polys );
