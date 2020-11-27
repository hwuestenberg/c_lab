#include "dns.h"

error_type calc_admitMatrix(int num_edges, Edge* edge_array, matrix* Yn) {
	int source,target;
	float weight;
	
	if( num_edges < 1 )
		return WRONGDIMENSION;
	
	
	// Calculate Yn
	for(int i=0; i<num_edges; ++i) {
		source = edge_array[i].source;	// Make code readable
		target = edge_array[i].target;
		weight = edge_array[i].weight;
		
		Yn->value[source][source] += 1/weight;	// Construct node admittancy matrix
		Yn->value[source][target] -= 1/weight;
		Yn->value[target][source] -= 1/weight;
		Yn->value[target][target] += 1/weight;
	}
	return SUCCESS;
}
