#ifndef PRINTEDGE__H__
#define PRINTEDGE__H__
#include <stdio.h>
#include "struct.h"
#include "int_list.h"
void print_edge(FILE* fp,char* desc, Edge edge,Node* node_array);
void print_waypoints(FILE* fp, char* desc, Int_List* waypoints, Node* node_array, int num_edge, Edge* edges, int source);
#endif
