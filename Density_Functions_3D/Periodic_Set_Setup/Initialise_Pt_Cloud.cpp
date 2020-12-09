#include "Initialise_Pt_Cloud_T2.h"
#include "Initialise_Pt_Cloud_T2L.h"
#include "Initialise_Pt_Cloud_Custom.h"

void Initialise_Pt_Cloud ( Framework_Parameters const& f_p, Input& input, int index, bool uplusv )
{
    if (f_p.T2) Initialise_Pt_Cloud_T2( f_p, input, index );
    
    else if (f_p.T2L) Initialise_Pt_Cloud_T2L( f_p, input, index );
    
    else Initialise_Pt_Cloud_Custom( input, uplusv );
}
