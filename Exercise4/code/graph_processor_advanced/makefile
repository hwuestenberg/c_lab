# phony targets
.PHONY: clean clean_target clean_all

# compiler flags
CFLAGS=-g -Wall -W -pedantic

# compiler
CC=gcc

# all object files
OBJS=help.o floydwarshall.o print_edge.o interpret.o readline.o edge_cost.o main.o

# libs
LDLIBS=-L./libs -lintlist -llin_struct

# final project name, thus, final build target
PROG=main

# overall built target
all: $(PROG)

# link the final project
$(PROG):	$(OBJS)

	$(CC) $(CFLAGS) $(OBJS) -o $@  $(LDLIBS)  
	
# compile all needed files taking into account all their dependencies
main.o: help.o floydwarshall.o print_edge.o interpret.o readline.o edge_cost.o
floydwarshall.o: floydwarshall.h
help.o: help.h

# some clean options
clean_target:
	rm $(PROG)
clean_all:
	rm $(OBJS) $(PROG)
clean:	
	rm $(OBJS)
