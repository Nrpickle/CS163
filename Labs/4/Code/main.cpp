#include "table.h"
using namespace std;

int main()
{
    table my_journal;
    journal to_add, an_entry;
    char title[100];
    char notes[300];
 

    //Let's add some items ot the journal first
    do
    {
       cout <<"Please enter a title: ";
       cin.get(title, 100); cin.ignore(100,'\n');
       cout <<"Please enter the notes: ";
       cin.get(notes, 300); cin.ignore(100,'\n');
       to_add.create_entry(title, notes);
       
       //now insert it into the hash table
       my_journal.insert(title, to_add);
       
    } while (again());
    
    //Let's display what we have  (this function was provided for you)
    cout <<"\n\nThis is the contents of the table:\n";
    my_journal.display_all();
    
    do
    {
       //Now retrieve an entry
       cout <<"What journal entry would you like to retrieve - provide the title: ";
       cin.get(title, 100); cin.ignore(100,'\n');
       if (my_journal.retrieve(title, an_entry))
       {
            cout <<"\n\nThis is what was found: ";
            an_entry.display(); //Let's see what it is!
       }
       else cout <<"No entry found\n\n";

     } while (again());
   
    return 0;
}
