/*
Nick McComb CS163

Assignment #4
*/

#include "tree.h"

//Default construcor
//Initializes all of the pointers to be NULL
dataStruct::dataStruct()
{
  course = NULL;
  topic = NULL;
  directory = NULL;
  year = 0;
}

//Default destructor
//Deletes the dynamic memory stored in the class
dataStruct::~dataStruct()
{
  delete [] course;
  delete [] topic;
  delete [] directory;
}

/* The following three functions handle the details of copying the relevant passed data into the relevant location in its internal data structure */

void dataClass::insertCourse(char newCourse[])
{
  int len = strlen(newCourse);
  data.course = new char[len + 1];
  strcpy(data.course, newCourse);
}

void dataClass::insertTopic(char newTopic[])
{
  int len = strlen(newTopic);
  data.topic = new char[len + 1];
  strcpy(data.topic, newTopic);
}

void dataClass::insertDirectory(char newDirectory[])
{
  int len = strlen(newDirectory);
  data.directory = new char[len + 1];
  strcpy(data.directory, newDirectory);
}

/* The following three functions handle the retrival of information from inside the dataClass */

//Returns 1 if there was a topic found and a 0 if there was not
	//0 - No topic found
	//1 - Topic found
int dataClass::getTopic(char * & foundTopic)
{
  if(data.topic)
  {
    int len = strlen(data.topic);
	foundTopic = new char[len + 1];
	strcpy(foundTopic, data.topic);
	return 1;
  }
  else
    return 0;
}


//Returns 1 if there was a course found and a 0 if there was not
	//0 - No course found
	//1 - Course found
int dataClass::getCourse(char * & foundCourse)
{
  if(data.course)
  {
    int len = strlen(data.course);
	foundCourse = new char[len + 1];
	strcpy(foundCourse, data.course);
	return 1;
  }
  else
    return 0;
}

//Returns 1 if there was a Directory found and a 0 if there was not
	//0 - No directory found
	//1 - Directory found
int dataClass::getDirectory(char * & foundDirectory)
{
  if(data.directory)
  {
    int len = strlen(data.directory);
	foundDirectory = new char[len + 1];
	strcpy(foundDirectory, data.directory);
	return 1;
  }
  else
    return 0;
}


//Copies the passed class' data into the calling class's struct
int dataClass::copy(dataClass & origData)
{
  if(dataExists())
  {
    delete [] data.topic;
	data.topic = NULL;
	delete [] data.course;
	data.course = NULL;
	delete [] data.directory;
	data.directory = NULL;
	cout << "--deleted existing data" << endl;
  }
  if(origData.getTopic(data.topic) && origData.getCourse(data.course) &&  origData.getDirectory(data.directory))
    return 1;
  return 0;
}

//Outputs the information that is stored in the struct
//This function is only ever called by the Client Application
int dataClass::output()
{
  if(data.course)
    cout << setw(13) << left << "Course: " << data.course << endl;
  if(data.topic)
    cout << setw(13) << left << "Topic: " << data.topic << endl;
  if(data.directory)
    cout << setw(13) << left << "Directory: " << data.directory << endl;
}

//This function returns a true value if all of the pointers in the struct are not NULL
int dataClass::validData()
{
  if(data.course && data.topic && data.directory)
    return 1;
  return 0;
}

//This function returns a true value of any of the poitners in the struct are not NULL
int dataClass::dataExists()
{
  if(data.course || data.topic || data.directory)
    return 1;
  return 0;
}

//NODE MANAGEMENT (constructors and destructors)

//Default construcor
//Initializes all of the pointers to be NULL
node::node()
{
  searchKey = NULL;
  altKey = NULL;
  left = right = NULL;
}

//Default destructor
//Deletes the dynamic memory stored in the node
node::~node()
{
  delete [] searchKey;
  delete [] altKey;
}

//This function handles the details of copying the search keys from node to node
//It copes the search keys from the passed node into the calling node
void node::copyKeys(node * & recivData)
{
  if(searchKey)
    delete [] searchKey;
  if(altKey)
    delete [] altKey;
	
  int len = strlen(recivData->searchKey);
  searchKey = new char[len + 1];
  strcpy(searchKey, recivData->searchKey);
  
  len = strlen(recivData->altKey);
  altKey = new char[len + 1];
  strcpy(altKey, recivData->altKey);
}

//BEGIN BINARY SEARCH TREE IMPLEMENTATION

//Default constructor
treeClass::treeClass()
{
  root = NULL;
}

//Default destructor
treeClass::~treeClass()
{
  if(root)
    removeAll(root);
}

//Inserts the passed data into the BST, and sets the search key as either the course or the topic basied on the value of key selector. 
//1 - Topic is primary, 2 - Course is primary
//This function selects the search key as defined in the above selectors and passes it to addAtEnd so that it can be inserted correctly
int treeClass::insert(dataClass & newData, int keySelector)
{
  char * searchKey = NULL;
  if(keySelector == 1)
    newData.getTopic(searchKey);
  else if(keySelector == 2)
    newData.getCourse(searchKey);

  addAtEnd(root, searchKey, newData, keySelector);
  
  delete [] searchKey;
}

//This recursive function adds the passed data to the function as a leaf at the end of the tree
void treeClass::addAtEnd(node * & root, char * searchKey, dataClass & newData, int keySelector)
{

  if(!root)  //Simple Case
  {
    root = new node;
	root->topic.copy(newData);
	root->left = root->right = NULL;
	cout << "--Inserted Node" << endl;
    if(keySelector == 1)  //Topic is the search key
	{
	  root->topic.getTopic(root->searchKey);
	  root->topic.getCourse(root->altKey);
	}
	if(keySelector == 2)  //Course is the search key
	{
	  root->topic.getCourse(root->searchKey);
	  root->topic.getTopic(root->altKey);	  
	}
  }
  else if (strcmp(searchKey, root->searchKey) < 0)   //Move left
    addAtEnd(root->left, searchKey, newData, keySelector);
  else
    addAtEnd(root->right,searchKey, newData, keySelector);//Move right
}

//Handler function for the display command
//Invocates the recursive display function or returns a false if the tree is empty
int treeClass::displayAll()
{
  if(!root)
    return 0;
	
  display(root);
  return 1;
}

//A recursive function that displays all of the nodes in sorted order
void treeClass::display(node * root)
{
  if(root->left)
    display(root->left);
	
  root->topic.output();
  cout << endl;
  
  if(root->right)
    display(root->right);
}

//This funciton is the publicly callable version of the remove command, it essentially acts as a handler and calls the recursive variety of the function that then does the deleting
//Search Key Selector
//  1 - searchKey
//  2 - altKey
int treeClass::remove(char * searchKey, int keySelector)
{
  return remove(root, searchKey, keySelector);
}

//This is the recursive version of the above function that deletes a node based on the passed searchKey and keySelector
//If the passed search keySelector is 1, then it deletes based upon the searchKey, if it 2, then it deletes baised upon the altKey
int treeClass::remove(node * & root, char * searchKey, int keySelector)
{
  bool found = false;
  if(!root)  //Empty tree / no match found
    return 0;

  if(remove(root->left, searchKey, keySelector))   //Check for the data to the left
    return 1;	

  if(keySelector == 1)
    if(!strcmp(searchKey, root->searchKey))
	  found = true;
  if(keySelector == 2)
    if(!strcmp(searchKey, root->altKey))
	  found = true;
	
  //3
  if(found)  //If the data is found
  {
    if(!root->left && !root->right)  //3a - Leaf
	{
	  delete root;  //Delete root
	  root = NULL;  //Set root to NULL
	  return 1;
	}
	
	if(root->left && !root->right)  //3b -- Internal Node with 1 left child
	{
	  node * temp = root;  //Use a temporary pointer to hold the value of the node to be deleted
	  root = root->left;   //Connect around the node to be deleted
	  delete temp;         //Delete the target node (all of the dynamic memory that has been allocated is handled within the destructor of the dataClass)
	  return 1;
	}
	
	if(!root->left && root->right)  //3c -- Internal Node with 1 left child
	{
	  node * temp = root;  //Use a temporary pointer to hold the value of the node to be deleted
	  root = root->right;  //Connect around the node to be deleted
	  delete temp;         //Delete the target node (all of the dynamic memory that has been allocated is handled within the destructor of the dataClass)
	  return 1;
	}	
	
	if(root->left && root->right)  //3d & 3e
	{
	  if(!root->right->left)  //3d - Internal node with two children, but the right child has no LEFT children
	  {
	    root->topic.copy(root->right->topic);  //Copies the data from the node to the right into the current node
		root->copyKeys(root->right);       //Copies the search keys from the next node into the current
		node * temp = root->right->right;  //Uses a temporary pointer to hold the location of the 2nd node to the right
		delete root->right; //Deletes the node to the right
		root->right = temp; //Reconnects the right pointer to the desired node
	  }
      else  //3e - Internal node with two children (the right child has left children) it replaces the target node with the inorder successor
	  {
	    node * current = root->right;  //Creates a temorary node to hold the current location throughout traversal
		node * previous;           //Previous pointer to drag behind current so that we can reconnect aftarwards
		while(current->left)       //Traverse until we have reached the last node (iteratively)
		{
		  previous = current;      //Drags the pointer behind
		  current = current->left; //Traverses left
		}
		root->topic.copy(current->topic); //Copies the data from the inorder successor into the current root node
		root->copyKeys(current);   //Copies the search keys 
		node * temp = current->right;     //Holds the address of the node to the right of the node to be deleted
		previous->left = temp;     //Connects around the node to be deleted
		delete current;  //Deletes the inorder successor
      }	  
	  return 1;
	}
  }
  
  if(remove(root->right, searchKey, keySelector)) //Check for the data to the left
    return 1;

  return 0;
}

//The public face of the rectrieve functions
//Is passed in a NULL pointer to a dataClass, which is then dynamically allocated with the correct number of matches and then filled with the matches
//Returns the number of matches (conviently a fail state if there are no matches)
int treeClass::retrieve(char * searchKey, dataClass * &  foundData)
{
  int index = 0;  //A variable to hold the index (so it can be changed through pass by reference)
  int matches = countMatches(root, searchKey);  //Determines the number of matches in the data
  foundData = new dataClass[matches]; //Allocates a dynamic array of the correct amount of dataClasses

  retrieve(root, searchKey, foundData, index);  //Fills the array of dataClasses with the matchs' information
  
  return matches;  //Returns the number of matches
}

//Fills the passed array of dataClass's with their relevant data
void treeClass::retrieve(node * root, char * searchKey, dataClass * & foundData, int & index)
{
  if(!root)  //Empty tree / end of the line
    return;
  
  if(root->left)  //Check left
    retrieve(root->left, searchKey, foundData, index);

  if(!strcmp(searchKey, root->searchKey))  //Checks the current
  {
    foundData[index].copy(root->topic);  //Copies the data into the relevant index of the passed array
	++index;  //Increments the array
  }  
	
  if(root->right) //Check right
    retrieve(root->right, searchKey, foundData, index);
}

//Counts the number of matches for the passed search key (recursively)
int treeClass::countMatches(node * root, char * searchKey)
{
  if(!root)
    return 0;

  if(!strcmp(searchKey, root->searchKey))
    return 1 + countMatches(root->left, searchKey) + countMatches(root->right, searchKey);
  else
    return countMatches(root->left, searchKey) + countMatches(root->right, searchKey);
}

//This is the public version of the getHeight funciton
//Gets the height of the tree
int treeClass::getHeight()
{
  return getHeight(root);
}

//This is the private version of the getHeight version, which recursively gets the height of the tree
int treeClass::getHeight(node * root)
{
  if(!root)
    return 0;
  else
    return 1 + max(getHeight(root->left),getHeight(root->right));
}

//The public face of the remove all function, it also checks if the tree is empty, and prevents a segmentation fault
void treeClass::removeAll()
{
  if(!root)
    return;
  removeAll(root);
  root = NULL;
}

//The private version of the removeAll funciton, recursively deletes all of the nodes in the tree
void treeClass::removeAll(node * & root)
{
  if(root->left)
    removeAll(root->left);
	
  if(root->right)
    removeAll(root->right);

  delete root;
}






