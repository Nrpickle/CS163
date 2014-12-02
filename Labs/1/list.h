#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

struct node
{
       int data;
       node * next;
};

class list
{
      public:
             //I have written these functions for your convenience
             list();
             ~list();
             void build();
             void display_all();
             
             //Write, iteratively, each of these functions
             void display();
             void remove_last();
             void remove_all();
             void display_every_other();
             bool find_item(int item_to_find);
      
      private:
              node * head;
};
             
