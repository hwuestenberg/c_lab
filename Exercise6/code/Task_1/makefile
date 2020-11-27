CFLAGS=-g -Wall -std=c99 -pedantic -Wextra
CC = gcc

LDLIBS=-L. -llinops
task_1: help.o interpret.o main.o print_edge.o readline.o dfs.o
	$(CC) $(CFLAGS) $^ -o $@  $(LDLIBS) 
main.o: struct.h expressiontype.h readline.h interpret.h linops.h help.h
interpret.o: interpret.h interpret.c
dfs.o: dfs.h struct.h
help.o: help.h help.c
readline.o: readline.h readline.c
print_edge.o: print_edge.h print_edge.c
clean:
	rm -f *.o
cleaner: clean	
	rm -f task_1
