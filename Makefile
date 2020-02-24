# movie: main.o Executive.o HashTable.o User.o
# 	g++ -std=c++11 -g -Wall main.o Executive.o HashTable.o User.o -o movie
#
# main.o: main.cpp Executive.h Executive.cpp HashTable.h HashTable.cpp User.h User.cpp
# 	g++ -std=c++11 -g -Wall -c main.cpp
#
# Executive.o: Executive.h Executive.cpp HashTable.h HashTable.cpp User.h User.cpp
# 	g++ -std=c++11 -g -Wall -c Executive.cpp
#
# HashTable.o: HashTable.h HashTable.cpp User.h User.cpp
# 	g++ -std=c++11 -g -Wall -c HashTable.cpp

Movie.o: Movie.h
	g++ -std=c++11 -g -Wall -c Movie.cpp

clean:
	rm *.o
