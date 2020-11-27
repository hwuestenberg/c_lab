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
#include <string.h>

#include "io.h"
#include "search.h"
#include "stopwatch.h"

void check_malloc(void *ptr) {
	if(ptr == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(-1);
	}
}

void check_file(FILE *ptr, char *filename) {
	if(ptr == NULL) {
		fprintf(stderr, "Could not open file %s\n", filename);
		exit(-1);
	}
}
		
int main(int argc, char** argv)
{
    // variables to control the programm behaviour
    int binary = 0; 		// binary was selected
    int linear = 0; 		// linear was selected
    FILE *fp = stdin; 		// file in which we want to search
	FILE *search = stdin; 	// files with numbers to search for
	int time_it = 0; 		// measure time

	// if no arguments are specified, print the 
	// proper usage to the terminal
	if(argc == 1) {
		printf("How to use contains:\n[-b]\tbinary search\n[-l]"
			"\tlinear search\n[-t]\tmeasure time\n[s]\t1. "
			"filename of file containing numbers to search"
			" for\n\t2. filename of file in which search shall"
			" be carried out\n\t   (optional --> stdin otherwise)\n");
		return 1;
	}

    // process the function arguments
    for(int i = 1; i < argc; ++i) {
        if(argv[i][0] == '-') {
            switch(argv[i][1]) {
                // binary search
                case 'b':
                    binary = 1;
                    break;
                // linear search
                case 'l':
                    linear = 1;
                    break;
				// measure time
				case 't':
					time_it = 1;
					break;
                // default
                default:
                    fprintf(stderr, "%s is no valid input parameter\n", argv[i]);
            }
        }
        else {
            // read numbers file first
			if(search == stdin) {
		        search = fopen(argv[i], "r");
		        check_file(search, argv[i]);
			}
			// read file to search in second
			else {
				fp = fopen(argv[i], "r");
				check_file(fp, argv[i]);
			}
        }
    }

    // using binary % linear search at the same time makes no sense
    if(binary == 1 && linear == 1) {
        fprintf(stderr, "Only choose one search method\n");
        return -1;
    }

	// specifying no searching algorithm makes no sense either
    if(binary == 0 && linear == 0) {
        fprintf(stderr, "Choose a search method\n");
        return -1;
    }

    // variables for data
    int *search_data = NULL;
	int *search_numbers = NULL;
    int length_s_data = 0;
	int length_s_numbers = 0;

    // read data from input files
    read(fp, &search_data, &length_s_data);
	read(search, &search_numbers, &length_s_numbers);

    // close input files
	if(fp != stdin)
    	fclose(fp);

	if(search != stdin)
		fclose(search);

    // ensure we have data to search in
    if(length_s_data == 0) {
        fprintf(stderr, "No data to search in\n");
        return -1;
    }

    // ensure we have data to search for
    if(length_s_numbers == 0) {
        fprintf(stderr, "No data to search for\n");
        return -1;
    }
	
	// search result
	int search_result = -1;

	// print to screen which search algorithm has been selected
	if(binary)
		printf("Searching for %i number(s) in %i value(s) using binary search\n", length_s_numbers, length_s_data);
	else
	    printf("Searching %i number(s) in %i value(s) using linear search\n", length_s_numbers, length_s_data);

	// start searching
	for(int i = 0; i < length_s_numbers; ++i) {
		// start timer if required		
		if(time_it)
			start_timer();

		// search by binary or linear search
		if(binary) {
		    search_result = binary_search(search_numbers[i], &length_s_data, search_data);	
		}
		else {
		    search_result = linear_search(search_numbers[i], &length_s_data, search_data);
		} 

		// read elapsed time if required
		if(time_it) {
			printf("Elapsed time: %fs\n", read_timer());
			pause_timer();
		}
		printf("Search for %i returned: %i\n", search_numbers[i], search_result);
	}
	// print a notice concerning indexing
	printf("Notice: indexing starts at 0 and first index of input files contains number of values in file --> add 2 to find the number in the file\n");

	// free mallocs
	free(search_data);
	free(search_numbers);

    return 0;
}
