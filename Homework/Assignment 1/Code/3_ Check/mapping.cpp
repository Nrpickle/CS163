/*
Nick McComb CS163
1/22/2013
Assignment 1
*/

#include "mapping.h"


dataType::dataType()
{
  valid = true;    //Data is initally not deleted  NEED TO CHANGE TO FALSE, SET TRUE LATER
  name = NULL;
  type = NULL;    
}

dataType::~dataType()
{
  delete [] name;  //Deallocates the memory for the name
  delete [] type;  //Deallocates the memory for the type
}

node::node()
{
  next = NULL;     //Initalizes the next pointer to null
  data = new dataType [NODE_ARRAY_SIZE];  //Creates an array of data, which is defined in a constant
}

node::~node()
{
  delete [] data;  //Deletes the dynamic array of data in the node
}


mappingType::mappingType()
{
  head = NULL;  //Sets the head pointer to be initiaally NULL
  count = 0;    //Initalize the count to be at 0, or the inital piece of data
  nodeNum = 0;  //Initializes the number of nodes to 0
  appendNode(); //Creates an inital node for the frst data to go into
                //Also ensures that head is not NULL
}

//Default destructor for the mapping type
mappingType::~mappingType()
{
  node * temp;      //Creates a temp variable to store the next spot in the list

  while(head)       //Loops until head is null, or the end of the lst
  {
    temp = head->next; //Stores the next item in the list
    delete head;    //Deletes head, and calls the desctuctor for data,
                    //which deletes the dynamic memory for the data
    head = temp;    //Moves head 'ahead'
  } 
  
  count = 0;        //Set the count to 0
  nodeNum = 0;      //Set the number of nodes to 0
}


//Insert a new node
//Return messages
  //1 - Created new list
  //2 - Added to end of list
int mappingType::insertItem(const dataType & newData)
{
  int status = 0;       //Initalize it as failed
  int len = 0;          //Used to 'measure' arrays

  if(count - ((nodeNum - 1) * NODE_ARRAY_SIZE) > (NODE_ARRAY_SIZE - 1))    //If the current node has run out 
                                                                           //of space
     appendNode();      //Append a new node
  
  int traversal = count / NODE_ARRAY_SIZE;   //Determines the about of nodes it is necessary to traverse
  int arrayIndex = count % NODE_ARRAY_SIZE;  //Determines which member of the array of data in
                                             //the target node we want to copy to
  //Positioning of current
  node * current  = head;             //Creates a copy of head in a variable called 'current'
  for(int i = 0; i < traversal; ++i)  //Traverse current to correct node to insert
    current = current->next;  //Traversal

  //Copies Name
  len = strlen(newData.name); 
  current->data[arrayIndex].name = new char [len + 1];
  strcpy(current->data[arrayIndex].name,newData.name);
  //Copies Type
  len = strlen(newData.type);
  current->data[arrayIndex].type = new char [len + 1];
  strcpy(current->data[arrayIndex].type,newData.type);
  //Copies Memory location
  current->data[arrayIndex].memoryLocation = newData.memoryLocation;

  ++count;              //Increments the count, so that the next item can 
                        //be inserted propertly
  return 1;             //Returns "Successful"
}

//This function appends a node onto the end of the linear linked list
void mappingType::appendNode()
{
  node * temp = new node;
  temp->next = NULL;           //Node is going to be appended at end

  if(!head)                    //If head is NULL, insert at head
    head = temp;      
  else                         //Else, traverse to the end
  {
    node * current = head;     //Create a new current pointer
    while(current->next)       //Traverse to the end
      current = current->next;
    current->next = temp;      //Append the temp node at the end
  }
  ++nodeNum;                   //Increase the number of nodes
}



//Return messages
  //0 - List is empty
  //1 - List is not empty
int mappingType::dispAll()
{

  int traversal = 0;                  //The amount of nodes that are needed to be traversed
  int prevTraversal = 0;              //The array from the last iteration, if no traversal is neccessary,
                                      //Stay the same
  int arrayIndex = 0;                 //The number within the array in the node to access

  node * current  = head;             //Sets up a current variable that starts at head

  for (int i = 0; i < count; ++i)
  {
    traversal = i / NODE_ARRAY_SIZE;  //Calculates the amount of nodes that are necessary to traverse
    arrayIndex = i % NODE_ARRAY_SIZE; //Calculates the index of the array inside the node
//   cout << "--Location:" << traversal << "-" << arrayIndex << " " << endl;  //Very useful for debugging

    cout << "Id: " << i << endl;      //Outputs the current object's id
    if(prevTraversal != traversal)    //Reduces unnecessary traversal
    {
      current = current->next;        //Traverses
      prevTraversal = traversal;      //Sets the previous traversal check to the current traversal
    }

    //At this point,  current is pointing to the desired node	
    if(current->data[arrayIndex].valid)  //If the current array is not "deleted"
    {
      cout << "--Name: " << current->data[arrayIndex].name << endl;              //Outputs the name
      cout << "--Type: " << current->data[arrayIndex].type << endl;              //Outputs the Type
      cout << "--MemLoc: " << current->data[arrayIndex].memoryLocation << endl;  //Outputs the memory loc
    }
    else                              //Else it has been deleted
      cout << "DELETED" << endl;      //Output Deleted instead of information DEBUGGING
  
    cout << endl;                     //End line for spacing
  }

  return 1;                           //Return success
}



//Function to "delete" an item
//This function takes a passed id and then searches for that id,
//if it is found, then the valid boolean in the data is set to false
//and then that piece of data will not be displayed when display all is called
  //Return numbers
    //0 - Successful
    //1 - Too Low
    //2 - Too High


int mappingType::deleteItem(int id)
{
  int status = 0;   //Holds the status of the function

  if (id > count)   //If the passed number is higher than any existing number, return that
    return 2;

  if (id < 0)       //If the passed number is lower than 0, it is too low
    return 1;

  node * current = head;

  int traversal = id / NODE_ARRAY_SIZE;
  int arrayIndex = id % NODE_ARRAY_SIZE;
  for(int i = 0; i < traversal; ++i)
    current = current->next;
  current->data[arrayIndex].valid = false;

  return 0;
}

