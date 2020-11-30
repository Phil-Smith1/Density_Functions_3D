#pragma once

#include <gemmi/cif.hpp>

#include <string>

using namespace std;
namespace cif = gemmi::cif;

void Read_Cell_Shape ( cif::Block * block, vector<pair<string, double>>& cell_shape );
