# Keenan Alchaar | ka5nt | 04/19/2021 | Makefile (prelab 09)

CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OBJECTS = threexplusone.o threexinput.o timer.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~
