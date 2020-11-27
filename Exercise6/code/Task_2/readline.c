#include "readline.h"
expression_type readline(FILE* fp,Reader_Context* context)
{
  int string_length;
  char string[81],name[40];
  if(fgets(string,80,fp))
  {
    if(sscanf(string,"NODE( %39s )",name) == 1)
    {
      string_length=strlen(name);
      context->node.name=(char*)malloc(sizeof(char)*(string_length));
      memcpy(context->node.name,name,string_length);
      if(context->node.name[string_length-1]==')')
        context->node.name[string_length-1]='\0';
      return NODE;
    }
    if(sscanf(string,"EDGE( %i , %i , %f )", &context->edge.source,
         &context->edge.target, &context->edge.weight) == 3
    )
      return EDGE;
    if(!strncmp(string,"HELP",4))
      return HELP;

    if(!strncmp(string, "QUIT", 4))
        exit(0);
    if(!strncmp(string, "END", 3))
        return END;
    if(!strncmp(string, "DFS", 3))
        return DFS;
    else return ERROR;
  }
  else return END;
}
