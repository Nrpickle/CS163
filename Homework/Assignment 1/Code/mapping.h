/*
Nick McComb CS163
1/22/2013
Assignement 1

*/



#include <iostream>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;


//Constants
const int STD_ARRAY = 51;
const int NODE_ARRAY_SIZE = 5;
const int TEMP_SIZE = 151;


//Prototypes

//General Purpose Prototypes
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes the 
                                                         //delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimeter


struct dataType 
{
  dataType();  //Default constructor
  ~dataType(); //Default destructor
  bool valid;  //Whether this piece of data has been 'deleted'
  char * name; //Dynamic array to hold the name of the item
  char * type; //Dynamic array to hold the type of the item
  int memoryLocation; //Stores the made up memory location
};

struct node 
{
  node();           //Default constructor
  ~node();          //Default destructor
  dataType * data;  //Array that holds the data

  node * next;
};


class mappingType 
{
  public:
    mappingType();          //Default constructor
    ~mappingType();         //Default destructor
    int dispAll();          //Displays all current data
    int insertItem(const dataType & newData);
    int deleteItem(int id); //Makes the passed item not valid
  private:
    void appendNode();
    node * head;    //Head pointer
    int nodeNum;    //Current number of nodes in the system
    int count;      //Current 'index' of the next item to be added
};



//Class that runs the client application
class menuType
{
  public:
    void disp();       //Displays the menu choices
    void choose();     //Prompts the user for their choice, and returns it
    void process(mappingType & map);    //~~Manages interface between the ADT and the application
    bool cont();       //Determines whether the manager function should return true or false 
  private:
    int addNew(mappingType & map);
    bool contBool;
    int choice;
};
