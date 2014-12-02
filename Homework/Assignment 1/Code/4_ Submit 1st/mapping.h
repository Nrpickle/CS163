/*
Nick McComb CS163
1/22/2013
Assignement 1

The main header file that declares the ADT and the Client Program
*/



#include <iostream>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;


//Constants
const int STD_ARRAY = 51;
const int NODE_ARRAY_SIZE = 5;  //Sets the size of the arrays in nodes
const int TEMP_SIZE = 151;      //Sets the temporary size of the dynamically allocated arrays
                                //that are used to input data before the size is known\
//General Purpose Prototypes
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes the 
                                                         //delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimeter

//This structure holds all of the data
struct dataType 
{
  dataType();  //Default constructor
  ~dataType(); //Default destructor
  bool valid;  //Whether this piece of data has been 'deleted'
  char * name; //Dynamic array to hold the name of the item
  char * type; //Dynamic array to hold the type of the item
  int memoryLocation; //Stores the made up memory location
};

//This strucure is the node that forms the LLL
struct node 
{
  node();           //Default constructor
  ~node();          //Default destructor
  dataType * data;  //Array that holds the data
  node * next;      //Points to the next node in the list
};


//This class is the ADT
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



//Class that runs the client application and manages the ADT
class menuType
{
  public:
    void disp();       //Displays the menu choices
    void choose();     //Prompts the user for their choice, and returns it
    void process(mappingType & map);    //~~Manages interface between the ADT and the application
    bool cont();       //Determines whether the manager function should return true or false 
  private:
    int addNew(mappingType & map);  //Gets the information for a new piece of data
                                    //then passes it to the ADT
    bool contBool;     //Determines if the entire program will continue
    int choice;        //Stores the user's menu choice
};
