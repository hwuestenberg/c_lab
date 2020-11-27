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
    do {
        printf("Please enter your name: ");
        scanf("%9s", name);
        if(strcmp(name, "Ende")) // 0 if strings are equal
            printf("Hallo, %s!\n", name);  
    }while(strcmp(name, "Ende"));
    
    return 0;
}

