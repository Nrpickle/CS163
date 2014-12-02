all: tree

tree: main.o menu.o tree.o
	g++ main.o menu.o tree.o

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

tree.o: tree.cpp
	g++ -c tree.cpp
