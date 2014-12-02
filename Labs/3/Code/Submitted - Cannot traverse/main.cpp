#include "stack.h"
using namespace std;

int main()
{
    stack my_journal;
    journal to_add, an_entry;
    char title[100];
    char notes[300];

    cout << my_journal.pop() << endl;

    cout << my_journal.peek(to_add) << endl;

    
    //Let's add some items ot the journal first
    do
    {
       cout <<"Please enter a title: ";
       cin.get(title, 100); cin.ignore(100,'\n');
       cout <<"Please enter the notes: ";
       cin.get(notes, 300); cin.ignore(100,'\n');
       to_add.create_entry(title, notes);
       
       //now push it on the stack
       my_journal.push(to_add);

       cout << my_journal.peek(to_add) << endl;

       cout << my_journal.pop() << endl;
       
    } while (again());
    
    //Let's display what we have  (this function was provided for you)
    cout <<"\n\nThis is the contents of the stack: " << endl;
    my_journal.display_all();
    
    //Now peek at the first entry
    my_journal.peek(an_entry);
    cout <<"\n\nThis is what is at the top of stack: " << endl;
    an_entry.display(); //Let's see what it is!
    
    //Now pop!
    do
    {
          
          if (my_journal.pop())
          {
             cout <<"\n\nAfter removing this is what we have: " << endl;
             my_journal.display_all();
          }
    } while (again());
    
    return 0;
}
