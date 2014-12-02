#include "list.h"
using namespace std;


void list::display_all(void)
{
  node * current = head;
  
  while(current)
  {
    cout << current->data;
	current = current->next;
	if(current)
	  cout << " -> ";
  }
}

int list::count_first()
{
  int count = 0;
  int firstData;
  node * current = head;
  
  if(!current)
    return 0;

  firstData = current->data;
	
  while(current)
  {
    if(firstData == current->data)
	  ++count;
	current = current->next;
  }

  return count;
}

bool list::last_occurance()
{
  if(!head)
    return false;
	
  int lastNum = 0;
  node * current = head;
  node * last;

  while(current->next)
  {
    current = current->next;
  }
  
  last = current;
  lastNum = last->data;

  current = head;
  
  while(current)
  {
    if(current != last && lastNum == current->data)
	  return true;
	current = current->next;
  }
  return false;
}

void list::append(int to_add)
{
  node * current = head;
  
  if(!current)
    return;
	
  while(current->next)
    current = current->next;
  
  current->next = new node;
  current = current->next;
  current->data = to_add;
  current->next = NULL;
}


void list::remove_last()
{
  if(!head)
    return;
  if(!head->next)
  {
    delete head;
	head = NULL;
  }
  
  
  node * current = head;
  
  while(current->next->next)
    current = current->next;
  
  delete current->next;
  current->next = NULL;

}







