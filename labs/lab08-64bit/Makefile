# Keenan Alchaar | ka5nt | 04/16/2021 | Makefile (postlab 08)

CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OBJECTS = linearSearch.o testLinearSearch.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~
