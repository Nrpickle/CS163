/*
Nick McComb	CS163
2/4/2013

This is the main file, or the main hub of the program
*/

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <ctime>
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
