#pragma once

#include <gemmi/cif.hpp>

#include "Framework_Parameters.h"
#include "Input.h"
#include "Read_Cell_Shape.h"
#include "Assign_Experimental_Cell_Shape.h"
#include "Transformation_Matrix.h"
#include "Assign_Experimental_Pts.h"
#include "Read_Atom_Coords.h"
#include "Obtain_Base_Pts_T2.h"

void Initialise_Pt_Cloud_T2 ( Framework_Parameters const& f_p, Input& input, int index );
