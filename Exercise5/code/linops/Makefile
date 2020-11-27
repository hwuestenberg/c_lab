CFLAGS=-Wall
all: liblinops.a linopsTest gaussTest
gaussTest: liblinops.a
linopsTest: liblinops.a
liblinops.a:liblinops.a(linops.o gauss.o)
	ar scr $@ $^
clean:
	rm -f *.a *.o *Test
