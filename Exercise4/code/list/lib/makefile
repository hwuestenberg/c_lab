.PHONY: clean clean_all

# All objects
OBJS = int_list.o

# Final build target
PROG = libintlist.a

# Build Target
all: $(PROG)
	ar sr $(PROG) $(OBJS)

# Compile library and dependencies
libintlist.a:		int_list.o
int_list.o:		int_list.h

clean:
	rm *.o
	
clean_all:
	rm *.o *.a