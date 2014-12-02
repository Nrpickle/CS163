/*
Nick McComb CS163

Assignment #3
2/21/2013

This is the implementation file for the menu.
*/

#include "table.h"

//Default Constructor
menuType::menuType()
{
  choice = 0;   //Set the default the choice to be zero (an invalid choice)
}

//Default Destructor
menuType::~menuType()
{

}

//Outputs the menu choices to the user
void menuType::disp()
{
  cout << endl;
  cout << "-----------" << endl;
  cout << "-Main Menu-" << endl;
  cout << "-----------" << endl;
  cout << "1: Add a new command" << endl;
  cout << "2: Remove a command" << endl;
  cout << "3: Retrieve a command (display)" << endl;
  cout << "4: Exit the program" << endl;
}


//Checks if the user wants to continue
//If the user has chosen '4' then the main executing
//loop will not loop again
bool menuType::again()
{
  if(choice == 4)   //If the user has chosen to exit, return false
    return false;
  return true;      //Else, return true

}


//Reads in a user's choice and stores it in the manu data member 'choice'
void menuType::choose()
{
  read_int("Please enter your choice: ", choice);
  cout << endl;
}

//This prototype is placed here so that it can be used by this file
void read_array(char prompt[], char array[], int size);

//This function processes the choice that the user makes.
//The options are as described in the disp() function above
void menuType::process(tableType & table)
{
  int status = 0;  //Status integer to handle the status returns of functions

  char * temp = new char [TEMP_SIZE];
  char * targetKey = new char [TEMP_SIZE];

  commandType tempCommand;   //Temporary command used for storing information
  int len = 0;               //Used for 'measuring' arrays
  char response;             //Used for responses to prompts

  //Debugging
  char random[11];           //Used in the generation of large amounts of data
  int amtRandom = 0;         // ""            ""            ""            ""

  switch (choice)  //Acts upon the user's choice
  {
    case 1: //Add a new command
	  cout << "Add a new command" << endl;
	  read_array("Please enter the command: ", targetKey, TEMP_SIZE);  //Reads in the key
	  
	  readCommandInfo(tempCommand);  //Reads in the specific command information from the user
	  if(table.insert(targetKey,tempCommand))  //Inserts the command into the ADT, determines if successful
	    cout << "Successfully added" << endl;
      break;
    case 2: //Remove a command
	  cout << "Remove a command" << endl;
	  read_array("Please enter the command: ", targetKey, TEMP_SIZE);  //Reads in the key
	  if(table.remove(targetKey))    //Searches for and removes the passed key
	    cout << "Successfully removed" << endl;
	  else
	    cout << "The entered command was not found" << endl;
      break;
    case 3:
	  cout << "Retrieve a command" << endl;
	  read_array("Please enter the command: ", targetKey, TEMP_SIZE);  //Reads in the key
	  if(table.retrieve(targetKey,tempCommand))  //Searches for and retrieves the passed key
	  {   //Outputs the retreived information
	    cout << "Successfully found" << endl;
		cout << endl << "Command: " << targetKey << endl;
		cout << "Function: " << tempCommand.func << endl;
		cout << "Rules: " << tempCommand.rules << endl;
	  }
	  else
	    cout << "The entered command was not found" << endl;
      break;
    case 4:  //Exit program
      cout << "Exiting Program" << endl;
      break;
	  
    //The following are three debugging functions that are used to test large amounts of information

    case 777: //Debug, display all current values
	  cout << "Display all of the counters for the indexes" << endl;
	  table.displayCounter();
	  break;
	case 888: //Fill with random keys
	  read_int("Number of data: ", amtRandom);
	  for(int i = 0; i < amtRandom; ++i)
	  {
    	  for(int i = 0; i < 10; ++i)
	    {
	      random[i] = (rand() % 26) + 'a';
	    }
	    random[10] = '\0';
		tempCommand.func = new char [2];
		tempCommand.func[0] = '\0';
		tempCommand.rules = new char [2];
		tempCommand.rules[0] = '\0';
        cout << random << endl;	
		table.insert(random,tempCommand);
	  }
	  break;
	case 999:
	  table.displayAll();
	  break;

    default:
      cout << "That is not a valid choice." << endl;
      break;
  }

  delete [] temp;  			//Deletes the temporary variables
  delete [] targetKey;
}

//Reads in the command information from the user
//Helps make the program easier to read
int menuType::readCommandInfo(commandType & tempCommand)
{
  char * temp = new char [TEMP_SIZE];   //Used to store information from the user
  int len = 0;                          //Used to 'measure' the arrays

  //Reads in the infromation from the user and stores it in the passed command  
  read_array("Command function: ", temp, TEMP_SIZE);
  len = strlen(temp);
  tempCommand.func = new char[len+1];
  strcpy(tempCommand.func, temp);
  
  read_array("Defined rules: ", temp, TEMP_SIZE);
  len = strlen(temp);
  tempCommand.rules = new char[len+1];
  strcpy(tempCommand.rules, temp);
  
  delete [] temp;
}


