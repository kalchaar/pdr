# Keenan Alchaar | ka5nt | 04/23/2021 | Makefile (postlab 09)

CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OBJECTS = binarySearch.o testBinarySearch.o timer.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~
