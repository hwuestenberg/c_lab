# phony targets
.PHONY: clean clean_target clean_all

# compiler flags
CFLAGS=-g -Wall -W -pedantic

# compiler
CC=gcc

# all object files
OBJS=int_list.o int_list_test.o

# libs
#LDLIBS=-L. -lintlist

# final project name, thus, final build target
PROG=intlist

# overall built target
all: $(PROG)

# link the final project
$(PROG):	$(OBJS)

	$(CC) $(CFLAGS) $(OBJS) -o $@  $(LDLIBS)  
	
# compile all needed files taking into account all their dependencies
lin_list_test.o:	lin_list_test.c lin_list.o
lin_list.o:		lin_list.h

# some clean options
clean_target:
	rm $(PROG)
clean_all:
	rm $(OBJS) $(PROG)
clean:	
	rm $(OBJS)
