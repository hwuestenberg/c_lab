#include <stdlib.h>

int linear_search(int search_number, int *n, int *data) {
	// iterate over all data in data
	for(int i = 0; i < *n; ++i)
		// compare i-th element with search number
		// and return i if it equals search number
		if(*(data + i) == search_number)
			return i;

	// search_number was not found in data
	return -1;
}

int binary_search(int search_number, int *n, int *data) {
	// initialise helper varialbes
	int left = 0, right = *n - 1, middle = 0;
	
	while(right >= left) {
		// compute (new) middle element
		middle = abs(((double) (right - left)) / 2)  + left;

		// check if middle element matches search_number
		if(*(data + middle) == search_number)
			return middle;

		// middle element does not match search_number 
		// alter search range by changing left or right
		if (search_number > *(data + middle))
			left = middle + 1;
		else
			right = middle - 1;
	}

	// number was not found
	return -1;
}
