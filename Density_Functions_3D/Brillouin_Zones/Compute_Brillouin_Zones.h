#pragma once

#include "Framework_Parameters.h"
#include "Dividing_Space.h"
#include "Triangulate_Zones.h"
#include "Write_Poly_VTK_File.h"
#include "Compute_Experiment_Data.h"

void Compute_Brillouin_Zones ( Framework_Parameters const& f_p, Input const& input, P3 const& base_pt, multimap<double, P3>const cloud, vector<double>& zone_volume, vector<double>& max_radii, vector<vector<Tetrahedron>>& tetras, Experiment_Data& e_d );
