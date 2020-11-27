#include "interpret.h"
#include <assert.h>

#include "dfs.h"
void interpret(FILE* out,Reader_Context context, expression_type type,
                int* num_edge, Edge* edge_array,int* num_node, Node* node_array)
{
  switch(type)
  {
    case NODE:
      node_array[*num_node]=context.node;
      node_array[*num_node].id = *num_node;
      fprintf(out,"##> NODE[%i]=%s\n",*num_node,node_array[*num_node].name);
      (*num_node)++;
      return;
    case EDGE:
      assert(*num_node>context.edge.source
          && *num_node>context.edge.target);
      edge_array[*num_edge]=context.edge;
      fprintf(out,"##>");
      print_edge(out,"EDGE",edge_array[*num_edge],node_array);
      (*num_edge)++;
      return;
    case HELP:
      fprintf(out,"##> ");
      print_help(out);
      return;
    case ERROR:
      fprintf(out,"\n##> ERROR READING DATA\n");
      return;
    case DFS:
        fprintf(out, "DFS running\n");
        dfs(node_array, edge_array, *num_node, *num_edge);

    default:
      return;
  }
}
