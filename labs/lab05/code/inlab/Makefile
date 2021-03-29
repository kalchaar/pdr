# Keenan Alchaar | ka5nt | 03/23/2021 | Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall
DEBUG=-g
OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o
a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "inlab 05 compiled"

BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out
