#include "Framework_Parameters.h"
#include "Input.h"
#include "Frac_To_Cart_Coords.h"

#include <fstream>

void Initialise_Pt_Cloud_T2L ( Framework_Parameters const& f_p, Input& input, int index )
{
    input.base_pts.clear();
    
    string filename = "T2_" + to_string( index ) + ".txt";
    string file_path = f_p.T2L_dir + filename;
    
    ifstream ifs( file_path );
    
    string line_data;
    
    getline( ifs, line_data );
    
    double a, b, c;
    stringstream stream;
    
    stream << line_data;
    
    stream >> a >> b >> c;
    
    input.matrix[0][0] = a;
    input.matrix[1][0] = b;
    input.matrix[2][0] = c;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    stream >> a >> b >> c;
    
    input.matrix[0][1] = a;
    input.matrix[1][1] = b;
    input.matrix[2][1] = c;
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    stream >> a >> b >> c;
    
    input.matrix[0][2] = a;
    input.matrix[1][2] = b;
    input.matrix[2][2] = c;
    
    getline( ifs, line_data );
    getline( ifs, line_data );
    getline( ifs, line_data );
    
    vector<pair<P3, int>> molecules;
    
    while(getline( ifs, line_data ))
    {
        int molecule_index;
        double d;
        P3 p;
        string atom_type;
        
        stream.clear();
        stream << line_data;
        
        stream >> a >> atom_type >> b >> c >> d >> molecule_index;
        
        p = P3( b, c, d );
        
        Frac_To_Cart_Coords( input.matrix, p );
        
        molecules.push_back( pair<P3, int>( p, molecule_index ) );
    }
    
    ifs.close();
    
    int num_molecules = (int)molecules.size() / 46;
    
    for (int counter_1 = 0; counter_1 < num_molecules; ++counter_1)
    {
        P3 p = P3( 0, 0, 0 );
        
        for (int counter_2 = 0; counter_2 < molecules.size(); ++counter_2)
        {
            if (molecules[counter_2].second == counter_1)
            {
                p = P3( p.x() + molecules[counter_2].first.x(), p.y() + molecules[counter_2].first.y(), p.z() + molecules[counter_2].first.z() );
            }
        }
        
        p = P3( p.x() / (double)46, p.y() / (double)46, p.z() / (double)46 );
        
        input.base_pts.push_back( p );
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
