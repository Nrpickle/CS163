/*
Nick McComb CS163

Assignment #5
*/

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <ctime>
#include "mapping.h"
using namespace std;


class mappingType;  //Mapping Type prototype

struct edgeData {
  edgeData();
  ~edgeData();
  int copy(const edgeData & recivData);  //Copies the passed data into the node
  char * stName;   //Holds the street nane
  int difficulty;  //Holds the difficulty on a 1-5 scale
  int dist;        //Holds the distance, unfortunately its an integer
};

struct edgeNode {
  int id;  //Vertex node to point to
  edgeData data;   //Holds the data that is in an edge
  edgeNode * next; //Points to the next node
};
      
//This struct is simply for reducing the amount of arguments that are required to pass to the insert function
struct insertInfo {
  insertInfo();
  ~insertInfo();
  int id1;       //Holds the id of the first target
  int id2;       //Holds the id of the second target
  char * name1;  //Holds the name of the first target
  char * name2;  //Holds the name of the second target
};

class graphType {
  public:
    int insertInter(char * start);   //Inserts into the adjacency list
	int insertStreet(insertInfo & info, const edgeData & newData);  //Inserts an edge into the graph
	int dispInter();  //Displays all of the different 'intersections'
	int adjVert(int id, dataType * & data);  //'Returns' an array of data containing information regarding any adjacent verticies to the passed id
	int dispAll(int id, int level = 0);    //Displays all nodes that are adjacent to the passed id; recursice
	int dispAllDFS(int id, int level = 0); //Essentially does the same as above, but it does not visit a node twice
  private:
    mappingType adjList;  //Holds the adjacency list
};

