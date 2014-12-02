/*
Nick McComb CS163
1/22/2013
Assignment 1

REFERENCE DIFFERENT CAPITALIZATIONS

*/


#include "mapping.h"


//Prototypes
bool manager(menuType & menu, mappingType & map);    //Manages the program and the menu class. It is located in this file
                                                     //because the class had to be declared before it could be used in a prototype


int main()
{
  srand(time(0)); //Seeds the rand() function
  menuType menu;  //Declare the menu type

  mappingType map;

  while(manager(menu,map));   //The main executing loop

  return 0;
}


bool manager(menuType & menu, mappingType & map)
{
  menu.disp();
  menu.choose();
  menu.process(map);

  return menu.cont();
}



//Basic general-purpose functions that can be used by any other function
//General Purpose functions have a different style of notation, they use underscores instead of capitalization

//Returns true if a y (upper or lower) is passed to it
bool is_y(char ch)
{
  if(toupper(ch) == 'Y')
    return true;
  return false;
}

//Reads in an integer and removes the delimiter
void read_int(char prompt[], int & number)
{
  cout << prompt;
  cin >> number;
  cin.ignore(100,'\n');
}

//Reads in an array of characters and removes the delimiter
void read_array(char prompt[], char array[], int size)
{
  cout << prompt;
  cin.get(array, size, '\n');
  cin.ignore(100,'\n');
}

//Reads in a character and removes the delimiter
void read_char(char prompt[], char & ch)
{
  cout << prompt;
  cin >> ch;
  cin.ignore(100,'\n');
}
