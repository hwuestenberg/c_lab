#include "interpret.h"
void interpret(FILE* out,Reader_Context context, expression_type type, 
                int* num_edge, Edge* edge_array,int* num_node, Node* node_array)
{
  switch(type)
  {
    case NODE:
      node_array[*num_node]=context.node;
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
    case SHORTESTPATH:
	  //assert(*num_node>context.edge.source // Secure IDs within boundaries
	  //  && *num_node>context.edge.target);
	  if(!floydwarshall(&(context.edge), *num_node, *num_edge, edge_array))
		print_edge(out, "SHORTESTPATH", context.edge, node_array);
	  else {
		  // Print FEW_NODES
		  fprintf(out,"EDGE (%i--(%g)-->%i) not available!!\n",
            context.edge.source,
            0.0,
            context.edge.target);
	  }
	  return;
	case END:
	  return;
    default:
      return;
  }
} 

