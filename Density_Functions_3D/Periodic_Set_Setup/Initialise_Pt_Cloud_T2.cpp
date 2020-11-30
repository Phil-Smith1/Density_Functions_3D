#include <gemmi/cif.hpp>

#include "Framework_Parameters.h"
#include "Input.h"
#include "Read_Cell_Shape.h"
#include "Assign_Experimental_Cell_Shape.h"
#include "Transformation_Matrix.h"
#include "Assign_Experimental_Pts.h"
#include "Read_Atom_Coords.h"
#include "Obtain_Base_Pts_T2.h"

void Initialise_Pt_Cloud_T2 ( Framework_Parameters const& f_p, Input& input, int index )
{
    input.base_pts.clear();
    
    string filename = "T2_" + to_string( index ) + "_num_molGeom.cif";
    string file_path = f_p.T2_dir + filename;
    
    vector<pair<string, double>> cell_shape;
    
    if (f_p.experimental_T2)
    {
        Assign_Experimental_Cell_Shape( f_p.experimental_T2_label, cell_shape );
        
        Transformation_Matrix( cell_shape, input.matrix );
        
        Assign_Experimental_Pts( f_p.experimental_T2_label, f_p.type_of_experiment, input.matrix, input.base_pts );
    }
    
    else
    {
        cif::Document cif_file = cif::read_file( file_path ); // Accessing CIF file.
        
        cif::Block * block = &(*(++cif_file.blocks.begin())); // Pointer to relevant block.
        
        Read_Cell_Shape( block, cell_shape ); // Reading cell shape.
        
        Transformation_Matrix( cell_shape, input.matrix ); // Calculating the transformation matrix.
        
        vector<P3> atom_cloud;
        
        Read_Atom_Coords( block, input.matrix, atom_cloud );
        
        Obtain_Base_Pts_T2( atom_cloud, f_p.type_of_experiment, input.base_pts );
    }
    
    P3 p1 = P3( 1, 0, 0 );
    P3 p2 = P3( 0, 1, 0 );
    P3 p3 = P3( 0, 0, 1 );
    
    Frac_To_Cart_Coords( input.matrix, p1 );
    Frac_To_Cart_Coords( input.matrix, p2 );
    Frac_To_Cart_Coords( input.matrix, p3 );
    
    input.lattice_vectors.clear();
    input.lattice_vectors.push_back( p1 );
    input.lattice_vectors.push_back( p2 );
    input.lattice_vectors.push_back( p3 );
}
