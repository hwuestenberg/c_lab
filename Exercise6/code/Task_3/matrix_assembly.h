#ifndef MATRIX_ASSEMBLY_H_INCLUDED
#define MATRIX_ASSEMBLY_H_INCLUDED

#include "struct.h"
#include "linops.h"
#include <stdio.h>

matrix* assemble_FMM(Edge *edge_array, Cycle **cycles, int *num_edges, int *num_cycles);

void update_start_end(int *start, int *cycle_length);

void print_KMM(FILE *stream, matrix *mat);

matrix* assemble_ZM(Edge *edge_array, int *num_edges);

#endif // MATRIX_ASSEMBLY_H_INCLUDED
