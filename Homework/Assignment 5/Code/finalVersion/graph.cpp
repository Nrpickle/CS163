/*
Nick McComb CS163
Assignment #5

*/

#include "graph.h"
//Deafult constructor
edgeData::edgeData()
{
  stName = NULL;
  difficulty = -1;
  dist = -1;
}

//Default destructor
edgeData::~edgeData()
{
  delete [] stName;
}

//Copies the passed data structure into the current data struct
int edgeData::copy(const edgeData & recivData)
{
  if(stName)
    delete [] stName;
  
  int len = strlen(recivData.stName);
  stName = new char [len + 1];
  strcpy(stName, recivData.stName);
  
  difficulty = recivData.difficulty;
  dist = recivData.dist;
}

//Initialized the pointers to NULL
insertInfo::insertInfo()
{
  name1 = NULL;
  name2 = NULL;
}

//Deletes any dynamic memory that has been allocated to the struct
insertInfo::~insertInfo()
{
  delete [] name1;
  delete [] name2;
}

//Inserts a new entry into the flexible array that makes up the adjacency list
//This function passes the passed array of chaceters straight into the private adjacency list
int graphType::insertInter(char * name)
{
  return adjList.insertItem(name);
}

//Calls the display portion of the adjacency list, whgich displays all of avalible ID numbers and the names that are associated with them
int graphType::dispInter()
{
  return adjList.dispAll();
}

//Passes the passed information into the edge list, after retrieving the head pointers from inside the adjacency list. This function then changes the head pointers, and sends the new values back into adjacency list
//Fail state = 0
int graphType::insertStreet(insertInfo & info, const edgeData & newData)
{
  int id1 = info.id1;  //Retrieves the passed in values from the insertInfo data
  int id2 = info.id2;    //structures, and passes them into local variables
  int status1 = 0;     //Holds the status from the first retrival
  int status2 = 0;     //Holds the status from the second retrival
  int validID = 0;     //Used as a boolean to determine if the IDs are valid
  dataType data1;      //Data structures that hold the retrieved data
  dataType data2;        //while it works with it in the local function
  
  if(id1 == id2)  //This would create a circular loop, return
    return 0;
  
  status1 = adjList.search(id1,data1);  //Retrives the data from the adjacency list
  status2 = adjList.search(id2,data2);  

  if(!status1 && !status2)
    validID = 1;

  if(validID)
  {
	//Copies the retrieved names of the connection is is about to amke into the insertInfo struct so that the menu class can then output the names to the user
    info.name1 = new char[strlen(data1.name) + 1];
	strcpy(info.name1, data1.name);
    info.name2 = new char[strlen(data2.name) + 1];
	strcpy(info.name2, data2.name);

	edgeNode * temp = data1.head;   //Holds the about-to-be-old head pointer
	data1.head = new edgeNode;      //Creates a new ndoe
	data1.head->id = id2;           //Sets up the new connection
	data1.head->next = temp;        //Reconnects up the LLL that makes up the edge
	data1.head->data.copy(newData); //Copies the new edge data
	++data1.count;     //Increments the count of connections in the adjacency list

	adjList.edit(id1, data1);       //Updates the head pointer in the adjacency list
	
	adjList.clearVisitAll();        //Clears all of the visited flags for no reason
  }
  
  return validID;
}

//This function retrieves all of the adajacent verticies and returns them in an array of data that returns the vertex of the passed id as index 0, then all matches in addition to that, as the next pieces of data in the array.
int graphType::adjVert(int id, dataType * & data)
{
  dataType tempData;
  
  int status = adjList.search(id,tempData);  //Retrieves the vertex that is associated with the passed id
  
  if(!status)  //If it was found
  {
    data = new dataType [tempData.count + 1];  //Allocate a new dynamic array of dataTypes (verticies) that will be accessed by the calling function
	int index = 0;  //An index that is used to manage the location of inserted data into the array
	adjList.search(id,data[index++]);  //Inserts the base vertex
	edgeNode * current = tempData.head;
	while(current)  //Loop through all matches
	{
	  adjList.search(current->id,data[index++]);  //Copies the data into the array
	  current = current->next;  //Traversal
	}
	return tempData.count;  //Returns the amount of matches
  }
  else
    return -1;
  
}

//Displays all of the information
//This recusive function displays all available paths from the passed variable
//The level integer is used for spacing only, and increases the level does
int graphType::dispAll(int id, int level)
{
  dataType data;  //These structs are used to sure data
  edgeData edge;
  
  int status = adjList.search(id,data);  //Retrieves the desired data from the adjacency list
  
  if(!status)  //If it was found
  {
	edgeNode * current = data.head;  //Copy the head pointer into a local variable
	data.visited = 1;  //Set the node as visited
	adjList.edit(id,data);  //Update the node in the adjacency list (to indicate visited)
	for(int i = 0; i < level; ++i)   //Spacing
	  cout << "  ";
	cout << "||" << data.name << " is connected to " << data.count << " intersection(s): " << endl;  //Output the information
	while(current)  //Displays all of the connected nodes
	{
	  for(int i = 0; i < (level * 2) + 1; ++i)
        cout << "-";
      cout << "Street: " << current->data.stName << endl;
	  for(int i = 0; i < (level * 2) + 1; ++i)
        cout << "-";
      cout << "Length: " << current->data.dist << " miles" << endl;
	  for(int i = 0; i < (level * 2) + 1; ++i)
        cout << "-";
      cout << "Difficulty: " << current->data.difficulty << endl;
	  dispAll(current->id, level + 1);
	  current = current->next;
	}
  }
  
  if(level == 0)  //If finished,
    adjList.clearVisitAll();   //Clear all of the visisted flags
  return status;
}

//Essentially the same algorithm as above, except it does not revisit previous nodes, displaying all nodes once, using Depth First Traversal.
int graphType::dispAllDFS(int id, int level)
{
  dataType data;
  
  int status = adjList.search(id,data);
  if(!status && !data.visited)  //If it was found and it hasn't been visited
  {
	edgeNode * current = data.head;
	data.visited = 1;
	adjList.edit(id,data);
	for(int i = 0; i < level; ++i)
	  cout << "  ";
	cout << "||" << data.name << " is connected to " << data.count << " intersection(s): " << endl;
	while(current)
	{
	  dispAllDFS(current->id, level + 1);
	  current = current->next;
	}
  }
  
  if(level == 0)
    adjList.clearVisitAll();
  return status;
}

