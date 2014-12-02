/*
Nick McComb   CS163
2/5/2013

Assignment #2
*/

#include "list.h"


//General Prototypes that are usable througout the entire program
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes
                                                    //the delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimiter



//Prototypes for functions used in main.cpp only
bool manager(menuType & menu, queueType & queue);   //Manages the main repeating functionality of the program


int main()
{
  menuType menu;   //Creates an instance of the menu to manage the program

  queueType queue;

  while(manager(menu,queue));

  return 0;
}


bool manager(menuType & menu, queueType & queue)
{
  menu.disp();
  menu.choose();
  menu.process(queue);
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



