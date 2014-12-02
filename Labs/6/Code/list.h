//list.h
#include <iostream>
#include <cstring>
#include <cctype>


struct node
{
    int data;
    node * next;
};

class list
{
      public:
      /* These functions are already written and can be called to test out your code */
          list();        //supplied
          ~list();       //supplied
          void display(int unused);    //supplied

      /* *****************YOUR TURN! ******************************** */
      /* These are the prototypes for the functions you will be writing for LAB #5 */
          void display_all();         //STEP 1
          int count_first();          //STEP 2
          bool last_occurance();      //STEP 3
          void append(int to_add);    //STEP 4, 5
          void remove_last();         //STEP 6


      private:
          node * head;
};
