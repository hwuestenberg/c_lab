/* 
 * 
 * Philipp Donn, CSE, 2. Semester, Mat-Nr 4897815
 * Henrik Wuestenberg, CSE, 2. Semester, Mat-Nr 4911788
 * 
 * 22.04.2018
 * 
 */
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED


void insertion_sort(int* data, int* len);

void swap_data(int* data, int first, int second);

int partition(int* data, int p, int r);

void quick_sort_helper(int* data, int left, int right);

void quick_sort(int* data, int* len);


#endif // SORT_H_INCLUDED
