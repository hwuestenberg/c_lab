#ifndef STRUCT_H
#define STRUCT_H
typedef enum node_color_enum {WHITE = 0, BLACK = 1, GREY = 2} node_color;

typedef struct edge_struct
{
  int source, target, color;
  float weight;
} Edge;

typedef struct node_struct
{
    int color, id;
    struct node_struct *pre;
    int depth;
    char* name;
} Node;

typedef struct reader_context_struct
{
  Edge   edge;
  Node   node;
}Reader_Context;

typedef struct cycle_struct {
    int length;
    Node **my_cycle;
} Cycle;

#endif
