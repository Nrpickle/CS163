/*
Nick McComb CS163

*/

class tableType;  //tableType prototype

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
    int choice;  //Holds the user's choice
};
