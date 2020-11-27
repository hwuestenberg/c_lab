#ifndef READLINE__H
#define READLINE__H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "expressiontype.h"
/******************************************************************************/
/*  function readline: function reads in a line from file fp, analyses the    */
/*                     content of the line and saves the given data in a      */
/*                     context structure. It returns an identifier of the     */
/*                     type of expression which was read.                     */
/******************************************************************************/
expression_type readline(FILE* fp,Reader_Context* context);
#endif
