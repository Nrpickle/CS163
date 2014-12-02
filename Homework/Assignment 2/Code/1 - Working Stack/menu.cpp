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

void menuType::process(stackType & stack)
{
  int status = 0;  //Status integer to handle the status returns of functions
  switch (choice)
  {
    case 1:
      cout << "Add new item" << endl;
      status = insertStack(stack);
      if(status)
        cout << "Insertion Successful" << endl;
      break;
    case 2:
      cout << "Pop" << endl;
      status = popStack(stack);
      if(status)
        cout << "Successful" << endl;
      else
        cout << "List is empty" << endl;
      break;
    case 3:
      cout << "Display All DEBUG" << endl;
      stack.debugDisp();
      break;
    case 6:
      cout << "Exiting Program" << endl;
      break;
    default:
      cout << "That is not a valid choice." << endl;
      break;
  }
}


int menuType::insertStack(stackType & stack)
{
  stackNode newData;

  read_int("Please enter the data: ", newData.data);

  return stack.push(newData);
}


int menuType::popStack(stackType & stack)
{
  stackNode foundData;
  int status = 0;


  status = stack.pop(foundData);

  if(status)
    cout << foundData.data << endl;

  return status;  
}
