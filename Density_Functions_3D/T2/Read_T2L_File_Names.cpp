#include "Framework_Parameters.h"

#include <boost/filesystem.hpp>

void Read_T2L_File_Names ( Framework_Parameters const& f_p, vector<string>& T2L_labels )
{
    boost::filesystem::path p( f_p.T2L_dir );
    
    vector<boost::filesystem::path> full_filenames;
    
    copy( boost::filesystem::directory_iterator( p ), boost::filesystem::directory_iterator(), back_inserter( full_filenames ) );
    
    sort( full_filenames.begin(), full_filenames.end() );
    
    for (int counter = 0; counter < full_filenames.size(); ++counter)
    {
        T2L_labels.push_back( full_filenames[counter].filename().string().substr( 5, 4 ) );
    }
}
