/*
Nick McComb CS163

Assignment #4
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
/*
  cout << "1: " << endl;
  cout << "2: " << endl;
  cout << "3: " << endl;
  cout << "4: " << endl;
  cout << "5: " << endl;
*/
  cout << "6: Exit Program" << endl;
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


void menuType::process(treeClass & tree)
{
  int status = 0;  //Status integer to handle the status returns of functions

  char * temp = new char [TEMP_SIZE];
  char * returned;  //Returned value
  int len = 0;               //Used for 'measuring' arrays
  char response;             //Used for responses to prompts

  courseClass tempData;
  
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
	  
	  if(tempData.getCourse(returned))
	    cout << "Title found: " << returned << endl;
      else
        cout << "No title found" << endl;

	  if(tempData.getTopic(temp))
	    cout << "Topic found: " << temp << endl;
      else
	    cout << "No Topic found" << endl;	
		
	  if(tempData.getDirectory(temp))
	    cout << "Directory found: " << temp << endl;
      else
	    cout << "No Directory found" << endl;	

	  tree.insert(return_int("Number: "));

      break;
    case 2:  
	  cout << "Display All Current Entries" << endl;
      tree.displayAll();
      break;
    case 3:
      break;
    case 4: 
      break;
    case 5:  
      break;
    case 6:  //Exit program
      cout << "Exiting Program" << endl;
      break;
    case 777:  //Randomly insert data
	  len = rand() % 200;
	  cout << "Inserting: " << len << endl;
	  tree.insert(len);
      break;
    default:
      cout << "That is not a valid choice." << endl;
      break;
  }

  delete [] temp;  			//Deletes the temporaray variable
}






