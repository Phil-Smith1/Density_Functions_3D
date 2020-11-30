#pragma once

#include "Input.h"
#include "Sphere_Tetrahedron_Intersection.h"

void Data_Pts_For_Given_Radius ( Input const input, int sample, P3 const& base_pt, vector<vector<Tetrahedron>>const& tetras, vector<double>const& max_radii, vector<double>& results );
