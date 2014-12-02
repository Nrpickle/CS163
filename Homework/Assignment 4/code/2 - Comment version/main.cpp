/*
Nick McComb   CS163

Assignment #4
*/

#include "tree.h"


//General Prototypes that are usable througout the entire program
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
int return_int(char prompt[]);                //Reads in a number and returns it
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes
                                                    //the delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimiter



//Prototypes for functions used in main.cpp only
bool manager(menuType & menu, treeClass & topic, treeClass & course);   //Manages the main 
                                   //repeating functionality of the program


int main()
{
  srand (time(NULL)); //Initialize random seed
  menuType menu;
  
  treeClass topic;
  treeClass course;

  while(manager(menu, topic, course));  //The main loop of the program

  return 0;
}

//This function manages the program
//It displays the menu, asks the user to choose their selection
//Then acts based on what they chose
bool manager(menuType & menu, treeClass & topic, treeClass & course)
{
  menu.disp();
  menu.choose();
  menu.process(topic, course);
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

int return_int(char prompt[])
{
  int num;
  cout << prompt;
  cin >> num;
  cin.ignore(100,'\n');
  return num;
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



