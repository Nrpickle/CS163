#include "journal.h"

//In Lab #3 we will be working with the journal class from Lab #2 (where the code
//is already written, compiled, and object code provided. In this lab we will
//extend it by creating a stack of journals. The data structure will be a 
//linear linked list of arrays of dynamicaly allocated journal entries

//Here is the node structure. Remember, whenever you have a pointer you can
//point to one item or the first of many items
struct node
{
       journal * entries; //a dynamically allocated array of journal entries
       node * next;
};

//Now let's create a stack. Stacks should be able to keep a collection of
//data and push (add at the beginning), pop (remove at the beginning), 
//display all, and peek (retrieve the information at the beginning).
//If you NEED more functionality than the journal class provides, you can
//always add a prototype to the journal.h file and create your own functions
//in a file named SOMETHING with your last name (e.g., fant_journal.cpp)

//Create arrays of const size MAX
const int MAX = 5;

class stack
{
      public:
             stack(void);     //initialize all data members
             ~stack(void);     
             
             //Peek: You need to get back through the argument list the
             //journal on the top of the stack but don't change the stack
             int peek(journal & foundJournal);
                                  
             int push(const journal & newJournal);
                                         //to push the argument onto the stack
             int pop (void); 
  
             int display_all(void); /*This is already implemented */
      private:
              node * head;
              int num_items;    //how full is the array of journal entries
                                //located at the top node of the stack
              int top;
};
             
