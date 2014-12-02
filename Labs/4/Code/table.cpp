/*
Nick McComb CS163

Lab #4
*/

#include "table.h"
using namespace std;

node::node()
{
  next = NULL;
}


table::table(void)
{
  hash_table = new node * [TABLE_SIZE];

  for (int i = 0; i < (TABLE_SIZE-1); ++i)
    hash_table[i] = NULL;
}


int table::insert(char * key_value, const journal & to_add)
{
  int targetIndex = hash(key_value);
  
  cout << "--Hash: " << targetIndex << endl;
  cout << hash_table[targetIndex] << endl;
  
  node * temp = hash_table[targetIndex];
  hash_table[targetIndex] = new node;
  hash_table[targetIndex]->next = temp;
  hash_table[targetIndex]->entry.copy_entry(to_add);
  
  return 1;
}

int table::retrieve(char * title_to_find, journal & found)
{
  int targetIndex = hash(title_to_find);
  int success = 0;
  
  if(!hash_table[targetIndex])
    return 0;

  if(hash_table[targetIndex]->entry.retrieve(title_to_find, found))
    success = 1;
  else //Not at head
  {
    node * current = hash_table[targetIndex];
	while(current)
	{
	  if(current->entry.retrieve(title_to_find, found))
	    success = 1;
	  current = current->next;
	}
  }
  return success;
}


int table::hash(char key[])
{
  int len = strlen(key);
  if(len < 2)
    return key[0] % TABLE_SIZE;
  else
    return (key[0] + key[len - 1]) % TABLE_SIZE;
}

