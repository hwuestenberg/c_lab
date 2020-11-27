#include "print_edge.h"
void print_edge(FILE* fp,char* desc, Edge edge,Node* node_array)
{
    fprintf(fp,"%s(%s--(%g)-->%s)\n",desc,
            node_array[edge.source].name,
            edge.weight,
            node_array[edge.target].name);
}

