# phony targets
.PHONY: clean clean_target clean_all

# compiler flags
CFLAGS=-g -Wall -W -pedantic

# compiler
CC=gcc

# all object files
OBJS=help.o dns.o interpret.o readline.o main.o print_voltage.o print_edge.o

# libs
LDLIBS=-L./libs -llinops

# final project name, thus, final build target
PROG=main

# overall built target
all: $(PROG)

# link the final project
$(PROG):	$(OBJS)

	$(CC) $(CFLAGS) $(OBJS) -o $@  $(LDLIBS)  
	
# compile all needed files taking into account all their dependencies
main.o: help.o dns.o interpret.o readline.o print_voltage.o print_edge.o
dns.o: dns.h
help.o: help.h

# some clean options
clean_target:
	rm $(PROG)
clean_all:
	rm $(OBJS) $(PROG)
clean:	
	rm $(OBJS)
