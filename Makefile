Movie: main.o Executive.o BinaryTree.o BinaryNode.o
	g++ -std=c++11 -g -Wall main.o Executive.o BinaryTree.o BinaryNode.o -o Movie

main.o: main.cpp Executive.h Executive.cpp BinaryTree.h BinaryTree.cpp BinaryNode.h BinaryNode.cpp

Executive.o: Executive.h Executive.cpp BinaryTree.h BinaryTree.cpp BinaryNode.h BinaryNode.cpp

BinaryTree.o: BinaryTree.h BinaryTree.cpp BinaryNode.h BinaryNode.cpp

BinaryNode.o: BinaryNode.h BinaryNode.cpp
	g++ -std=c++11 -g -Wall -c BinaryNode.cpp

clean:
	rm *.o Movie
