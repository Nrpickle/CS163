/*
Nick McComb CS163
2/5/2013

Assignment #2
*/


#include "list.h"

queueNode::queueNode()
{
  next = NULL;
}


queueNode::~queueNode()
{

}



//Default Constructor
queueType::queueType()
{
  tail = NULL;
}


//Default Destructor
//Tail is used as a 'head' pointer in this function
queueType::~queueType()
{
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


int queueType::enqueue(const queueNode & newData)
{
  queueNode * temp = new queueNode;

  temp->data = newData.data;

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


int queueType::dequeue(queueNode & foundData)
{
  if(!tail)    //Empty list
    return 0;

  //Copy data
  foundData.data = tail->next->data;  //Retrieve the data from the beginnning

  //Delete head node

  //Check if there is only one node
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


int queueType::peek(queueNode & foundData)
{
  if(!tail)    //Empty list
    return 0;  

  //Copy data
  foundData.data = tail->next->data;   //Retrieve the data from the beginning

  return 1;
}


int queueType::isEmpty()
{
  if(tail)
    return 0;
  return 1;
}


