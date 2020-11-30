#include "Input.h"
#include "B_Poly.h"
#include "Experiment_Data.h"

typedef Polyhedron::Edge_iterator edge_iterator;
typedef Polyhedron::Facet_iterator facet_iterator;

void Compute_Experiment_Data ( Input const& input, vector<B_Poly>& polys, Experiment_Data& e_d )
{
    vector<int> num_vertices_per_zone( input.zone_limit, 0 );
    vector<int> num_edges_per_zone( input.zone_limit, 0 );
    vector<int> num_facets_per_zone( input.zone_limit, 0 );
    vector<int> num_polys_per_zone( input.zone_limit, 0 );
    
    for (int counter = 0; counter < polys.size(); ++counter)
    {
        num_polys_per_zone[polys[counter].zone - 1] += 1;
        
        int num_facets = 0;
        int num_edges = 0;
        
        for (facet_iterator f = polys[counter].poly.facets_begin(); f != polys[counter].poly.facets_end(); ++f)
        {
            ++num_facets;
        }
        
        for (edge_iterator e = polys[counter].poly.edges_begin(); e != polys[counter].poly.edges_end(); ++e)
        {
            ++num_edges;
        }
        
        num_edges_per_zone[polys[counter].zone - 1] += num_edges;
        num_facets_per_zone[polys[counter].zone - 1] += num_facets;
    }
    
    num_vertices_per_zone[0] = 2 + num_edges_per_zone[0] - num_facets_per_zone[0];
    
    for (int counter_1 = 1; counter_1 < input.zone_limit; ++counter_1)
    {
        num_vertices_per_zone[counter_1] = num_edges_per_zone[counter_1] - num_facets_per_zone[counter_1];
    }
    
    for (int counter = 0; counter < input.zone_limit; ++counter)
    {
        e_d.m_vertices[input.motif_iter].second[counter] += num_vertices_per_zone[counter];
        e_d.m_polys[input.motif_iter].second[counter] += num_vertices_per_zone[counter];
    }
}
