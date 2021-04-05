# Keenan Alchaar | ka5nt | 03/30/2021 | Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS = hashTable.o wordPuzzle.o timer.o
a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "postlab 06 compiled"

hashTable.o: hashTable.cpp hashTable.h
hashTable.o: hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h
timer.o: timer.h

.PHONY: clean
clean:
	-rm -f *.o a.out
