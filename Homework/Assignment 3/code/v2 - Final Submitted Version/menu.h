/*
Nick McComb CS163

Assignment #3
2/21/2013

This is the header file for the menu class
*/

class tableType;   //tableType prototype
class commandType; //commandType prototype

class menuType
{
  public:
    menuType();  //Default Constructor
    ~menuType(); //Default Destructor
    void disp(); //Displays the menu
    bool again();   //Determines if the user wants to continue
    void choose();  //Asks the user to choose a selection and stores it in choice
    void process(tableType & table); //Processes the choice that the user selects
  private:
    int readCommandInfo(commandType & tempCommand);  //Reads in the command details 
                                                     //from the user
    int choice;  //Holds the user's choice
};
