// https://www.physics-in-a-nutshell.com/article/11/close-packed-structures-fcc-and-hcp#the-hcp-structure
// http://lampx.tugraz.at/~hadley/ss1/crystalstructure/structures/hcp/hcp.php

#include "Input.h"

void Initialise_Parameters ( Input& input )
{
    if (input.homometric)
    {
        input.cell_param_a = 100;
        input.cell_param_b = 100;
        input.cell_param_c = 100;
        input.cell_param_alpha = 90;
        input.cell_param_beta = 90;
        input.cell_param_gamma = 90;
        
        input.frac_base_pts.push_back( P3( input.u, 0, 0.25 ) );
        input.frac_base_pts.push_back( P3( -input.u, 0.5, 0.25 ) );
        input.frac_base_pts.push_back( P3( 0.5 - input.u, 0, 0.75 ) );
        input.frac_base_pts.push_back( P3( input.u + 0.5, 0.5, 0.75 ) );
        input.frac_base_pts.push_back( P3( 0.25, input.u, 0 ) );
        input.frac_base_pts.push_back( P3( 0.25, -input.u, 0.5 ) );
        input.frac_base_pts.push_back( P3( 0.75, 0.5 - input.u, 0 ) );
        input.frac_base_pts.push_back( P3( 0.75, input.u + 0.5, 0.5 ) );
        input.frac_base_pts.push_back( P3( 0, 0.25, input.u ) );
        input.frac_base_pts.push_back( P3( 0.5, 0.25, -input.u ) );
        input.frac_base_pts.push_back( P3( 0, 0.75, 0.5 - input.u ) );
        input.frac_base_pts.push_back( P3( 0.5, 0.75, input.u + 0.5 ) );
        input.frac_base_pts.push_back( P3( -input.u, 0, 0.75 ) );
        input.frac_base_pts.push_back( P3( input.u, 0.5, 0.75 ) );
        input.frac_base_pts.push_back( P3( input.u + 0.5, 0, 0.25 ) );
        input.frac_base_pts.push_back( P3( 0.5 - input.u, 0.5, 0.25 ) );
        input.frac_base_pts.push_back( P3( 0.75, -input.u, 0 ) );
        input.frac_base_pts.push_back( P3( 0.75, input.u, 0.5 ) );
        input.frac_base_pts.push_back( P3( 0.25, input.u + 0.5, 0 ) );
        input.frac_base_pts.push_back( P3( 0.25, 0.5 - input.u, 0.5 ) );
        input.frac_base_pts.push_back( P3( 0, 0.75, -input.u ) );
        input.frac_base_pts.push_back( P3( 0.5, 0.75, input.u ) );
        input.frac_base_pts.push_back( P3( 0, 0.25, input.u + 0.5 ) );
        input.frac_base_pts.push_back( P3( 0.5, 0.25, 0.5 - input.u ) );
    }
    
    else if (input.FCC)
    {
        /*input.cell_param_a = 10;
        input.cell_param_b = 10;
        input.cell_param_c = 10;
        input.cell_param_alpha = 60;
        input.cell_param_beta = 60;
        input.cell_param_gamma = 60;*/
        
        //BCC
        
        input.cell_param_a = 10;
        input.cell_param_b = 10;
        input.cell_param_c = 10;
        input.cell_param_alpha = 70.52877937;
        input.cell_param_beta = 70.52877937;
        input.cell_param_gamma = 70.52877937;
        
        input.frac_base_pts.push_back( P3( 0, 0, 0 ) );
    }
    
    else if (input.HCP)
    {
        input.cell_param_a = 1;
        input.cell_param_b = 1;
        input.cell_param_c = 2 * sqrt( (double)6 ) / (double)3;
        input.cell_param_alpha = 90;
        input.cell_param_beta = 90;
        input.cell_param_gamma = 120;
        
        input.frac_base_pts.push_back( P3( 0, 0, 0 ) );
        input.frac_base_pts.push_back( P3( 2 / (double)3, 1 / (double)3, 0.5 ) );
    }
    
    else input.frac_base_pts.push_back( P3( 0, 0, 0 ) );
}
