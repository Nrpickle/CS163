#include <cstring>
#include <cctype>
#include <iostream>

//This journal supports a title and notes
//In the real world this would contain a date, author, type of journal entry, and much more!
class journal
{
      public:
             journal(void);            //initialize dynamic memory
             ~journal(void);           //deallocate all dynamimc memory
             
             //Set the data members title and notes to the values passed in
             int create_entry(char * title, char * notes);
             
             //Create a new entry but this time with the contents of another
             //journal entry that is coming in as an argument. In CS202 we
             //will be doing this with a function called the copy constructor!
             int copy_entry(const journal & a_new_entry);
             
             //Compare to see if the title passed in matches the current object's
             //title. If it does, fill the argument called "found" with the
             //title and notes
             int retrieve(char * title, journal & found);
             
             //Regardless of the title...fill the argument with the current
             //object's title and notes
             int get_back(journal & current_object);
             int display(void);
      private:
              char * title;
              char * notes;
};
bool again();
