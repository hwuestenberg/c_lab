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

#include "sort.h"
#include "io.h"
#include "stopwatch.h"

int main(int argc, char** argv)
{
    // variables to control the programm behaviour
    int quick = 0; // quick sort was selected
    int insertion = 0; // insertion was selected
    FILE *fp = stdin; // input file --> no file --> stdin
    int input = 0; // position of input file in argv
	int time_it = 0; // measure time

	// if no arguments are specified, print the 
	// proper usage to the terminal
	if(argc == 1) {
		printf("How to use sort:\n[-i]\tinsertion sort\n[-q]"
			"\tquick sort\n[-t]\tmeasure time\n[s]\tfilename "
			"of file to sort (optional --> stdin otherwise)\n");
		return 1;
	}

    // process the function arguments
    for(int i = 1; i < argc; ++i) {
        if(argv[i][0] == '-') {
            switch(argv[i][1]) {
                // quicksort
                case 'q':
                    quick = 1;
                    break;
                // insertion sort
                case 'i':
                    insertion = 1;
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
            // filename
            input = i;
            fp = fopen(argv[i], "r");
            if(fp == NULL) {
                fprintf(stderr, "Could not open %s as input file\n", argv[i]);
                return -1;
            }
        }
    }

    // using quick and insertion sort at the same time makes no sense
    if(quick == 1 && insertion == 1) {
        fprintf(stderr, "Only choose one sorting algorithm\n");
        return -1;
    }

	// specifying no sorting algorithm makes no sense either
    if(quick == 0 && insertion == 0) {
        fprintf(stderr, "We need a sorting algorithm\n");
        return -1;
    }

    // variables for data
    int* data = NULL;
    int length = 0;

    // read data from input file
    read(fp, &data, &length);

    // close input file
    fclose(fp);

    // ensure we have data
    if(length == 0) {
        fprintf(stderr, "No data to read\n");
        return -1;
    }
	
	// start timer if required		
	if(time_it)
		start_timer();

    // sort either by quick or insertion sort
    if(quick) {
        printf("Sorting %i value(s) using quick sort\nHang on! I'm busy...\n", length);
        quick_sort(data, &length);	
    }
    else {
        printf("Sorting %i value(s) using insertion sort\nHang on! I'm busy...\n", length);
        insertion_sort(data, &length);
    }

	// read elapsed time if required
	if(time_it) {
		printf("Elapsed time: %fs\n", read_timer());
		pause_timer();
	}

    // pointer to output filename
	char *output_filename = NULL;

	// number of characters of output filename (12 is length of "piped_input" string)
	int characters = 12;

	// get the number of characters of the input filename
	if(fp != stdin) 
    	characters = sizeof(argv[input]) / sizeof(char) - 1;

	// allocate memory to concatenate the output filename
	output_filename = malloc(sizeof(char) * (characters + 8));
	if(output_filename == NULL) {
	    fprintf(stderr, "Could not allocate memory for output filename\n");
	    return -1;
	}

	// concatenate the output filename
	if(fp != stdin)
		strcpy(output_filename, argv[input]);
	else	
		strcpy(output_filename, "piped_input");
	strcat(output_filename, "_sorted");

    // open output file
    FILE *out = fopen(output_filename, "w");
    if(out == NULL) {
        fprintf(stderr, "Could not open output file\n");
        return -1;
    }

    // write sorted data to output file
    write(out, data, length);

    // close output file
    fclose(out);
	
	free(data);
	free(output_filename);
    return 0;
}
