/* 
 * 
 * Philipp Donn, CSE, 2. Semester, Mat-Nr 4897815
 * Henrik Wuestenberg, CSE, 2. Semester, Mat-Nr 4911788
 * 
 * 11.04.2018
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */
int main() {
    char name[10];
    
    FILE *file;
    file = fopen("Namen.dat", "r");
    if(file == NULL)
        printf("Error: could not open file\n");
    
    while(fscanf(file, "%9s", name) != EOF) {
        printf("Hallo, %s!\n", name);
    }

    fclose(file);
    
    return 0;
}

