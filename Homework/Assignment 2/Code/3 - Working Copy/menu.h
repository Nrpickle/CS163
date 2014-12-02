/*
Nick McComb CS163
2/5/2013

Assignment #2
*/


class menuType
{
  public:
    menuType();  //Default Constructor
    ~menuType(); //Default Destructor
    void disp();
    bool again();   //Determines if the user wants to continue
    void choose();  //Asks the user to choose a selection and stores it in choice
    void process(queueType & queue); //Processes the choice that the user selects
  private:
    int choice;  //Holds the user's choice
};
