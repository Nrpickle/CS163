#include <cstring>
#include <cctype>
#include <iostream>

//This journal supports a title and notes
//In the real world this would contain a date, author, type of journal entry, and much more!
class journal
{
      public:
             journal(void);
             ~journal(void);
             int create_entry(char * title, char * notes);
             int copy_entry(const journal & a_new_entry);
             int retrieve(char * title, journal & found);
             int display(void);
      private:
              char * title;
              char * notes;
};
bool again();
