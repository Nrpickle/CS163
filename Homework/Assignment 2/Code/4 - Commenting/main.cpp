/*
Nick McComb   CS163
2/12/2013

Assignment #2

Main Implementation File
This file contains the main() function and the most basic managing code
*/

#include "list.h"


//General Prototypes that are usable througout the entire program
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes
                                                    //the delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimiter



//Prototypes for functions used in main.cpp only
bool manager(menuType & menu, stackType & allAvatars);   //Manages the main 
                                   //repeating functionality of the program


int main()
{
  menuType menu;         //Creates an instance of the menu to manage the program

  stackType allAvatars;  //Creates the main controlling stack for the  rest of the program

  while(manager(menu,allAvatars));  //The main loop of the program

  return 0;
}

//This function manages the program
//It displays the menu, asks the user to choose their selection
//Then acts based on what they chose
bool manager(menuType & menu, stackType & allAvatars)
{
  menu.disp();
  menu.choose();
  menu.process(allAvatars);
  return menu.again();
}



//Basic general-purpose functions that can be used by any other function
//General Purpose functions (in this implementation) have a different style 
//of notation, they use underscores instead of capitalization

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



