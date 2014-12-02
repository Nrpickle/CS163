all: tree

tree: main.o menu.o graph.o
	g++ main.o menu.o graph.o

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

graph.o: graph.cpp
	g++ -c graph.cpp
