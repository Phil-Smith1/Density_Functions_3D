#include "Framework_Parameters.h"
#include "Input.h"
#include "Frac_To_Cart_Coords.h"

#include <fstream>

void Initialise_Pt_Cloud_T2L ( Framework_Parameters const& f_p, Input& input, int index )
{
    input.base_pts.clear();
    
    string filename = "job_0" + input.T2L_label + ".csv";
    string file_path = f_p.T2L_dir + filename;
    
    ifstream ifs( file_path );
    
    string line_data;
    
    getline( ifs, line_data );
    
    string a, b, c;
    stringstream stream;
    
    stream << line_data;
    
    getline( stream, a, ',' );
    getline( stream, b, ',' );
    getline( stream, c, ',' );
    
    input.matrix[0][0] = stod( a );
    input.matrix[1][0] = stod( b );
    input.matrix[2][0] = stod( c );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, a, ',' );
    getline( stream, b, ',' );
    getline( stream, c, ',' );
    
    input.matrix[0][1] = stod( a );
    input.matrix[1][1] = stod( b );
    input.matrix[2][1] = stod( c );
    
    getline( ifs, line_data );
    
    stream.clear();
    stream << line_data;
    
    getline( stream, a, ',' );
    getline( stream, b, ',' );
    getline( stream, c, ',' );
    
    input.matrix[0][2] = stod( a );
    input.matrix[1][2] = stod( b );
    input.matrix[2][2] = stod( c );
    
    getline( ifs, line_data );
    getline( ifs, line_data );
    getline( ifs, line_data );
    
    vector<pair<P3, pair<string, int>>> molecules;
    
    while(getline( ifs, line_data ))
    {
        P3 p;
        string index, atom_type, x, y, z, molecule_index;
        
        stream.clear();
        stream << line_data;
        
        getline( stream, index, ',' );
        getline( stream, atom_type, ',' );
        getline( stream, x, ',' );
        getline( stream, y, ',' );
        getline( stream, z, ',' );
        getline( stream, molecule_index, ',' );
        
        p = P3( stod( x ), stod( y ), stod( z ) );
        
        Frac_To_Cart_Coords( input.matrix, p );
        
        molecules.push_back( pair<P3, pair<string, int>>( p, pair<string, int>( atom_type, stoi( molecule_index ) ) ) );
    }
    
    ifs.close();
    
    int num_molecules = (int)molecules.size() / 46;
    
    for (int counter_1 = 0; counter_1 < num_molecules; ++counter_1)
    {
        P3 p = P3( 0, 0, 0 );
        
        for (int counter_2 = 0; counter_2 < molecules.size(); ++counter_2)
        {
            if (molecules[counter_2].second.second == counter_1)
            {
                p = P3( p.x() + molecules[counter_2].first.x(), p.y() + molecules[counter_2].first.y(), p.z() + molecules[counter_2].first.z() );
            }
        }
        
        p = P3( p.x() / (double)46, p.y() / (double)46, p.z() / (double)46 );
        
        if (f_p.type_of_experiment == "Molecule_Centres" || f_p.type_of_experiment == "Centres_Plus_Ox") input.base_pts.push_back( p );
    }
    
    if (f_p.type_of_experiment == "Centres_Plus_Ox")
    {
        for (int counter = 0; counter < molecules.size(); ++counter)
        {
            if (molecules[counter].second.first == "O") input.base_pts.push_back( molecules[counter].first );
        }
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
