#include "matrix_assembly.h"
#include "linops.h"
#include <stdlib.h>
#include "struct.h"

matrix* assemble_FMM(Edge *edge_array, Cycle **cycles, int *num_edges, int *num_cycles) {
    // create the matrix structure
    matrix *mat = malloc(sizeof(matrix));
    create_matrix(mat, *num_cycles, *num_edges);

    // iterate over all cycles
    for(int i = 0; i < *num_cycles; ++i) {

        // iterate over all edged
        for(int j = 0; j < *num_edges; ++j) {

            // variables to access all edges of a cycle
            int k_start = 0;
            int k_end = 1;

            // iterate over all edges of a cycle
            for(int k = 0; k < cycles[i]->length; ++k) {

                // Edge wird vorwaerts durchlafen
                if(edge_array[j].source == cycles[i]->my_cycle[k_start]->id
                   && edge_array[j].target == cycles[i]->my_cycle[k_end]->id) {
                    mat->value[i][j] = 1;
                    break; // if edge is found, no further checking necessary
                }

                // Edge wird rueckwaerts durchlaufen
                else if(edge_array[j].source == cycles[i]->my_cycle[k_end]->id
                        && edge_array[j].target == cycles[i]->my_cycle[k_start] ->id) {
                    mat->value[i][j] = -1;
                    break;  // if edge is found, no further checking necessary
                }

                // update cycle variables, i. e. increment them by one with wrap around
                // after cycle length
                update_start_end(&k_start, &(cycles[i]->length));
                update_start_end(&k_end, &(cycles[i]->length));
            }
            // the default case of 0 will automatically be fulfilled if no matching edge is found
            // since the matrix is initialised with zeros
        }
    }

    // return the matrix
    return mat;
}

// print the KMM matrix to a stream
void print_KMM(FILE *stream, matrix *mat) {
    for(int i = 0; i < mat->dim1; ++i)
        for(int j = 0; j < mat->dim2; ++j) {
            fprintf(stream, "%f", mat->value[i][j]);
            if(j == mat->dim2 - 1)
                fprintf(stream, "\n");
            else
                fprintf(stream, " ");
        }
}

// increment the start value by one and do a wrap around when
// the cycle_length is exceeded
void update_start_end(int *start, int *cycle_length) {
    if(*start != *cycle_length - 1)
        ++(*start);
    else
        *start = 0;
}


// create the Z matrix using the edge weights
matrix* assemble_ZM(Edge *edge_array, int *num_edges) {
    // create the matrix structure
    matrix *mat = malloc(sizeof(matrix));
    create_matrix(mat, *num_edges, *num_edges);

    for(int i = 0; i < *num_edges; ++i) {
        mat->value[i][i] = edge_array[i].weight;
    }

    return mat;
}
