/*
Nick McComb CS163
2/12/2013

Assignment #2

This is the implementation of the avatar stack
*/

#include "list.h"


//Avatar Constructor
avatarType::avatarType()
{
  name = NULL;
}

//Avatar Type destructor
avatarType::~avatarType()
{
  delete [] name;
}

//Default Constructor
stackNode::stackNode()
{
  next = NULL;
}

//Default Destructor
stackNode::~stackNode()
{

}

//Default Constructor
stackType::stackType()
{
  head = NULL;
}


//Default Destructor
stackType::~stackType()
{
  stackNode * temp;
  while(head)
  {
    temp = head;
    head = head->next;
    delete temp;
  }
}

//This pushes a new node onto the fron of the stack
int stackType::push(const avatarType & newAvatar)
{
  stackNode * temp = new stackNode;

  int len = 0;
  //Copy Data
  len = strlen(newAvatar.name);
  temp->avatar.name = new char[len + 1];
  strcpy(temp->avatar.name, newAvatar.name);
  temp->avatar.rank = newAvatar.rank;


  if(!head)  //If the list is empty
  {
    head = temp;
    head->next = NULL;
  }
  else       //Insert it at the front
  {
    temp->next = head;
    head = temp;
  }
  return 1;
}

//Returns and removes the first node of the stack
int stackType::pop(avatarType & foundAvatar)
{
  if(!head)    //If the list is empty,
    return 0;  //Return empty list

  
  int len = 0;
  //Copy Data
  len = strlen(head->avatar.name);
  foundAvatar.name = new char[len + 1];
  strcpy(foundAvatar.name,head->avatar.name);
  foundAvatar.rank = head->avatar.rank;


  //Remove head node
  stackNode * temp = head;

  head = head->next;

  delete temp;

  return 1;
}

//Returns the data in the first node without removing it
int stackType::peek(avatarType & foundAvatar)
{
  if(!head)
    return 0;

  int len = 0;
  //Copy Data
  len = strlen(head->avatar.name);
  foundAvatar.name = new char[len + 1];
  strcpy(foundAvatar.name,head->avatar.name);
  foundAvatar.rank = head->avatar.rank;


  return 1;
}


//Determines if the stack contains data
//Returns false if the stack is not empty
int stackType::isEmpty()
{
  if (head)   //If head exists, then there is data in the stack
    return 0;
  return 1;   //Else, there is no data
}


//Displays all of the avatars currently in the stack
int stackType::dispAll()
{
  stackNode * current = head;

  if(!head)
    return 0;

  cout << setw(8) << left << "Name" << " Rank" << endl;
  while(current)
  {
    cout << setw(8) << left << current->avatar.name << " " << current->avatar.rank << endl;
    current = current->next;
  }

  return 1;
}

//Adds a weapon the queue that is in the current ('head') node
int stackType::enqueueWeapon(const weaponType & weapon)
{
  return head->avatar.weapons.enqueue(weapon);
}

//Removes a weapon from the 'head' avatar in the stack
int stackType::dequeueWeapon(weaponType & foundWeapon)
{
  return head->avatar.weapons.dequeue(foundWeapon);
}

//Returns the information of the head weapon in the head avatar
int stackType::peekWeapon(weaponType & foundWeapon)
{
  return head->avatar.weapons.peek(foundWeapon);
}

//Displays all of the weapons that in the avatar's weapon queue
int stackType::dispAllWeapon()
{
  return head->avatar.weapons.dispAll();
}

//Deletes all of the weapons that are in the avatar's weapon queue
int stackType::deleteAllWeapons()
{
  return head->avatar.weapons.deleteAll();
}
