# Keenan Alchaar | ka5nt | 04/13/2021 | Makefile (prelab 08)

CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OBJECTS = mathlib.o mathfun.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~
