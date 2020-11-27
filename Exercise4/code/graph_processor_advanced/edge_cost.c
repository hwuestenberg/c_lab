#include "edge_cost.h"

double edge_cost(int a,int b, int num_edge, Edge* edge)
{
  int i;
  if(a==b)return 0.0;
  for(i=0;i<num_edge;i++)
    if(edge[i].source==a&&edge[i].target==b)
      return edge[i].weight;
  return DBL_MAX;
}
