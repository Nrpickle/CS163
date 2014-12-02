/*
Nick McComb CS163
Assignement 5

The main header file that declares an ADT and the Client Program
*/





//Constants
const int STD_ARRAY = 51;
const int NODE_ARRAY_SIZE = 5;  //Sets the size of the arrays in nodes
const int TEMP_SIZE = 151;      //Sets the temporary size of the dynamically allocated arrays
const int TEMP_DESC_SIZE = 301; //Sets the temporary size of the dynamically allocated description array
                                  //that are used to input data before the size is known
//General Purpose Prototypes
bool is_y(char ch);                           //Returns true if the passed character is y (upper or lower)
void read_int(char prompt[], int & number);   //Reads in a number into the passed integer
int return_int(char prompt[]);                //Returns a prompted int
void read_array(char prompt[], char array[], int size);  //Reads in an array of characters and removes the 
                                                         //delimiter
void read_char(char prompt[], char & ch);     //Reads in a character and removes the delimeter

struct edgeNode;  //Edgenode Prototype

//This structure holds all of the data
struct dataType 
{
  dataType();  //Default constructor
  ~dataType(); //Default destructor
  int copy(const dataType & recivData);
  bool valid;  //Whether this piece of data has been 'deleted'
  char * name; //Dynamically allocated array to hold the name of the item
  int visited;
  int count;
  edgeNode * head;
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
    int insertItem(char * name); //Inserts the passed item
    int search(int id, dataType & foundData); //Looks up the passed id, and 'returns' the data
	int edit(int id, dataType & newData);
    int deleteItem(int id); //Makes the passed item not valid
    int deleteAll();        //Executes a variant of the destructor
                            //to reset the ADT
	int clearVisitAll();
  private:
    void appendNode();
    node * head;    //Head pointer
    int nodeNum;    //Current number of nodes in the system
    int count;      //Current 'index' of the next item to be added
};

class graphType;  //Graphtype prototype

//Class that runs the client application and manages the ADT
class menuType
{
  public:
    void disp();       //Displays the menu choices
    void choose();     //Prompts the user for their choice, and returns it
    void process(graphType & graph);    //~~Manages interface between the ADT and the application
    bool cont();       //Determines whether the manager function should return true or false 
  private:
    int addNew(graphType & graph);  //Gets the information for a new piece of data
    int search(mappingType & map);                   //Handles the the searching of the ADT 
                                    //then passes it to the ADT
	int addStreet(graphType & graph);
	int adjVert(graphType & graph, int id);
	int testSuite(graphType & graph);
    bool contBool;     //Determines if the entire program will continue
    int choice;        //Stores the user's menu choice
};

