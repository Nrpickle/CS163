/*
Nick McComb  CS163
Lab #3
*/

#include "stack.h"
using namespace std;



stack::stack()
{
  head = NULL;
  num_items = 0;
}

stack::~stack()
{
  node * temp;
  while(head)
  {
    temp = head;
    head = head->next;
    delete [] temp;
  }
}


int stack::peek(journal & foundJournal)
{
  if(!head)  //Empty list
    return 0; 

  node * current = head;

  for(int i = 0; i < (num_items / MAX); ++i)
    current = current->next;

  foundJournal.copy_entry(current->entries[(num_items - 1) % MAX]);

  return 1;
}


int stack::push(const journal & newJournal)
{
  if(!head) //Empty list
  {
    head = new node;
    head->next = NULL;
    head->entries = new journal[MAX];
    head->entries[0].copy_entry(newJournal);
    ++num_items;
  }
  else
  {
    node * current = head;

    if(num_items % 5 == 0)
    {
      while(current->next)
        current = current->next;
      current->next = new node;
      current->entries = new journal[MAX];
    }
    else
      for(int i = 0; i < (num_items / MAX); ++i)
        current = current->next;

    current->entries[num_items % MAX].copy_entry(newJournal);

    ++num_items;
  }

}


int stack::pop(void)
{
  if(!head)   //The list is empty
    return 0;

  --num_items;

/*
  node * temp = head;

  head = head->next;

  delete temp;

*/

  return 1;

}
