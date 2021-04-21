# Keenan Alchaar | ka5nt | 04/20/2021 | Makefile (inlab 09)

CXX=clang $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g
OBJECTS = linkedlist.o
a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

linkedlist.o: linkedlist.c

.PHONY: clean
clean:
	-rm -f *.o a.out
