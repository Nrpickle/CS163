#include "list.h"
using namespace std;

bool find(node * head, int match)
{
  if (!head)
    return false;
	
  if (head->data == match)
    return true;
  else
    return find(head->next, match);
}


void insert_9(node * & head)
{
  if(!head)
    return;

  node * temp;	

  if(head->data == 2)
  {
	temp = head->next;
	head->next = new node;
	head->next->data = 9;
	head->next->next = temp;
  }
  
  return insert_9(head->next);
}

void display_last_two(node * head)
{
  if(!head->next)
  {
    cout << head->data << endl;
	return;
  }
  
  if(!head->next->next)
  {
    cout << head->data << endl;
  }

  return display_last_two(head->next);
}

bool same_length(node * head1, node * head2)
{
  if(!head1 || !head2)
  {
    if(!head1 && !head2)
	  return true;
	else
	  return false;
  }

  return same_length(head1->next, head2->next);
}









