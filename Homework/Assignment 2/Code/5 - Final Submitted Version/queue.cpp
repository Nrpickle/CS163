/*
Nick McComb CS163
2/12/2013

Assignment #2

This is the implementation for the queue header file
*/


#include "list.h"

//Default Constructor
queueNode::queueNode()
{
  next = NULL;
  weapon.name = NULL;
}

//Default Destructor
queueNode::~queueNode()
{
  delete [] weapon.name;
}

//Default Constructor
queueType::queueType()
{
  tail = NULL;
  id = 0;
}

//Default Destructor
//Tail is used as a 'head' pointer in this function
queueType::~queueType()
{
  if (!tail)    //Empty List
    return;
  queueNode * temp = tail->next;
  tail->next = NULL;
  tail = temp;

  while(tail)  //Walk through entire list, untill the manufactured end is reached
  {
    temp = tail->next;
    delete tail;
    tail = temp;
  }
}


//Enqueue's a new weapon into the end of the list
int queueType::enqueue(const weaponType & newWeapon)
{

  queueNode * temp = new queueNode;  //Creates a new node that will eventually be added on

  int len = 0;  //"measures" arrays


  //Copying over data 
  len = strlen(newWeapon.name);
  temp->weapon.name = new char[len + 1];
  strcpy(temp->weapon.name, newWeapon.name);

  temp->weapon.pwr = newWeapon.pwr;
  temp->weapon.speed = newWeapon.speed;
  temp->data = id;
  ++id;

  //Inserting data into queue

  if(!tail)  //empty list case
  {
    tail = temp;
    tail->next = tail;  //Connect the list circularily
  }
  else
  {
    temp->next = tail->next;  //Connect the end of the new node to the beginning of the list
    tail->next = temp;        //Appends the new temp node
    tail = tail->next;        //Advances the tail pointer forward
  }

  return 1;
}


//Returns and removes the 'head' item in the queue
int queueType::dequeue(weaponType & foundWeapon)
{
  if(!tail)    //Empty list
    return 0;

  int len = 0; //Used to 'measure' arrays
  //Copy data
  len = strlen(tail->next->weapon.name);
  foundWeapon.name = new char[len + 1];
  strcpy(foundWeapon.name, tail->next->weapon.name);  
  foundWeapon.pwr = tail->next->weapon.pwr;  //Retrieve the data from the beginnning
  foundWeapon.speed = tail->next->weapon.speed;

  //Delete head node

  //Check if there is only one node (compares the unique ids in each node)
  if(tail->data == tail->next->data)
  {
    delete tail;
    tail = NULL;
  }
  else  //There is more than one node in the list
  {
    queueNode * temp = tail->next;
    tail->next = tail->next->next;
    delete temp;
  }

  return 1;

}


//Returns the 'head' item in the queue without removing it
int queueType::peek(weaponType & foundWeapon)
{
  if(!tail)    //Empty list
    return 0;  

  int len = 0; //Used to 'measure' arrays
  //Copy data
  len = strlen(tail->next->weapon.name);
  foundWeapon.name = new char[len + 1];
  strcpy(foundWeapon.name, tail->next->weapon.name);
  foundWeapon.pwr = tail->next->weapon.pwr;  //Retrieve the data from the beginnning
  foundWeapon.speed = tail->next->weapon.speed;

  return 1;
}


//Checks if the queue is empty or not
//Returns true if the function conteins no data
int queueType::isEmpty()
{
  if(tail)
    return 0;
  return 1;
}


//Outputs all of the items in the list, starting immediatly 'after' tail,
//essentially so the 'head' of the list, and ends with tail
int queueType::dispAll()
{
  if(!tail)  //The list is empty
    return 0;

  queueNode * current = tail->next;

  if(current == tail)  //Single node
  {
    cout << "  " <<  current->weapon.name << "--Current" << endl;
    cout << "  Pwr: " << setw(5) << left << current->weapon.pwr;
    cout << " Speed: " << current->weapon.speed << endl; 
  }
  else  //More than one node
  {
    while(!(current == tail)) //Continue until the last node (but does not display the last node)
    {
      cout << "  " <<  current->weapon.name << endl;
      cout << "  Pwr: " << setw(5) << left << current->weapon.pwr;
      cout << " Speed: " << current->weapon.speed << endl;
      current = current->next;
    }
    //This displays the final weapon
    cout << "  " <<  current->weapon.name << " --Current" << endl;
    cout << "  Pwr: " << setw(5) << left << current->weapon.pwr;
    cout << " Speed: " << current->weapon.speed << endl;
  }

  return 1;
}

//Deletes all of the nodes in the array, but not as a destructor does
//This function checks if the list is empty, and if it is not, then it dequeues an item
int queueType::deleteAll()
{

  if(!tail)  //Empty list
    return 0;

  weaponType tempWeapon;  //Creates a weapon variable so that it can 
                          //be passed to dequeue to delete the nodes

  while(dequeue(tempWeapon));

  return 1;
}

