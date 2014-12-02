/*
Nick McComb	CS163
2/12/2013

Assignment #2

This is the main header file that connects all of the other files
It also holdes the prototypes for the general purpose functions, which use
a different type of notation. They use underscores to denote changes in words
which signifies that they are GP functions, and are not specific to any class
*/

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <ctime>
#include "queue.h"
#include "stack.h"
#include "menu.h"
using namespace std;

//Constants
//These are all program-wide constants that are used throughout the program

const int TEMP_SIZE = 151;  //This is the size of the basic temporary input array



//General Prototypes that are usable througout the entire program
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
void array(char prompt[], char array[], int size);  //Reads in an array of characters and removes
						    //the delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimiter

