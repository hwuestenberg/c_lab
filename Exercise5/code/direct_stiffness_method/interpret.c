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
    case VOLTAGE: {
	  // Create and initialize list of waypoints -> brackets allow declaration
	  int status;
	  matrix* Yn;
	  Yn = malloc(sizeof(matrix));
	  create_matrix(Yn,*num_node,*num_edge);
	  
	  vector *in,*un;
	  in = malloc(sizeof(vector));
	  create_vector(in,(*num_node)-1);	// Reduce size due to grounding
	  in->value[0] = 0.1;	// Given predefinition
	  un = malloc(sizeof(vector));
	  create_vector(un,(*num_node)-1);	// Reduce size due to grounding
	  
	  print_matrix(Yn);
	  calc_admitMatrix(*num_edge, edge_array, Yn);
	  print_matrix(Yn);
	  
	  // Ground node 6 -> delete the node (row) and connected edges (columns)
	  delete_row(5,Yn);
	  delete_column(7,Yn);
	  delete_column(6,Yn);
	  delete_column(5,Yn);
	  
	  print_matrix(Yn);
	  status = solve(*un, *Yn, *in);

	  if(status == 1)
		print_voltage(out,un);
	
	  else {
		  if(status == -1)
			  fprintf(out,"There was an GENERAL error solving the linear system");
		  if(status == -2)
			  fprintf(out,"There was an dimension mismatch");
		  if(status == -3)
			  fprintf(out,"There was an NUMERICAL error solving the linear system");
	  }	
	  
	  // Free the matrix and vectors
	  free_matrix(Yn);
	  free_vector(in);
	  free_vector(un);
	  return;
	}
	case END:
	  return;
    default:
      return;
  }
} 

