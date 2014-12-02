/*
Nick McComb CS163
2/5/2013

Assignment #2

This is the basic implementation of a stack class
*/


#include "list.h"


stackNode::stackNode()
{
  next = NULL;
}


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


int stackType::push(const stackNode & newData)
{
  stackNode * temp = new stackNode;

  temp->data = newData.data;

  if(!head)  //If the list is empty
  {
    head = temp;
    head->next = NULL;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
  return 1;
}



int stackType::pop(stackNode & foundData)
{
  if(!head)    //If the list is empty,
    return 0;  //Return empty list

  //Copy over data
  foundData.data = head->data;

  //Remove head node
  stackNode * temp = head;

  head = head->next;

  delete temp;

  return 1;
}


int stackType::peek(stackNode & foundData)
{
  if(!head)
    return 0;

  //Copy over data
  foundData.data = head->data;

  return 1;
}




//Determines if the stack contains data
int stackType::isEmpty()
{
  if (head)   //If head exists, then there is data in the stack
    return 1;
  return 0;   //Else, there is no data
}






//DEBUGGING DISPLAY ALL FUNCTION
void stackType::debugDisp()
{
  stackNode * current = head;

  if(!head)
    return;

  while(current)
  {
    cout << current->data << endl;
    current = current->next;
  }

}
