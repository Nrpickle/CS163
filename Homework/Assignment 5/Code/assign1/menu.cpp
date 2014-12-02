/*
Nick McComb CS163
1/22/2013
Assignment 1

This file contains the implementation code for the menu class that controls the client program of assignment 1
*/


#include "mapping.h"


//Manages the output of the menu options
void menuType::disp()
{
  cout << endl;
  cout << "-----------" << endl;
  cout << "-Main Menu-" << endl;
  cout << "-----------" << endl;
  cout << "1: Add item" << endl;
  cout << "2: Display all items" << endl;
  cout << "3: Remove a item" << endl;
  cout << "4: Lookup by id" << endl;
  cout << "5: Reset all data" << endl;
  cout << "6: Exit program" << endl;
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
void menuType::process(mappingType & map)
{
  int status = 0;  //Default fail status

  int number;      //Multipurpose number variable
  switch (choice)
  {
    case 1:  //Add a new number
      cout << "Add New Number" << endl;

      status = addNew(map);
      if(status) 
        cout << "Item Added Successfully" << endl;
      break;
    case 2:  //Displays all numbers
      cout << "Display all numbers" << endl << endl;
      status = map.dispAll();
      if (!status)
        cout << "There are no entries!" << endl;
      break;
    case 3:  //Remove a number
      cout << "Remove a number" << endl;
      read_int("Id: ", number);
      status = map.deleteItem(number);
      if(!status)
        cout << "Successful Deletion" << endl;
      else if (status == 1)
        cout << "There are no items with id's below 0." << endl;
      else if (status == 2)
        cout << "There are no id's with that high of a number." << endl;
      break;
    case 4:  //Lookup a number
      cout << "Lookup a number" << endl;
      status = search(map);
      if(status == 1)
        cout << "There is no entry with that id." << endl;
      if(status == 2)
        cout << "This entry has been deleted." << endl;
      break;
    case 5:  //Reset ADT
      cout << "Deleting all entries" << endl;
      status = map.deleteAll();
      if (status)
        cout << "Deletion successful." << endl;
      else
        cout << "There are no entries." << endl;
      break;
    case 6:  //Exit program
      cout << "Exiting program" << endl << endl;
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

  read_int("Id: ", number);
  dataType foundData;
  status = map.search(number, foundData);

  if(!status)  //If it has been found succesfully
  {
    cout << "--Name: " << foundData.name << endl;              //Outputs the name
    cout << "--Type: " << foundData.type << endl;              //Outputs the Type
    cout << "--MemLoc: " << foundData.memoryLocation << endl;  //Outputs the memory loc
    cout << "--Description: " << foundData.desc << endl;       //Outputs the description
  }


  return status;
}



//Adds a new piece of data
//This function inputs all of the data, then passes
//The completed data structure to the ADT for copying
int menuType::addNew(mappingType & map)
{
  int status = 0;

  dataType newData;

  //Name
  newData.name = new char[TEMP_SIZE];
  read_array("Name: ", newData.name, TEMP_SIZE);
  //Type
  newData.type = new char[TEMP_SIZE];
  read_array("Type: ", newData.type, TEMP_SIZE);
  //Memory Location
  newData.memoryLocation = rand() % 100000;   
  //Description
  newData.desc = new char[TEMP_DESC_SIZE];
  read_array("Description: ", newData.desc, TEMP_DESC_SIZE);

  status = map.insertItem(newData);  //Insert the data into the ADT

  return status;
}

