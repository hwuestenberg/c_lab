/* 
 * 
 * Philipp Donn, CSE, 2. Semester, Mat-Nr 4897815
 * Henrik Wuestenberg, CSE, 2. Semester, Mat-Nr 4911788
 * 
 * 22.04.2018
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* data, int* len) {
    for(int i = 1; i < *len; ++i) {
        int target = *(data + i);
        int j;
        for (j = i - 1; (j >= 0) && (*(data + j) > target); j--)
            *(data + j + 1) = *(data + j);
        *(data + j + 1) = target;
    }
}

void swap_data(int* data, int first, int second) {
	int temp = *(data + first);
	*(data + first) = *(data + second);
	*(data + second) = temp;
}

int partition(int* data, int left, int right) {
	int pivot = *(data + right);
	int j = left;
	for (int i = left; i < right; i++) {
		if( *(data + i) <= pivot ) {
			if(j != i)
				swap_data(data,i,j);
			j++;
		}
	}
	if(right != j)
		swap_data(data,right,j);
	return j;
}

void quick_sort_helper(int* data, int left, int right) {
	if( left < right ) {
		int p = partition(data, left, right);
		quick_sort_helper(data, left, p-1);
		quick_sort_helper(data, p+1, right);
	}
}

void quick_sort(int* data, int* len) {
	quick_sort_helper(data, 0, *len-1);
}





