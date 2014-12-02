/*
Nick McComb CS163
1/22/2013
Assignment 1
*/

#include "mapping.h"


dataType::dataType()
{
  valid = true;
  name = NULL;
  type = NULL;
}

dataType::~dataType()
{
  delete [] name;
  delete [] type;
}

node::node()
{
  next = NULL;
  data = new dataType [NODE_ARRAY_SIZE];
}

node::~node()
{
  delete [] data;
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

/*
int mappingType::add(int dataNum)
{
  dataType newData;
  
  newData.num = dataNum;
  
  return insertNode(newData);
}
*/

//Insert a new node
//Return messages
  //1 - Created new list
  //2 - Added to end of list
int mappingType::insertItem(const dataType & newData)
{
  int status = 0;  //Initalize it as failed
  int len = 0;     //Used to 'measure' arrays

//Debugging section
 //   cout << "--Current Count: " << count << endl;

  //Tests if a new node is needed to be created
  if(count - ((nodeNum - 1) * NODE_ARRAY_SIZE) > (NODE_ARRAY_SIZE - 1))    // __ Need to make modular
     appendNode();
    cout << "--Current Nodes: " << nodeNum << endl;
  
  //Accessing the correct node
    cout << "--Access Information" << endl;
  
  int traversal = count / NODE_ARRAY_SIZE;
  int arrayIndex = count % NODE_ARRAY_SIZE;
  
   cout << "--Traversal:   " << traversal << endl;
   cout << "--Array Index: " << arrayIndex << endl;

  //Positioning of current
  node * current  = head;
  for(int i = 0; i < traversal; ++i)  //Traverse to correct node to insert
    current = current->next;

  //Name
  len = strlen(newData.name);
  current->data[arrayIndex].name = new char [len + 1];
  strcpy(current->data[arrayIndex].name,newData.name);
  //Type
  len = strlen(newData.type);
  current->data[arrayIndex].type = new char [len + 1];
  strcpy(current->data[arrayIndex].type,newData.type);
  //Memory location
  current->data[arrayIndex].memoryLocation = newData.memoryLocation;

  ++count;
  status = 1;

  return status;             //Returns the status
}


void mappingType::appendNode()
{
  node * temp = new node;
  temp->next = NULL;      //Node is going to be appended at end

  if(!head)  //if head is NULL, insert at head
  {
    head = temp;    
  }
  else       //Else, traverse to the end
  {
    node * current = head;     //Create a new current pointer
    while(current->next)       //Traverse to the end
      current = current->next;
    current->next = temp;      //Append the temp node at the end
  }
  ++nodeNum;
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
      current = current->next;          //Traverses
      prevTraversal = traversal;        //Sets the previous traversal check to the current traversal
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
