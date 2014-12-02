/*
Nick McComb CS163
2/122013

Assignment #2

This is the header file for the class that controls the 
client program. This is the class that interacts with the 
ADT's. It inputs and outputs nearly all of the information.
*/


class menuType
{
  public:
    menuType();  //Default Constructor
    ~menuType(); //Default Destructor
    void disp(); //Displays the menu
    void dispWeaponMenu(); //Displays the menu for the weapons interface
    bool again();   //Determines if the user wants to continue
    void choose();  //Asks the user to choose a selection and stores it in choice
    void process(stackType & allAvatars); //Processes the choice that 
                                          //the user selects
    bool weaponInterface(stackType & allAvatars);  //The main execcutable part of a loop that
                                                   //controls access to the weapon interface
  private:
    int choice;  //Holds the user's choice
};
