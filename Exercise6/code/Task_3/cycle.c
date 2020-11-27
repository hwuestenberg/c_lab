#include "cycle.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void get_cycles(Cycle **cycles, Node *node_array, Edge *edge_array, int num_nodes, int num_edges, int *num_cycles) {
    // iterate over all edges
    for(int i = 0; i < num_edges; ++i)
        // only process WHITE edges as they may be closing edges
        if(edge_array[i].color == WHITE) {
            // get source and target, just for convenience...
            int source = edge_array[i].source;
            int target = edge_array[i].target;

            // change source and target if necessary
            if(node_array[source].depth >= node_array[target].depth) {
                int t = source;
                source = target;
                target = t;
            }

            // call build_cycle to build up the found cycle
            cycles[*num_cycles] = build_cycle(&node_array[source], &node_array[target], num_nodes);
            ++(*num_cycles); // increment cycle counter by one (in place!)
        }
}

Cycle* build_cycle(Node *source, Node *target, int num_nodes) {
    // create a new cycle
    Cycle *new_cycle = malloc(sizeof(Cycle));
    new_cycle->my_cycle = malloc(sizeof(Node*) * (num_nodes + 1)); // a cycle cannot have more than num_nodes +1

    Node *p = target; // "cursor" node
    // do it as long as p != source->pre in order to have a full cycle in the
    // cycle structure, i. e. from target to source including target and source
    while(p != source->pre) {
        new_cycle->my_cycle[new_cycle->length] = p; // add node to cycle
        ++new_cycle->length; // increase cycle length
        p = p->pre; // move p pointer one position further
    }

    // reallocate cycle size to match its actual length
    new_cycle->my_cycle = realloc(new_cycle->my_cycle, sizeof(Node*) * new_cycle->length);
    return new_cycle;
}

// print all found cycles to the specified stream
void print_cycles(FILE *stream, Cycle **cycles, int num_cycles) {
    // iterate over all cycles
    for(int i = 0; i < num_cycles; ++i) {
        // print cycle number
        fprintf(stream, "\nCycle %i:\n", i);

        // iterate over all elements of a cycle
        for(int j = 0; j < cycles[i]->length; ++j) {
            // print the node id
            fprintf(stream, "%i", cycles[i]->my_cycle[j]->id);

            // string handling...
            if(j == cycles[i]->length - 1)
                fprintf(stream, "\n");
            else
                fprintf(stream, " - ");
        }
    }

}
