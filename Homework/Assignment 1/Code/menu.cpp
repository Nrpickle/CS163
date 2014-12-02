v /*
Nick McComb CS163
1/22/2013
Assignment 1

This file contains the implementation code for the menu class that controls the client program of assignment 
1
*/


#include "mapping.h"


//Manages the output of the menu options
void menuType::disp()
{
  cout << endl;
  cout << "-----------" << endl;
  cout << "-Main Menu-" << endl;
  cout << "-----------" << endl;
  cout << "1: Add new Number" << endl;
  cout << "2: Display all Numbers" << endl;
//Not yet implemented
//  cout << "3: Remove a number" << endl;
//  cout << "4: Lookup a number" << endl;
//  cout << "5: Remove all entries" << endl;
  cout << "6: Exit program" << endl;
}

//Sets the choice variable to the users desired choice
void menuType::choose()
{
  choice = 999; //Default error number
  read_int("Please enter your choice: ", choice);
  cout << endl;
}

//Determines if the choice is 6, if so, return false to exit the program
bool menuType::cont()
{
  if(choice == 6)
    return false;  //If the user specified to exit, exit
  return true;     //Else, continue
}


void menuType::process(mappingType & map)
{
  cout << "--Processing Data" << endl;
  int status = 0;  //Default fail status


  //Debugging
    int number;      //Number for input
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
        cout << "List is empty!" << endl;
      break;
/*
    case 3:  //Remove a number
      cout << "Remove a number" << endl;
      status = map.deleteItem(2);
      if(!status)
        cout << "Successful Deletion" << endl;
      else if (status == 1)
        cout << "There are no items with id's below 0." << endl;
      else if (status == 2)
        cout << "There are no id's with that high of a number" << endl;
      break;
*/
    case 6:  //Exit program
      cout << "Exiting program" << endl << endl;
      break;
    default: //Default
      cout << "That is not a valid choice. Please try again" << endl;
      break;
  }
}



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

  status = map.insertItem(newData);  //Insert the data into the ADT

  return status;
}
