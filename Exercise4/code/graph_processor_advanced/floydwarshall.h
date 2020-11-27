#ifndef __FLOYDWARSHALL__H
#define __FLOYDWARSHALL__H
#include "struct.h"
#include <float.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "int_list.h"
#include "lin_struct.h"

typedef enum floyd_warshall_status { FEW_NODES=1 , SUCCESS=0 } SP_STATUS;

/******************************************************************************/
/* function edge_cost: estimates the weigth of the direct edge from a to b    */
/*   if the edge is defined: its weight is returned                           */
/*   if the edge does not exist: infinite is returned                         */
/*   if a and b are the same node: 0 is returned                              */
/* args: a(id of source node) b(id of target node)                            */
/*       num_edge(number of edges in given array of edges)                    */
/*       edge(array of edges representing the graph)                          */
/******************************************************************************/
double edge_cost(int a,int b, int num_edge, Edge* edge);


/******************************************************************************/
/* function floydwarshall: compute the shortest path from request->source node*/ 
/*   to request->target node through a graph given by an array of edges       */
/*   (parameter Edge* edge); the Edge struct is defined in file struct.h.     */
/* args:   request(node with requested source and target information),        */
/*         num_node(number of nodes in graph), edge(edges of the graph)       */
/* return: int point value(a value of type floyd_warshall_status)             */
/*         SUCCESS on success; FEW_NODES of requested nodes are not in graph  */
/*         request->weight contains the estimated shortest distance           */
/******************************************************************************/
SP_STATUS floydwarshall(Edge* request, int num_node, int num_edge, Edge* edge);

// if edge is defined return target (b)
// if a == b return b
// else return -1
int edge_target(int a, int b, int num_edge, Edge* edges);

// Return optimal route between source and dest (=List of waypoints)
Int_List evaluate_optimal_route(int** route, int source, int dest);

// Shortest path from request->source to reuqest->target
// Returns SP_Status, request->weight with shortest distance 
// and waypoints between source und target
SP_STATUS floydwarshall_route(Edge* request, Int_List* waypoints, int num_node, int num_edge, Edge* edges);
#endif
