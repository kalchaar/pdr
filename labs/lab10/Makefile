# Keenan Alchaar | ka5nt | 04/30/2021 | Makefile (inlab 10)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g
#OBJECTS = HuffmanNode.o huffmanenc.o heap.o
OBJECTS = HuffmanNode.o huffmandec.o
a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "inlab 10 compiled"

#HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
#HuffmanNode.o: HuffmanNode.h
#huffmanenc.o: huffmanenc.cpp HuffmanNode.h heap.h
#heap.o: heap.cpp heap.h HuffmanNode.h
#heap.o: heap.h HuffmanNode.h

huffmandec.o: huffmandec.cpp HuffmanNode.h
HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
HuffmanNode.o: HuffmanNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out
