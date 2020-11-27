#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include "struct.h"
#include <stdio.h>

void dfs(Node *node_array, Edge *edge_array, int num_nodes, int num_edges);

void dfs_visit(Node *node_array, Edge *edge_array, int num_nodes, int num_edges, int n, int depth);

void print_dfs_results(FILE *stream, Node *node_array, Edge *edge_array, int num_nodes, int num_edges);
#endif // DFS_H_INCLUDED
