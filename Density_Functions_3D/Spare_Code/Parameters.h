#pragma once

// Things that can be controlled from here:
// Whole T2 dataset;
// Experimental T2 crystals;
// FCC and HCP;
// Patterson's homometric structure.

bool homometric = false;

double cell_param_a = 10; // Was 100.
double cell_param_b = 10; // Was 100.
double cell_param_c = 10; // Was 100.
double cell_param_alpha = 90;
double cell_param_beta = 90;
double cell_param_gamma = 90;

double u = -0.03;

bool FCC = false;

bool HCP = false;
