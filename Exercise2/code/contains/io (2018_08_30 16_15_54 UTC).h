#ifndef __IO_H
#define __IO_H
#include<stdio.h>
/**************************************************/
/* function to write an integer array into a file */
/* args: 1. filepointer to write to               */
/*       2. integer array                         */
/*       3. length of the array                   */
/**************************************************/
void write(FILE*, int*, int);
/**************************************************/
/* function to read an integer array from file    */
/* args: 1. filepointer to read from              */
/*       2. pointer to integer array              */
/*          (has to point to NULL)                */
/*       3. pointer to integer will be filled     */ 
/*          with the length of the read array     */
/* return: 0 on success, -1 on error              */
/**************************************************/
int read (FILE*, int**, int*);
#endif
