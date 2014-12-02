/*
Nick McComb CS163
1/22/2013
Assignment 1

This file contains the implementation code for the menu class that controls the client program of assignment 1
*/


#include "graph.h"


//Manages the output of the menu options
void menuType::disp()
{
  cout << endl;
  cout << "-----------" << endl;
  cout << "-Main Menu-" << endl;
  cout << "-----------" << endl;
  cout << "1: Add an intersection" << endl;
  cout << "2: Display all items" << endl;
  cout << "3: Add a street (connect two intersections)" << endl;
  cout << "4: Get connections from an intersection" << endl;
  cout << "5: Output all entries" << endl;
  cout << "6: Exit program" << endl;
  cout << "7: Traverse Depths First" << endl;
}

//Sets the choice variable to the users desired choice
void menuType::choose()
{
  choice = 999; //Default error number
  read_int("Please enter your choice: ", choice);  //Reads in the choice from the user
  cout << endl;
}

//Determines if the choice is 6, if so, return false to exit the program
bool menuType::cont()
{
  if(choice == 6)
    return false;  //If the user specified to exit, exit
  return true;     //Else, continue
}

//"Processes" the choice that the user made
//It taktes the inputted choice variable and puts it in a switch
//structure, which then takes the appropriate action
void menuType::process(graphType & graph)
{
  int status = 0;  //Default fail status

  int number;      //Multipurpose number variable
  switch (choice)
  {
    case 1:  //Add a new number
      cout << "Add New Intersection" << endl;

      status = addNew(graph);
      if(status != -1) 
        cout << "Item Added Successfully" << endl;
      break;
    case 2:  //Displays all numbers
      cout << "Display all numbers" << endl << endl;
      status = graph.dispInter();
      if (!status)
        cout << "There are no entries!" << endl;
      break;
    case 3:  //Add vertex
	  cout << "Add street" << endl;
	  status = addStreet(graph);
	  if(!status)
	    cout << "The ID's entered were not valid" << endl;
      break;
    case 4:  //Verticies
	  status = adjVert(graph, return_int("ID: "));
      break;
    case 5:  //Display all entries (Depth First Search)
	  status = graph.dispAll(return_int("ID: "),0);
      break;
    case 6:  //Exit program
      cout << "Exiting program" << endl << endl;
      break;
	case 7:
	  cout << "Display all using Depths First Traversal" << endl;
	  status = graph.dispAllDFS(return_int("ID: "),0);
	  break;
	case 777:
	  status = testSuite(graph);
	  break;
    default: //Default
      cout << "That is not a valid choice. Please try again" << endl;
      break;
  }
}


//Searches for the data in the ADT
int menuType::search(mappingType & map)
{
  int status = 0;
  int number = 0;

  read_int("Id: ", number);   //Reads in the desired ID from the user
  dataType foundData;  //Declares a temporary hold struc
  status = map.search(number, foundData);  

  if(!status)  //If it has been found succesfully
  {
    cout << "--Name: " << foundData.name << endl;              //Outputs the name
  }


  return status;
}



//Adds a new piece of data
//This function inputs all of the data, then passes
//The completed data structure to the ADT for copying
int menuType::addNew(graphType & graph)
{
  int status = -1;
  
  char * name = new char[TEMP_SIZE];

  /*
  cout << "Please, enter a number or a word: ";
  char c = cin.peek();

  if ( (c >= '0') && (c <= '9') )
  {
    int n;
    cin >> n;
    cout << "You entered the number: " << n << '\n';
  }
  else
  {
    read_array("Name: ", name, TEMP_SIZE);
    cout << "You entered the word: " << name << '\n';
  }
  */
  
  read_array("Name: ", name, TEMP_SIZE);
  status = graph.insertInter(name);  //Insert the data into the ADT

  cout << name << " assigned ID " << status << endl;
  
  delete [] name;
  
  return status;
}

//This function handles the client application's role in inserting a new street into the graph ADT (an edge)
int menuType::addStreet(graphType & graph)
{
  int status = 0;
  
  insertInfo info;
  edgeData newData;
  
  read_int("Int 1: ", info.id1);
  read_int("Int 2: ", info.id2);
  newData.stName = new char[TEMP_SIZE];  //Allocated to temp size because the final stored value will be cut down to the correct length when it is copied
  read_array("Street Name: ", newData.stName, TEMP_SIZE);
  read_int("Lenth of Street (miles): ", newData.dist);
  read_int("Difficulty (1-5): ", newData.difficulty);
  
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
  return status;
}

//This is a test suite that will connect nodes in a specified order. It requries 8 nodes to be allocated to work correctly.
int menuType::testSuite(graphType & graph)
{
  int status = 0;
  
  insertInfo info;
  edgeData newData;
  
  newData.stName = new char[TEMP_SIZE];
  strcpy(newData.stName, "Street Name");
  
  
  info.id1 = 0;
  info.id2 = 1;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;

  info.id1 = 0;
  info.id2 = 2;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;

  info.id1 = 0;
  info.id2 = 3;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;

  info.id1 = 1;
  info.id2 = 3;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  info.id1 = 1;
  info.id2 = 4;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  info.id1 = 2;
  info.id2 = 4;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  info.id1 = 3;
  info.id2 = 5;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  info.id1 = 5;
  info.id2 = 7;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  info.id1 = 4;
  info.id2 = 6;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  info.id1 = 6;
  info.id2 = 7;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  info.id1 = 4;
  info.id2 = 5;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  info.id1 = 3;
  info.id2 = 7;
  status = graph.insertStreet(info, newData);
  if(status)
    cout << "Connected --" << info.name1 << "-- to --" << info.name2 << "--" << endl;
	
  return status;
}

//This function outputs all of the adjac
//the returned data is indexed 1, with index 0 being the searched vertex
int menuType::adjVert(graphType & graph, int id)
{
  dataType * data;  //Pointer that will point to the returned data
  
  int number;       //This number handles the number of different direction
  number = graph.adjVert(id, data);  //Retrieves 
  
  if(number > 0)
  {
    cout << "You can go " << number;
	if(number > 1)
	  cout << " different directions";
	else
	  cout << " direction";
	cout << " from " << data[0].name << ":" << endl;
    for(int i = 1; i < number + 1; ++i)
	{
	  cout << data[i].name << endl;   //Outputs all of the names of the adjacent verticies
	}
  }
  else if (!number)
  {
    cout << "There are no roads leading away from this intersection." << endl;
  }
  else
  {
    cout << id << " is not a valid ID. Please try again." << endl;
  }
  
  delete [] data;  //Dealloactes the dynamically allocated data
  return number;   //Returns the number of matches
}



