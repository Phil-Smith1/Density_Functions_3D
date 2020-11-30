#pragma once

#include "Input.h"
#include "B_Poly.h"
#include "Experiment_Data.h"

typedef Polyhedron::Edge_iterator edge_iterator;
typedef Polyhedron::Facet_iterator facet_iterator;

void Compute_Experiment_Data ( Input const& input, vector<B_Poly>& polys, Experiment_Data& e_d );
