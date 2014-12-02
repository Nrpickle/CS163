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

void menuType::process(queueType & queue)
{
  int status = 0;  //Status integer to handle the status returns of functions

  queueNode tempData;


  switch (choice)
  {
    case 1:
      cout << "Enqueue" << endl;
      read_int("Enter data: ", tempData.data);
      status = queue.enqueue(tempData);
      if(status)
        cout << "Insertion Sucessful" << endl;
      break;
    case 2:
      cout << "Dequeue" << endl;
      status = queue.dequeue(tempData);
      if(status)
        cout << "Recieved data: " << tempData.data << endl;
      else
        cout << "List is empty" << endl;
      break;
    case 3:
      cout << "Peek" << endl;
      status = queue.peek(tempData);
      if(status)
        cout << "Recieved data: " << tempData.data << endl;
      else
        cout << "There is no information stored." << endl;
      break;
    case 4:
      cout << "Display All DEBUG" << endl;
      break;
    case 6:
      cout << "Exiting Program" << endl;
      break;
    default:
      cout << "That is not a valid choice." << endl;
      break;
  }
}
