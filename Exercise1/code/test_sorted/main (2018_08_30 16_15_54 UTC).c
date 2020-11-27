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

#include "io.h"

int main(int argc, char** argv)
{
    // ensure that we have a file to check
    if(argc == 1) {
        fprintf(stderr, "Please enter file to check\n");
        return -1;
    }

    // file pointer to input file
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        fprintf(stderr, "Could not open input file\n");
        return -1;
    }

    // variables for data storage
    int *data = NULL;
    int length = 0;

    // read data
    read(fp, &data, &length);

    // close input file
    fclose(fp);

    // check sorting
    for(int i = 1; i < length; ++i) {
        if(data[i] < data[i - 1]) {
            fprintf(stderr, "Sorting was not successful!\n");
            return -1; // sorting did not work
        }
    }

    // output on successful sorting
    printf("File is perfectly sorted\n");
	
	free(data);

    return 0;
}
