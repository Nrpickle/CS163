#include "journal.h"

//In Lab #4 we will be working with the journal class from Lab #2 . In this lab we will
//extend it by creating a hash table of journals. The data structure will be an array
//of head pointers to linear linked lists of nodes. Each node has a single journal entry

struct node
{
       node();
	   journal entry; //just one journal entry
       node * next;
};

//Now let's create a table ADT. A table ADT works by the value of the data
//instead of the position of where it is located. It allows us the class designers
//to begin using non-linear data structures!

//Create arrays of const size MAX
const int MAX = 5;
const int TABLE_SIZE = 5;

class table
{
      public:
             table(void);     // IMPLEMENT THIS
             ~table(void);    // Already implemented in methods.o   
             
             //insert the journal being passed in, into the table
             //Pass in the title as the key value for the hash table to create an index
             int insert(char * key_value, const journal & to_add);   //IMPLEMENT THIS
             int retrieve(char * title_to_find, journal & found);   //IMPLEMENT THIS
  
             int display_all(void); /*This is already implemented */
      private:
             node ** hash_table;  //a dynamically allocated array of head pointers
             int hash(char key[]);
};
