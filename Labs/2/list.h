//This file contains information for a collection of journal entries
//All of the functions have been implemented except for those that have
//comments indicating that you need to provide the code. Enjoy!
#include "journal.h"

struct node
{
       journal entry;
       node * next;
};

class list
{
      public:
             //Write, iteratively, each of these functions
             list(void);
             ~list(void);
             int add(journal & to_add);
             int find(char title[], journal & found);
             int display(void);
 
      private:
              node * head;
};
             
