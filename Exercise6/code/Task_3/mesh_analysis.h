#ifndef MESH_ANALYSIS_H_INCLUDED
#define MESH_ANALYSIS_H_INCLUDED

#include "struct.h"
#include "linops.h"

void mesh_analysis(Node *node_array, Edge *edge_array, vector *current, int *num_nodes, int *num_edges);

#endif // MESH_ANALYSIS_H_INCLUDED
