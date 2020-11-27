#include "mesh_analysis.h"
#include "matrix_assembly.h"
#include "dfs.h"
#include "struct.h"
#include "cycle.h"
#include <stdlib.h>

void mesh_analysis(Node *node_array, Edge *edge_array, vector *current, int *num_nodes, int *num_edges) {

    printf("\n---- START OF MESH ANALYSIS ----\n");
    // perform DFS
    dfs(node_array, edge_array, *num_nodes, *num_edges);

    //print_dfs_results(stdout, node_array, edge_array, num_node, num_edge);

    Cycle **cycle_array = malloc(sizeof(Cycle*) * *num_edges); // we cannot have more than num_edge cycles
    int num_cycles = 0;
    get_cycles(cycle_array, node_array, edge_array, *num_nodes, *num_edges, &num_cycles);

    //print_cycles(stdout, cycle_array, num_cycles);

    // assemble the FMM matrix
    matrix *B = assemble_FMM(edge_array, cycle_array, num_edges, &num_cycles);

    // cylces are no longer needed
    for(int i = 0; i < num_cycles; ++i) {
        free(cycle_array[i]->my_cycle);
        free(cycle_array[i]);
    }
    free(cycle_array);

    //print_KMM(stdout, B);

    // assemble the K matrix
    matrix *Z = assemble_ZM(edge_array, num_edges);

    // set up vector for u_l
    vector *u_l = malloc(sizeof(vector));
    create_vector(u_l, B->dim1);

    // calculate u_l and print error_state to screen
    printf("u_L = B*u returned %d\n", mat_vec_mul(*u_l, *B, *current));

    // change sign of u_l
    double scal = -1;
    vec_scal_mul(*u_l, &scal);

    // calculate B * Z and print error state to screen
    matrix *res = malloc(sizeof(matrix));
    create_matrix(res, B->dim1, Z->dim2);
    printf("B * Z returned %i\n", mat_mat_mul(*res, *B, *Z));

    // calculate B * Z * B^T and print error state to screen
    matrix *A = malloc(sizeof(matrix));;
    create_matrix(A, res->dim1, B->dim1);
    printf("B * Z * B^T returned %i\n", mat_matT_mul(*A, *res, *B));

    // set up i_l vector
    vector *i_l = malloc(sizeof(vector));;
    create_vector(i_l, A->dim1);

    // solve for i_l
    printf("Solve for i_l returned %i\n", solve(*i_l, *A, *u_l));

    // change sign of i_l
    vec_scal_mul(*i_l, &scal);

    // create identity matrix to transpose B
    matrix *I = malloc(sizeof(matrix));
    create_matrix(I, B->dim2, B->dim2);
    for(int i = 0; i < B->dim2; ++i)
        I->value[i][i] = 1;

    // create vector for transpose of B
    free_matrix(res);
    res = malloc(sizeof(matrix));
    create_matrix(res, B->dim2, B->dim1);

    // transpose B and print error status to screen
    printf("Transpose of B returned %i\n", mat_matT_mul(*res, *I, *B));

    // create solution vector for i
    vector *iv = malloc(sizeof(vector));
    create_vector(iv, res->dim1);

    // solve for i and print error status to screen
    printf("Solve for i returned %i\n", mat_vec_mul(*iv, *res, *i_l));

    // output results
    printf("---- END OF MESH ANALYSIS ----\n\n");
    printf("Solution for i: ( ");
    for(int i = 0; i < iv->dim; ++i) {
        printf("%.4f", iv->value[i]);
        if(i != iv->dim - 1)
            printf(" ");
        else
            printf(" )\n\n");
    }

    printf("Solution for u_l: ( ");
    for(int i = 0; i < u_l->dim; ++i) {
        printf("%.4f", u_l->value[i]);
        if(i != u_l->dim - 1)
            printf(" ");
        else
            printf(" )\n");
    }


    free_matrix(res);
    free_matrix(A);
    free_matrix(I);
    free_vector(u_l);
    free_vector(i_l);
    free_vector(iv);
    free_matrix(B);
    free_matrix(Z);
}
