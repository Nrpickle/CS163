/*
Nick McComb CS163
Assignment #3
2/21/2013

This is the main implementation file for the Hash Table Abstract Data Type
*/

#include "table.h"

//This is the default constructor for the commandType struct
commandType::commandType()
{
  func = NULL;   //Sets both of the pointers to arrays to null
  rules = NULL;
}

//This is the default destructor for the commandType struct
commandType::~commandType()
{
  delete [] func;  //Deletes of the the arrays that were dynamically allocated
  delete [] rules;
}

//This is the default constructor for the chaining node
node::node()
{
  next = NULL;  //Sets the next node to null so that there can be ends of lists easier
  key = NULL;
}

//This is the default destructor for the chaining node
node::~node()
{
  delete [] key;  //Deletes the dynamically allocated array of characters that is key
}

//This is the default constructor for the hash table ADT
tableType::tableType()
{
  hashTable = new node * [TABLE_SIZE];  //Creates the array of nodes to create the hash table
  
  counter = new int[TABLE_SIZE];        //Initializes the counter to be the size of the table
  for(int i = 0; i < TABLE_SIZE; ++i)   //Initalizes all of the elements of the array to be 0
    counter[i] = 0;
}

//This is the default destructor for the hashTable ADT 
tableType::~tableType()
{
  delete [] counter;
  for(int i = 0; i < TABLE_SIZE; ++i)  //Deallocates all nodes in the list
    deleteLLL(hashTable[i]);
  
  delete [] hashTable;
}

//Deletes the linear linked list that the node it is passed points to
//The head pointer eventually becomes NULL again
void tableType::deleteLLL(node * & head)
{
  if(!head)             //If head is null, then the list is empty
    return;
  node * temp = head;   //Creates a temporary node to point to the node
			            //that is going to be deleted
  while(head)           //Continue until the end of the list is reached
  {
    head = head->next;  //Makes the inital head NULL again
	delete temp;        //Deletes the node that has not been traversed
  	temp = head;		//'Catches' head up to the other node
  }
}

//This function inserts the passed information into the ADT
//It uses the hash function to determine the correct index, then places
//the data there, chaining if necessary to account for collisions
int tableType::insert(char key[], const commandType & newCommand)
{
  int targetIndex = hash(key);
  int len = strlen(key);         //Measures the key

  //  cout << "--Target Index: " << targetIndex << endl;  //Debugging

  //Add at the head  
  node * temp = hashTable[targetIndex];
  hashTable[targetIndex] = new node;
  hashTable[targetIndex]->next = temp;
  hashTable[targetIndex]->key = new char[len + 1];
  strcpy(hashTable[targetIndex]->key, key);    
  copyCommands(hashTable[targetIndex]->command, newCommand);

  //Increment Efficiency Counter
  ++counter[targetIndex];         //Increments the counter that tracks
								  //the number of items in the individual chains
  return 1;
}

//This function removes the passed key from the list, or returns a
//failed valyue if the key is not in the list. 
int tableType::remove(char key[])
{
  int targetIndex = hash(key);
  
  if(!hashTable[targetIndex])  //The item could not be found because
    return 0;                  //there is nothing indexed at that position
   
  if(!strcmp(hashTable[targetIndex]->key,key))  //Check to see if it is the first node
  {
	node * temp = hashTable[targetIndex]->next;
	delete hashTable[targetIndex];
	hashTable[targetIndex] = temp;
	--counter[targetIndex]; //Decreases the amount of nodes recorded in the chain
	return 1;                              //Returns from the function; successful
  }
  else
  {
	node * current = hashTable[targetIndex];
	while(current->next)                   //Checks a node ahaid for a match
	{
	  if(!strcmp(current->next->key,key))  //If the next one matches,
	  {                   				   //then connect around it and
	  node * temp = current->next;         //delete it
		current->next = current->next->next;
		delete temp;
		--counter[targetIndex];
		return 1;                          //return from the function 
	  }								       //because deletion has occured
	  current = current->next;
	}
  }
  
  return 0;
}

//This function retrieves the data for the passed key and returns it 
//via a passed struct. It returns false if the item does not exist in the list
int tableType::retrieve(char key[], commandType & foundCommand)
{
  int targetIndex = hash(key); //Calculates the target index
  int success = 0;             //Determines if the function was successfull
  
  if(!hashTable[targetIndex])  //The item could not be found because
    return 0;                  //there is nothing indexed at that position
   
  if(!strcmp(hashTable[targetIndex]->key,key))  //Check to see if it is the first node (head)
  {
    copyCommands(foundCommand, hashTable[targetIndex]->command);  //Copies the wanted data
	                                                              //into the passed array
	success = 1;
  }
  else  //Not at head
  {
    node * current = hashTable[targetIndex];
	while(current)  //While current is still pointing to valid data
	{
	  if(!strcmp(current->key,key))  //If the keys match
	  {
        copyCommands(foundCommand, current->command); //Copy desired data
		success = 1;
	  }
	  current = current->next;       //Traversal, to continue searching
	}
  }
  
  return success;
}

//This function simplifies the insert and retrieve commands by providing
//a simpler way to copy Command structs
void tableType::copyCommands(commandType & dest, const commandType & source)
{
  int len = 0; //Used to measure the length of the arrays
  
  len = strlen(source.func);
  dest.func = new char [len + 1];
  strcpy(dest.func, source.func);
  
  len = strlen(source.rules);
  dest.rules = new char [len + 1];
  strcpy(dest.rules, source.rules);

}


//This function displays all of the information that is stored in the counter array of ints,
//which keeps track of the amount of collisions that have occured for a particular value
//and is helpful for debugging.
int tableType::displayCounter(void)
{
  for(int i = 0; i < TABLE_SIZE; ++i)  //Iterates through all possible index values
    cout << "--Index " << i << ": " << counter[i] << endl << endl; //Outputs the corresponding
                                                                   //counter integer
}

//This funciton displays all of the information that is stored in the ADT
void tableType::displayAll()
{
  for(int i = 0; i < TABLE_SIZE; ++i)  //Iterates through all possible index values
    displayIndex(i);                   //Displays the information for the passed index value
}

//This function displays all of the current nodes in the passed index
//It is used for debugging, and therefore outputs directly to the user
int tableType::displayIndex(int targetIndex)
{
  if(!hashTable[targetIndex])  //If empty list, display nothing
    return 0;
  cout << endl << "--Display index: " << targetIndex << endl;
  node * current = hashTable[targetIndex]; 
  
  while(current)  //While the data is still valid,
  {
    cout << "--" << current->key << endl;  //Output
	current = current->next;               //Traverse until the data is not valid
  }

  return 1;
}


//Hash function
//This function converts the passed name of a funciton into an 
//index that is within the bounds of the current TABLE_SIZE.
//This hash function works by using the first character of the array
//if the size is less than 2, otherwise it adds up the first and the last
//character of the passed array and then mods it so that it will be within the 
//bounds of the hash table
int tableType::hash(char key[])
{
  int len = strlen(key);
  if(len < 2)
    return key[0] % TABLE_SIZE;
  else
    return (key[0] + key[len - 1]) % TABLE_SIZE;
}


