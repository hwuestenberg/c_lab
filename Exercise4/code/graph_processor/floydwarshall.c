#include "floydwarshall.h"
#include "edge_cost.h"
SP_STATUS floydwarshall(Edge* request, int num_node, int num_edge, Edge* edges)
{
  double path[num_node][num_node];
  int i,j,k;
  
  // Catch IDs out of bounds
  if(request->source > num_node||request->target > num_node)
	  return FEW_NODES;
  
  // Initialisation
  for(i=0; i<num_node;++i) {
    for(j=0;j<num_node;++j) {
      path[i][j] = edge_cost(i,j,num_edge,edges);
	}
  }
  
  // Algorithm
  for(k=0;k<num_node;++k) {
    for(i=0;i<num_node;++i) {
      for(j=0;j<num_node;++j) {
	    if(path[i][j] > path[i][k]+path[k][j])
			path[i][j] = path[i][k]+path[k][j];
	  }
	}
  }
  request->weight = path[request->source][request->target];
  return SUCCESS;
}
 
