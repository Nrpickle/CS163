/*
Nick McComb CS163
*/

#include <iostream>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <stdlib.h>    
#include <time.h>      
#include "menu.h"
using namespace std;

const int TEMP_SIZE = 151;  //This is the size of the basic temporary input array

//General Prototypes for functions that are usable througout the entire program
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
int return_int(char prompt[]);                //Reads in a number and returns it
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes
                                                    //the delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimiter

struct dataStruct {
  dataStruct();     //Default constructor
  ~dataStruct();    //Default destructor
  //Search Keys
  char * course;    //Points to the course title
  char * topic;     //Points to the topic title
  //Additional Information
  char * directory; //Points to the directory information
};

//Datatype
class dataClass {
  public:
    void insertCourse(char newCourse[]);
    void insertTopic(char newTopic[]);
	void insertDirectory(char newDirectory[]);
    int getTopic(char * & foundTopic);  //Pass in a NULL pointer, returns a pointer to a newly allocated piece of memory
    int getCourse(char * & foundCourse);  //Pass in a NULL pointer, returns a pointer to a newly allocated piece of memory
	int getDirectory(char * & foundDirectory);  //Pass in a NULL pointer, returns a pointer to a newly allocated piece of memory
	
	int output();
	int copy(dataClass & origData);  //Copys passed information into the function, deletes any existing information that has been stored in the class
	int validData();  //Returns a true value if all of the data has information
  private:
    int dataExists();
    dataStruct data;
};


struct node {
  node();            //Default constructor
  ~node();           //Default destructor
  void copyKeys(node * & recivData);  //Copies the keys of the node that is passed in as recivData into the calling node
  dataClass topic;   //The class that holds the data
  
  char * searchKey;  //Primary search key (relevant to the main organization of the lsit)
  char * altKey;     //Alternate key (so that when the user deletes an object while referencing another tree, it can be deleted in the current one as well
  
  node * left;       //Points to the left child
  node * right;      //Points to the right child
};



class treeClass
{
  public:
    treeClass();        //Default constructor
	~treeClass();       //Default destructor
    int insert(dataClass & newData, int keySelector);    //Inserts the passed data into the BST, and sets the search key as either the course or the topic basied on the value of key selector. 1 - Topic is primary, 2 - Course is primary
	int displayAll();   //Displays all of the contents in sorted order
	int remove(char * searchKey, int keySelector);            //Removes the passed searchKey based on the keySelector value (1 - searchKey, 2 - altKey)
	int retrieve(char * searchKey, dataClass * & foundData);   //Retrieves the data that is associated with the passed searchKey, or a failure value
	int getHeight();    //Returns the height of the tree
	void removeAll();   //Deletes all data from the tree
  private:
    void addAtEnd(node * & root, char * searchKey, dataClass & newData, int keySelector);   //Adds the passed data to the BST
	void display(node * root);  //Recursive function that displays all of the data in sorted order
	int remove(node * & root, char * searchKey, int keySelector); //Overloaded function (removes the selected node)
	void retrieve(node * root, char * searchKey, dataClass * & foundData, int & index);
	int countMatches(node * root, char * searchKey);  //Returns the number of matches to the passed searchLey in the tree
	int getHeight(node * root);     //Returns the height of the tree
	void removeAll(node * & root);  //Deletes all nodes
	node * root;  //Pointer the points to the root of the tree
};












