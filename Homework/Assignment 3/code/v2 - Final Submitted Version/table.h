/*
Nick McComb CS163

Assignment #3
2/21/2013

This is the main header file that brings the rest of the program together
*/

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <ctime>
#include "menu.h"
using namespace std;

const int TEMP_SIZE = 301;  //This is the size of the basic temporary input array
const int TABLE_SIZE = 13;  //The number of indexes in the arrays

//General Prototypes for functions that are usable througout the entire program
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes
                                                    //the delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimiter

//Contains the information that defines the command
struct commandType
{
  commandType();
  ~commandType();
  
  char * func;  //Defines the function of the command
  bool state;   //The state of the command
  char * rules; //Defines the rules of the command
};

//Node that handles the chaining in the hash table
//The key is stored in this node, while the information regarding the 
//command is stored in a seperate struct
struct node {
  node();
  ~node();
  char * key;            //Holds the search key that the node is associated with
  commandType command;   //Holds the information regarding the command
  node * next;           //Points to the next node
};

//Manages the hash table, this is the ADT
class tableType
{
  public:
    tableType();              //Default constructor
	~tableType();             //Default destructor
	int insert(char key[], const commandType & newCommand);  //Inserts a new node at the position
															 //that is calculated from the key
	int remove(char key[]);   //The entry with the key that is passed
	int retrieve(char key[], commandType & foundCommand);    //Searches for a passed key, and if it exists,
															 //returns the information via the passed struct
	//Debugging	
	int displayIndex(int targetIndex);  //Displays all of the keys that collide with the passed indexTarget
	int displayCounter(void);           //Outputs all of the information that is stored by the counter (the amount of collisions)
	void displayAll();                  //Displays all of the information in ther ADT
  private:
    void deleteLLL(node * & head);      //Deletes the passed linear linked list (sets head to NULL)
	void copyCommands(commandType & dest, const commandType & source); //Copies the commands struct that is passed to it (handles
																	   //the dynamically allocated memory)
	int hash(char key[]);     //The hash function
	node ** hashTable;        //Stores the array of head pointers
	int * counter;			  //Stores the amount of collisions at every index point
};

