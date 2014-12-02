#include "list.h"
using namespace std;

const int SIZE=100;

int main()
{
    
    char title[SIZE], notes[SIZE];  //temporary for journals
    char response;
    journal entry;                //Start creating entries!
    list my_journal;
    
     
    //Let's create some journal entries
    
    do
    {
       cout <<"Please enter the title of your journal entry\n";
       cin.get(title, SIZE, '\n'); cin.ignore(SIZE,'\n');
       cout <<"Please enter your notes\n";
       cin.get(notes, SIZE, '\n'); cin.ignore(SIZE,'\n');
       
       //Now create the journal entry
       entry.create_entry(title, notes);
       
       //Add it to the list!
       my_journal.add(entry);
     } while (again());
     
     //Is there an entry we would like to find (by title)?
     cout <<"Enter a title which you would like to find in your journal: ";
     cin.get(title, SIZE, '\n'); cin.ignore(SIZE,'\n');
     if (my_journal.find(title, entry))
        cout <<"\n\nWe found: "; entry.display();
     
     //Now display all that we have
     cout <<"\n\nThe entire list contains the following\n";
     my_journal.display();
     
}
