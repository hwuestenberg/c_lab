#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "struct.h"
#include "expressiontype.h"
#include "readline.h"
#include "interpret.h"
#include "linops.h"
#include "help.h"
#include "dfs.h"

#define MAX_NODE 2000
#define MAX_EDGE 2000

int main(int argc, char** argv)
{
  /*DECLARATION OF ALL VARIABLES*/
  int            type,num_edge=0,num_node=0;
  Edge           edge_array[MAX_EDGE];
  Node           node_array[MAX_NODE];
  FILE*          ifile;
  Reader_Context context;

  /*SHALL WE READ A GIVEN INPUT FILE?*/
  if(argc==2)    ifile=fopen(argv[1],"r");
  else           ifile=stdin;

  /*PRINT THE HELP TEXT*/
  print_help(stderr);

  /*READ THE FILE LINE BY LINE UNTIL END*/
  while((type=readline(ifile,&context))!=END)
  {
    /*INTERPRETE THE READ DATA*/
    interpret(stderr,context,type,&num_edge,edge_array,&num_node,node_array);
  }

  dfs(node_array, edge_array, num_node, num_edge);
  print_dfs_results(stdout, node_array, edge_array, num_node, num_edge);

  return 0;
}

