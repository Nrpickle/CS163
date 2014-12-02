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

struct courseData {
  courseData();
  ~courseData();
  //Search Keys
  char * course;
  char * topic;
  //Additional Information
  char * directory;
  int year;
};

//Datatype
class courseClass {
  public:
    courseClass();
    void insertCourse(char newCourse[]);
    void insertTopic(char newTopic[]);
	void insertDirectory(char newDirectory[]);
    int getTopic(char * & foundTopic);  //Pass in a NULL pointer, returns a pointer to a newly allocated piece of memory
    int getCourse(char * & foundCourse);  //Pass in a NULL pointer, returns a pointer to a newly allocated piece of memory
	int getDirectory(char * & foundDirectory);  //Pass in a NULL pointer, returns a pointer to a newly allocated piece of memory
	
	int validData();  //Returns a true value if all of the data has information
  private:
    courseData data;
};


struct node {
  courseClass course;
  
  int data;
  
  node * left;
  node * right;
};



class treeClass
{
  public:
    treeClass();
    int insert(int data);
	int displayAll();
	int remove(int data);
  private:
    void addAtEnd(node * & root, int data);
	void display(node * root);
	int remove(node * root, int data); //Overloaded function
	node * root;
};












