#include "Initialise_Pt_Cloud.h"
#include "Add_Random_Pts.h"
#include "Brillouin_Algorithm.h"
#include "Plot_Graph.h"

void Threads ( Framework_Parameters const f_p, Input input, int rep_iter, Experiment_Data e_d )
{
    Add_Random_Pts( input ); // Adding input.random_pts number of random points.
    
    Initialise_Pt_Cloud( f_p, input, rep_iter, f_p.uplusv ); // Producing the vector of base points in Cartesian coordinates.
    
    if (!f_p.replot) Brillouin_Algorithm( f_p, input, e_d ); // Main computations occur here.
    
    if (f_p.plot_graph) Plot_Graph( f_p, input ); // Plotting the graph.
}
