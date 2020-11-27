#include "print_edge.h"
void print_edge(FILE* fp,char* desc, Edge edge,Node* node_array)
{
    fprintf(fp,"%s(%s--(%g)-->%s)\n",desc,
            node_array[edge.source].name,
            edge.weight,
            node_array[edge.target].name);
}

void print_waypoints(FILE* fp, char* desc, Int_List* waypoints, Node* node_array, int num_edge, Edge* edges, int source) {
	int cur = 0;						
	prepend_int_list(waypoints,source);	// Add source to the waypoints
	
	for(head_int_list_iter(waypoints);		// First waypoint is head
        !is_tail_int_list_iter(waypoints);	// Stop before tail	
        incr_int_list_iter(waypoints)) {
		// Evaluate edge.weight for each intemediate edge
		for(int i=0;i<num_edge;++i) {
			if((edges+i)->source == waypoints->iter->value && (edges+i)->target == waypoints->iter->next->value) {
				cur = i;					// Recognise current edge
				break;
			}
		}
		// Print all edges
		fprintf(fp,"%s(%s--(%g)-->%s)\n",desc,
				node_array[waypoints->iter->value].name,
				(edges+cur)->weight,
				node_array[waypoints->iter->next->value].name);
	}
	fprintf(fp,"\n");
}