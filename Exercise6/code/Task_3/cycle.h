#ifndef CYCLE_H_INCLUDED
#define CYCLE_H_INCLUDED

#include "struct.h"
#include <stdio.h>

void get_cycles(Cycle **cycles, Node *node_array, Edge *edge_array, int num_nodes, int num_edges, int *num_cycles);

Cycle* build_cycle(Node *source, Node *target, int num_nodes);

void print_cycles(FILE *stream, Cycle **cycles, int num_cycles);

#endif // CYCLE_H_INCLUDED
