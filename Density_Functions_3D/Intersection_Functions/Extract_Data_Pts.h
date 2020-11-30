#pragma once

#include "Framework_Parameters.h"
#include "Data_Pts_For_Given_Radius.h"

#include <fstream>
#include <thread>

void Extract_Data_Pts ( Framework_Parameters const& f_p, Input& input, P3 const& base_pt, vector<double>const& max_radii, vector<vector<Tetrahedron>> tetras, vector<vector<double>>& results );
