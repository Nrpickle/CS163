all: graph

graph: main.o menu.o graph.o mapping.o
	g++ main.o menu.o graph.o mapping.o

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

graph.o: graph.cpp
	g++ -c graph.cpp

mapping.o: mapping.cpp
	g++ -c mapping.cpp