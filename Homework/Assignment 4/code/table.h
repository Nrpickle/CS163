/*
Nick McComb CS163
*/

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include "menu.h"
using namespace std;

const int TEMP_SIZE = 151;  //This is the size of the basic temporary input array

//General Prototypes for functions that are usable througout the entire program
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes
                                                    //the delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimiter
