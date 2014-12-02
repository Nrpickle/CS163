/*
Nick McComb CS163
2/12/2013

Assignment #2

This is the implementation file for the menu class that
handles the interaction between the client and the ADT
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

//Outputs the menu choices
void menuType::disp()
{
  cout << endl;
  cout << "-----------" << endl;
  cout << "-Main Menu-" << endl;
  cout << "-----------" << endl;
  cout << "1: Add a new Avatar" << endl;
  cout << "2: View current Avatar" << endl;
  cout << "3: Access Weapon Interface" << endl;
  cout << "4: View all Avatars" << endl;
  cout << "5: Delete current avatar" << endl;
  cout << "6: Exit the program" << endl;
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

//This function processes the choice that the user makes
//It utilizes a case structure to preform the following actions based on the user's choice:
  //"1: Add a new Avatar
  //"2: View current Avatar
  //"3: Access Weapon Interface
  //"4: View all Avatar
  //"5: Delete current avatar
  //6: Exit the program
void menuType::process(stackType & allAvatars)
{
  int status = 0;  //Status integer to handle the status returns of functions
  avatarType tempAvatar;

  char * temp = new char [TEMP_SIZE];
  int len = 0;               //Used for 'measuring' arrays
  char response;             //Used for responses to prompts

  switch (choice)
  {
    case 1:  //Add a new avatar
       cout << "Add a new Avatar" << endl << endl;
      //Get and store the basic avatar infromation
      read_array("Name: ",temp,TEMP_SIZE);     //Reads in the array
      len = strlen(temp);                      //Gets its length
      tempAvatar.name = new char[len + 1];     //Allocates memory for the array in the temp
      strcpy(tempAvatar.name, temp);           //Copies the array
      read_int("Ranking: ", tempAvatar.rank);  //Reads in the rank of the avatar

      //Insert into main stack
      status = allAvatars.push(tempAvatar);    //Pushes the new avatar onto the stack
      if(status)
        cout << "Sucessfully Added" << endl;
      break;
    case 2:  //View current Avatar (or select)
      cout << "View current Avatar" << endl << endl;
      status = allAvatars.peek(tempAvatar);    //Retrieves ('peeks') the current avatar
      if(status)  //If it exists, output it
      {
        cout << "Name:    " << tempAvatar.name << endl;
        cout << "Ranking: " << tempAvatar.rank << endl;
       }
       else      //Else, error message
         cout << "There are no avatars" << endl;
      break;
    case 3:
      cout << "Access Weapon Interface" << endl;
      if(allAvatars.isEmpty())                  //Checks if there are any avatars
        cout << "Threre are no avatars to have weapons (no avatars exist)" << endl;
      else                                      //If there are, it
        while(weaponInterface(allAvatars));     //Calls the weapon interface untill the user is finished
      break;
    case 4:  //View all avatars
      cout << "View all avatars" << endl << endl;
      status = allAvatars.dispAll();            //Displays all of the current avatars
      if(!status)                               //Or an error message
        cout << "There were no avatars to display" << endl;
      break;
    case 5:  //Delete current avatar
      cout << "Delete current avatar" << endl << endl;
      status = allAvatars.pop(tempAvatar);      //Deletes all of the avatars
      if(status)
        cout << "Avatar '" << tempAvatar.name << "' has been successfully deleted." << endl;  //Outputs the name of the deleted avatar
      else
        cout << "There are no avatars to delete" << endl;
      break;
    case 6:  //Exit program
      cout << "Exiting Program" << endl;
      break;
    default:
      cout << "That is not a valid choice." << endl;
      break;
  }

  delete [] temp;  			//Deletes the temporaray variable
}


//Displays the menu for the weapon interface
void menuType::dispWeaponMenu()
{
  cout << endl;
  cout << "  ------------------" << endl;
  cout << "  -Weapon Interface-" << endl;
  cout << "  ------------------" << endl;
  cout << "  1: View current weapon" << endl;
  cout << "  2: Add a new Weapon" << endl;
  cout << "  3: Delete current weapon" << endl;
  cout << "  4: View all weapons" << endl;
  cout << "  5: Remove all weapons" << endl;
  cout << "  6: Exit Weapons interface" << endl;
}


//Main loop for the weapon interface
//The options can be seen directly above in the menu function
bool menuType::weaponInterface(stackType & allAvatars)
{
  dispWeaponMenu();                      //Displays the menu
  cout << "  ";                          //Spacing
  choose();                              //Gets the user's choice

  weaponType tempWeapon;                 //Creates a temporary weapon variable to work with

  char * temp = new char[TEMP_SIZE];     //Creates a temporary variable to work with
  int len = 0;                           //Used to 'measure' arrays
  int status = 0;                        //Used to catch a returned status

  bool againResult;                      //Used to catch the return from the again() function

  switch(choice)
  {
    case 1:
      cout << "  View Current Weapon" << endl << endl;
      status = allAvatars.peekWeapon(tempWeapon);   //Retrieves the current weapon
      if(status)                                    // and displays it if it exist
      {
        cout << "  Current Weapon " << endl;
        cout << "  Name:  " << tempWeapon.name << endl;
        cout << "  Power: " << tempWeapon.pwr << endl;
        cout << "  Speed: " << tempWeapon.speed << endl;
      }
      else
        cout << "  There are no current weapons" << endl;
      break;
    case 2:
      cout << "  Add Weapon" << endl;               //Adds a weapon to the weapon queue
      read_array("  Name: ", temp, TEMP_SIZE);
      len = strlen(temp);
      tempWeapon.name = new char[len + 1];
      strcpy(tempWeapon.name,temp);
      read_int("  Power: ", tempWeapon.pwr);
      read_int("  Speed: ", tempWeapon.speed);
      //Store the information
      status = allAvatars.enqueueWeapon(tempWeapon);//Enqueue's the prepared tempWeapon variable
      if(status)
        cout << "  Succesfully Added" << endl;
      break;
    case 3:
      cout << "  Remove Current Weapon" << endl;
      status = allAvatars.dequeueWeapon(tempWeapon);//Calls the dequeue function for the weapon queue
      if(status)
        cout << "  Sucessfully deleted '" << tempWeapon.name << "' " << endl;
      else
        cout << "  There are no weapons to delete" << endl;
      break;
    case 4:
      cout << "  View All Weapons" << endl;
      status = allAvatars.dispAllWeapon();         //Displays all weapons
      if(!status)
        cout << "  There are no weapons to display." << endl;
      break;
    case 5:
      cout << "  Remove All Weapons" << endl;
      status = allAvatars.deleteAllWeapons();      //Deletes all weapons
      cout << "  All weapons have been removed." << endl;
      break;
    case 6:
      cout << "  Exiting Weapons Interface" << endl;
      break;
    default:
      cout << "  That is not a valid option. Please try again " << endl;
      break;
  }
  delete [] temp;

  againResult = again();  //Checks to see if the user wants to continue
  choice = 2;             //Makses it so that the main loop does not exit
  return againResult;     //Returns the continue condition
}
