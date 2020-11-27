#ifndef __SEARCH_H
#define __SEARCH_H

/*
 * search number: number you are looking for
 * n: length or data array
 * data: actual data
 * return: -1 in case of failure, otherwise index of data
 *			element	containing the number in question
*/
int linear_search(int search_number, int *n, int *data);


/*
 * search number: number you are looking for
 * n: length or data array
 * data: actual data
 * return: -1 in case of failure, otherwise index of data
 *			element	containing the number in question
*/
int binary_search(int search_number, int *n, int *data);

#endif
