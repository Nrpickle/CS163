/*
Nick McComb CS163
2/5/2013

*/


#include "list.h"


//Default Constructor
menuType::menuType()
{
  choice = 0;   //Default the choice to be zero
}


//Default Destructor
menuType::~menuType()
{

}

//Manages the output of the menu options
void menuType::disp()
{
  cout << endl;
  cout << "-----------" << endl;
  cout << "-Main Menu-" << endl;
  cout << "-----------" << endl;
//  cout << "6: Exit the program" << endl;
}


//Checks if the user wants to continue
bool menuType::again()
{
  if(choice == 6)   //If the user has chosen to exit, return false
    return false;
  return true;      //Else, return true

}

void menuType::choose()
{
  read_int("Please enter your choice: ", choice);
  cout << endl;
}

void read_array(char prompt[], char array[], int size);

void menuType::process(stackType & allAvatars)
{
  int status = 0;  //Status integer to handle the status returns of functions

//  avatarType avatar;
  char * temp = new char [TEMP_SIZE];
  int len = 0;               //Used for 'measuring' arrays

  switch (choice)
  {
    case 1:  //Add a new avatar
      cout << "Add New Avatar" << endl;
/*
      read_array("Name: ",temp,TEMP_SIZE);
      len = strlen(temp);
      avatar.name = new char[len + 1];
      strcpy(avatar.name, temp);
      read_int("Ranking: ", avatar.rank);
      cout << "Name: " << avatar.name << endl;
      cout << "Ranking: " << avatar.rank << endl;
      delete [] avatar.name;
*/
      break;
    case 2:  //View current Avatar (or select)
      cout << "Select main avatar" << endl;
      break;
    case 3:  //View all Avatars
      cout << "View all avatars" << endl;
      break;
    case 4:  //Delete current avatar
      cout << "Delete current avatar" << endl;
      break;
    case 6:  //Exit program
      cout << "Exiting Program" << endl;
      break;
    default:
      cout << "That is not a valid choice." << endl;
      break;
  }
  cout << "End of function" << endl;
  delete [] temp;
}
