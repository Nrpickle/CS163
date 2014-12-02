/*
Nick McComb CS163

Assignment #4

This is the header class for the menu class that acts as the client program
*/

class treeClass; //Tree Class Prototype

class menuType
{
  public:
    menuType();  //Default Constructor
    ~menuType(); //Default Destructor
    void disp(); //Displays the menu
    bool again();   //Determines if the user wants to continue
    void choose();  //Asks the user to choose a selection and stores it in choice
    void process(treeClass & topic, treeClass & course); //Processes the choice that the user selects
  private:
    int choice;  //Holds the user's choice
};


