/*
Nick McComb CS163
1/22/2013
Assignment 1

Implements the Abstract Data Type
*/

#include "graph.h"

//Default constructor for dataType
dataType::dataType()
{
  valid = true;    //Data is initally not deleted  NEED TO CHANGE TO FALSE, SET TRUE LATER
  name = NULL;
  head = NULL;
  visited = 0;     //Boolean
  count = 0;
}

//The destructor for dataType
dataType::~dataType()
{
  delete [] name;  //Deallocates the memory for the name
}


int dataType::copy(const dataType & recivData)
{
  if(name)
    delete [] name;
  
  int len = strlen(recivData.name);
  name = new char [len + 1];
  strcpy(name, recivData.name);
  
  head = recivData.head;
  visited = recivData.visited;
  count = recivData.count;
}

//Constructor for a node
node::node()
{
  next = NULL;     //Initalizes the next pointer to null
  data = new dataType [NODE_ARRAY_SIZE];  //Creates an array of data, which is defined in a constant
}

//Destructor for a node - deallocates memory
node::~node()
{
  delete [] data;  //Deletes the dynamic array of data in the node
}


//Constructor for mappingType
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
int mappingType::insertItem(char * name)
{
  int status = -1;       //Initalize it as failed
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
  len = strlen(name); 
  current->data[arrayIndex].name = new char [len + 1];
  strcpy(current->data[arrayIndex].name, name);

  ++count;              //Increments the count, so that the next item can 
                        //be inserted propertly
  return count - 1;             //Returns "Successful"
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


//Searches for a passed id and then returns it via
//the data type that was passed by reference to the function
//Returns messages
  //0 - Found data member
  //1 - No such position
  //2 - Entry has been deleted
int mappingType::search(int id, dataType & foundData)
{
  int traversal = id / NODE_ARRAY_SIZE;   //Determines the about of nodes it is necessary to traverse
  int arrayIndex = id % NODE_ARRAY_SIZE;  //Determines which member of the array of data in
                                          //the target node we want to copy from
  int len = 0;                            //Used for 'measuring' arrays
  if (id > (count - 1))   //If the passed number is higher than any existing number, return that
    return 1;
  if (id < 0)       //If the passed number is lower than 0, it is too low
    return 1;

  node * current = head;

  for(int i = 0; i < traversal; ++i)       //Traverse to the correct node
    current = current->next;

  if(current->data[arrayIndex].valid)      //If the current array is not "deleted"
  {
    //Copies Name
	foundData.copy(current->data[arrayIndex]);
    return 0;
  }
  else                                                  //Else it has been deleted
    return 2;;      //Output Deleted instead of information
}



//Returns messages
  //0 - Found data member
  //1 - No such position
  //2 - Entry has been deleted
int mappingType::edit(int id, dataType & newData)
{
  int traversal = id / NODE_ARRAY_SIZE;   //Determines the about of nodes it is necessary to traverse
  int arrayIndex = id % NODE_ARRAY_SIZE;  //Determines which member of the array of data in
                                          //the target node we want to copy from
  int len = 0;                            //Used for 'measuring' arrays
  if (id > (count - 1))   //If the passed number is higher than any existing number, return that
    return 1;
  if (id < 0)       //If the passed number is lower than 0, it is too low
    return 1;

  node * current = head;

  for(int i = 0; i < traversal; ++i)       //Traverse to the correct node
    current = current->next;

  if(current->data[arrayIndex].valid)      //If the current array is not "deleted"
  {
    current->data[arrayIndex].head = newData.head;
	current->data[arrayIndex].count = newData.count;
	current->data[arrayIndex].visited = newData.visited;
    return 0;
  }
  else                                                  //Else it has been deleted
    return 2;;      //Output Deleted instead of information
}



//Return messages
  //0 - List is empty
  //1 - List is not empty
int mappingType::dispAll()
{
  if(!count)                          //If there are no entries, return 0
    return 0;

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

    if(prevTraversal != traversal)    //Reduces unnecessary traversal
    {
      current = current->next;        //Traverses
      prevTraversal = traversal;      //Sets the previous traversal check to the current traversal
    }

    //At this point,  current is pointing to the desired node	
    if(current->data[arrayIndex].valid)  //If the current array is not "deleted"
    {
      cout << "Id: " << i << endl;      //Outputs the current object's id
      cout << "--Name: " << current->data[arrayIndex].name << endl;              //Outputs the nam
      cout << endl;                                                              //End line for spacing
    }
  
//    cout << endl;                     //End line for spacing
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

  if (id > (count - 1))   //If the passed number is higher than any existing number, return that
    return 2;

  if (id < 0)       //If the passed number is lower than 0, it is too low
    return 1;

  node * current = head;

  int traversal = id / NODE_ARRAY_SIZE;
  int arrayIndex = id % NODE_ARRAY_SIZE;
  for(int i = 0; i < traversal; ++i)       //Traverse to the correct node
    current = current->next;
  current->data[arrayIndex].valid = false; //'Delete' the correct entry

  return 0;
}


//Almost the same as the destructor, this function deallocates all of the memory,
//that has been allocated. The difference is that this then appends a node to the end
//to prepare for more data to be entered
//Returns the number of entries delted
int mappingType::deleteAll()
{
  int numEntries = 0; //Records the number of entries
  node * temp;      //Creates a temp variable to store the next spot in the list

  while(head)       //Loops until head is null, or the end of the lst
  {
    temp = head->next; //Stores the next item in the list
    delete head;    //Deletes head, and calls the desctuctor for data,
                    //which deletes the dynamic memory for the data
    head = temp;    //Moves head 'ahead'
    ++numEntries;   //Increments the number of entries deleted
  }

  count = 0;        //Set the count to 0
  nodeNum = 0;      //Set the number of nodes to 0

  appendNode();     //Resets the structure, adds a new node to add data to
  return numEntries;
}


int mappingType::clearVisitAll()
{
  int id = count - 1;
  int status = 0;   //Holds the status of the function

  if (id > (count - 1))   //If the passed number is higher than any existing number, return that
    return 2;

  if (id < 0)       //If the passed number is lower than 0, it is too low
    return 1;

  node * current = head;

  int traversal = id / NODE_ARRAY_SIZE;
  int arrayIndex = id % NODE_ARRAY_SIZE;
  for(int i = 0; i < traversal; ++i)       //Traverse to the correct node
  {
    for(int innerIndex = 0; innerIndex < NODE_ARRAY_SIZE; ++innerIndex)
	  current->data[innerIndex].visited = false;
    current = current->next;
  }
  for(int innerIndex = 0; innerIndex < arrayIndex; ++innerIndex)
	  current->data[innerIndex].visited = false;

  return 0;
}


