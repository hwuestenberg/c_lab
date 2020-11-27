#ifndef STRUCT_H
#define STRUCT_H
typedef struct edge_struct
{
  int source, target;
  float weight;
} Edge;

typedef struct node_struct
{
  char* name;
} Node;

typedef struct reader_context_struct
{
  Edge   edge;
  Node   node;
}Reader_Context;
#endif
