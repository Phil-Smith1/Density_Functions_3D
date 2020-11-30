#pragma once

#include <string>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

using namespace std;
using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_3 P3;

class Input
{
    public:
    
    bool homometric, FCC, HCP;
    int zone_limit, perim, random_pts, num_input, num_v, motif_iter, k_iter, rep_iter;
    double cell_param_a, cell_param_b, cell_param_c, cell_param_alpha, cell_param_beta, cell_param_gamma, u, max_radius;
    double ** matrix;
    string data_file, graph_file;
    vector<P3> frac_base_pts, frac_random_pts, lattice_vectors, frac_V, base_pts;
    
    Input();
    ~Input();
};
