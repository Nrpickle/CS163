/*
Nick McComb CS163

Assignment #4

This is the implementation file for the menu class, which acts as the client program
*/


#include "tree.h"


//Default Constructor
menuType::menuType()
{
  choice = 0;   //Default the choice to be zero (an invalid choice)
}


//Default Destructor
menuType::~menuType()
{

}

//Outputs the menu choices
void menuType::disp()
{
  cout << endl;
  cout << "-----------" << endl;
  cout << "-Main Menu-" << endl;
  cout << "-----------" << endl;
  cout << "1: Add new topic" << endl;
  cout << "2: Display all topics" << endl;
  cout << "3: Remove a topic" << endl;
  cout << "4: Search for a topic" << endl;
  cout << "6: Exit Program" << endl;
//  cout << "777: Get Height of the trees" << endl;
}


//Checks if the user wants to continue
//If the user has chosen '6' then the main executing
//loop will not loop again
bool menuType::again()
{
  if(choice == 6)   //If the user has chosen to exit, return false
    return false;
  return true;      //Else, return true

}


//Reads in a user's choice and stores it in the data member 'choice'
void menuType::choose()
{
  read_int("Please enter your choice: ", choice);
  cout << endl;
}

//This prototype is placed here so that it can be used by this file
void read_array(char prompt[], char array[], int size);


void menuType::process(treeClass & topic, treeClass & course)
{
  int status = 0;  //Status integer to handle the status returns of functions

  char * temp = new char [TEMP_SIZE];
  char * returned;  //Returned value
  int len = 0;               //Used for 'measuring' arrays
  char response;             //Used for responses to prompts

  dataClass tempData;
  dataClass * dynTempData;
  
  switch (choice)
  {
    case 1: 

	  cout << "Insert New Data" << endl;
	  
	  read_array("Course Name: ", temp, TEMP_SIZE);
	  tempData.insertCourse(temp);
	  read_array("Topic: ", temp, TEMP_SIZE);
	  tempData.insertTopic(temp);
	  read_array("Directory: ", temp, TEMP_SIZE);
	  tempData.insertDirectory(temp);
	  
	  cout << endl;
	  
	  tempData.output();
	  
      topic.insert(tempData,1);
	  course.insert(tempData,2);

      break;
    case 2:  
	  cout << "Display All Current Entries" << endl;
	  read_char("Enter 'c' to display by course, or 't' to display by topic: ", response);
	  if(toupper(response) == 'T')
        if(!topic.displayAll())
	      cout << "There is nothing to display" << endl;
	  if (toupper(response) == 'C')
	    if(!course.displayAll())
		  cout << "There is nothing to display" << endl;
      break;
    case 3:
	  cout << "Remove an entry" << endl;
	  read_char("Enter 'c' to remove by course, or 't' to remove by topic: ", response);
	  if(toupper(response) == 'T')
	  {
  	    read_array("Topic: ", temp, TEMP_SIZE);
	    if(topic.remove(temp,1) && course.remove(temp,2))
	      cout << "Successfully Removed" << endl;
	    else
	      cout << "Topic '" << temp << "' not found" << endl;
	  }
	  if(toupper(response) == 'C')
	  {
	    read_array("Course: ", temp, TEMP_SIZE);
	    if(course.remove(temp,1) && topic.remove(temp,2))
	      cout << "Successfully Removed" << endl;
	    else
	      cout << "Course '" << temp << "' not found" << endl;
	  }
      break;
    case 4: 
	  cout << "Search" << endl;
	  read_char("Enter 'c' to display by course, or 't' to display by topic: ", response);
	  if(toupper(response) == 'T')
	  {
	    read_array("Topic: ", temp, TEMP_SIZE);
		cout << endl;
		int matches = topic.retrieve(temp, dynTempData);
		cout << "Matches: " << matches << endl;
		for(int i = 0; i < matches; ++i)
		{
          dynTempData[i].output(); 
		  cout << endl;
		}
		delete [] dynTempData;
	  }
	  if(toupper(response) == 'C')
	  {
	    read_array("Course: ", temp, TEMP_SIZE);
		cout << endl;
		int matches = course.retrieve(temp, dynTempData);
		cout << "Matches: " << matches << endl;
		for(int i = 0; i < matches; ++i)
		{
          dynTempData[i].output(); 
		  cout << endl;
		}
		delete [] dynTempData;	  
	  }
      break;
    case 6:  //Exit program
      cout << "Exiting Program" << endl;
      break;
    case 777:  
	  cout << "Get height" << endl;
	  cout << "Topic height: " << topic.getHeight() << endl;
	  cout << "Course height: " << course.getHeight() << endl;
      break;
    default:
      cout << "That is not a valid choice." << endl;
      break;
  }

  delete [] temp;  			//Deletes the temporaray variable
}


