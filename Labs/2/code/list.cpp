/*
Nick McComb CS163

Lab #2
*/

#include "list.h"

//Default constructor
//This seats the ehad to NULL
list::list(void)
{
  head = NULL;
}


//Default destructor
list::~list(void)
{
  node * temp;
  while(head)
  {
    temp = head->next;
    delete head;
    head = temp;
  }
}

//Adds an entry into the List
int list::add(journal & to_add)
{
  if(!head) //if head is null
  {
    head = new node;
    head->entry.copy_entry(to_add);  //Copies the entry
    head->next = NULL;
  }
  else   //Head is not null
  {
    node * current = head;
    while(current->next)  //Traverses to the end of the list
    {
      current = current->next;
    }
    current->next = new node;
    current = current->next;
    current->entry.copy_entry(to_add);
  } 
  return 1;  //Successful
}

//Searches the list for a passed value
int list::find(char title[], journal & found)
{
  journal search;
  if(!head) //There is no list
    return 0;

  node * current = head;

  while(current)
  {
    if(current->entry.retrieve(title,search))  //Tests to see if the title matches
      found.copy_entry(search);                //If it is found, copy it over
    current = current->next;
  }
}

//Displays the entire list
int list::display(void)
{
  if(!head)   //There is no list
    return 0;
  
  node * current = head;

  while(current)
  {
    current->entry.display();
    current = current->next;
  }
}

