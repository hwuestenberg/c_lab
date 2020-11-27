#ifndef __INTERPRET_H
#define __INTERPRET_H
#include <stdio.h>
#include "struct.h"
#include "expressiontype.h"
#include "dns.h"
#include "help.h"
#include "linops.h"
#include "print_edge.h"
#include "print_voltage.h"

void interpret(FILE* out,Reader_Context context,expression_type type, 
                int* num_edge, Edge* edge_array,int* num_node, Node* node_array);
#endif
