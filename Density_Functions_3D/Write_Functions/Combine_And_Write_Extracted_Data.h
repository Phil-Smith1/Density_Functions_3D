#pragma once

#include "Data_File_Name.h"

#include <fstream>

#ifndef tiny_number
#define tiny_number
const double tiny_num = 1e-10;
#endif

void Combine_And_Write_Extracted_Data ( Framework_Parameters const& f_p, Input const& input, vector<double>const& cell_volume, vector<vector<double>>& results );
