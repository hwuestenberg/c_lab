#ifndef __INTERPRETE_H
#define __INTERPRETE_H
#include <stdio.h>
#include "struct.h"
#include "expressiontype.h"
#include "floydwarshall.h"
#include "help.h"
#include "print_edge.h"
void interpret(FILE* out,Reader_Context context,expression_type type, 
                int* num_edge, Edge* edge_array,int* num_node, Node* node_array);
#endif
