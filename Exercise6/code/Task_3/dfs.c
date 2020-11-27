#include "dfs.h"
#include "struct.h"
#include <stdio.h>

void dfs(Node *node_array, Edge *edge_array, int num_nodes, int num_edges) {
    // init all node values that are used in this process
    for(int i = 0; i < num_nodes; ++i) {
        node_array[i].color = WHITE;
        node_array[i].pre = NULL; // a node can only have num_nodes -1 predecessors
        node_array[i].depth = 0;
    }

    // set all edges to white
    for(int i = 0; i < num_edges; ++i) {
        edge_array[i].color = WHITE;
    }

    // call dfs_visit in order to move through the tree
    for(int i = 0; i < num_nodes; ++i) {
        if(node_array[i].color == WHITE)
            dfs_visit(node_array, edge_array, num_nodes, num_edges, i, 0);
    }

}

void dfs_visit(Node *node_array, Edge *edge_array, int num_nodes, int num_edges, int n, int depth) {
    node_array[n].color = GREY;
    node_array[n].depth = depth;

    // iterate over all edges
    for(int i = 0; i < num_edges; ++i) {
        Node *target = NULL; // target node

        // find potential neighbours
        // check if the current node is a source/target of an edge
        // if yes --> neighbour is found
        if(edge_array[i].source == n) // node is source --> target node is edge->target
            target = &node_array[edge_array[i].target];
		else if(edge_array[i].target == n) // node is target --> target node is edge->source
			target = &node_array[edge_array[i].source];

        // call recursively this function to perform dfs
        // only if the target node has not been visited yet and there is a target
		if(target != NULL && target->color == WHITE) {
	        // set prev node in target node
            target->pre = &node_array[n];

            // set edge to black --> already processed
            edge_array[i].color = BLACK;
            dfs_visit(node_array, edge_array, num_nodes, num_edges, target->id, depth + 1);
        }

        // reset target node for next iteration
        target = NULL;
    }

    // set node to black --> fully processed
    node_array[n].color = BLACK;
}

void print_dfs_results(FILE *stream, Node *node_array, Edge *edge_array, int num_nodes, int num_edges) {
    fprintf(stream, "\n\n-------- DFS output --------\n");
    for(int i = 0; i < num_nodes; ++i) {
        fprintf(stream, "Node[%i]:\n", i);
        fprintf(stream, "\t.color = %i\n", node_array[i].color);
        if(node_array[i].pre != NULL) {
           fprintf(stream, "\t.pre = %i, .depth = %i\n", node_array[i].pre->id, node_array[i].depth);
        }
        else
            fprintf(stream, "\tNo previous nodes found\n");
    }

    fprintf(stream, "\n\n------ DFS Edge Output ------\n");
    for(int i = 0; i < num_edges; ++i)
        fprintf(stream, "Edge[%i].color = %i, source: %i, target: %i\n", i, edge_array[i].color, edge_array[i].source, edge_array[i].target);
}
