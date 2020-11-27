#include "floydwarshall.h"
#include "edge_cost.h"
SP_STATUS floydwarshall(Edge* request, int num_node, int num_edge, Edge* edges)
{
  double path[num_node][num_node];
  int i,j,k;
  
  // Catch IDs out of bounds
  if(request->source > num_node || request->target > num_node)
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
 
// if edge is defined return target (b)
// if a == b return b
// else return -1
int edge_target(int a, int b, int num_edge, Edge* edges) {
	for(int i=0;i<num_edge;++i) {
		if( a == b )
			return b;
		if((edges+i)->source == a && (edges+i)->target == b)
			return b;
	}
	return -1;
}

// return optimal route between source and dest (=List of waypoints)
Int_List evaluate_optimal_route(int** route, int source, int target) {
	//printf("CALL\n");
	Int_List retRoute,subroute;
	init_int_list(&retRoute);
	init_int_list(&subroute);
	
	int waypoint = route[source][target];
	if(source!=target && target!=route[source][target]) {
		// Optimize: source -> waypoint
		subroute = evaluate_optimal_route(route,source,waypoint);
		tail_int_list_iter(&retRoute);
		int_list_insert_at_iter(&retRoute,&subroute);
		
		// Optimize: waypoint -> target
		subroute = evaluate_optimal_route(route,waypoint,target);
		tail_int_list_iter(&subroute);
		int_list_insert_at_iter(&retRoute,&subroute);
	}
	else {
		append_int_list(&retRoute,waypoint);
	}
	free_int_list(&subroute);	// Free data aferwards
	return retRoute;
	
}

// Shortest path from request->source to reuqest->target
// Returns SP_Status, request->weight with shortest distance 
// and waypoints between source und target
SP_STATUS floydwarshall_route(Edge* request, Int_List* waypoints, int num_node, int num_edge, Edge* edges) {
	double** path_cost = create_double_square_matrix(num_node);
	int** route = create_int_square_matrix(num_node);
	
	// Catch IDs out of bounds
	if(request->source > num_node || request->target > num_node)
		return FEW_NODES;
	
	// Initialisation
	for(int i=0;i<num_node;++i) {
		for(int j=0;j<num_node;++j) {
			path_cost[i][j] = edge_cost(i,j,num_edge,edges);
			route[i][j] = edge_target(i,j,num_edge,edges);
		}
	}
	// Algorithm
	for(int k=0;k<num_node;++k) {
		for(int i=0;i<num_node;++i) {
			for(int j=0;j<num_node;++j) {
				if(path_cost[i][j] > path_cost[i][k]+path_cost[k][j]) {
					path_cost[i][j] = path_cost[i][k]+path_cost[k][j];
					route[i][j] = k;
				}
			}
		}
	}
	// Return quantities
	*waypoints = evaluate_optimal_route(route,request->source,request->target);		
	request->weight = path_cost[request->source][request->target];
	
	// Free memeory
	free_double_square_matrix(path_cost);
	free_int_square_matrix(route);
	return SUCCESS;
}





