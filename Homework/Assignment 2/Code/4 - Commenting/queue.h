/*
Nick McComb CS163
2/12/2013

Assignment #2

This is the header file for the weapon queue ADT.
*/

//This contains the data that comprises a weapon
struct weaponType
{
  char * name;   //The weapon's name
  int pwr;       //power
  int speed;     //and speed
};

//Makes up the node an item in the queue
struct queueNode
{
  queueNode();    //Default constructor
  ~queueNode();   //Default destructor

  weaponType weapon;  //Handles the information

  queueNode * next;   //Points to the next node in the list
  int data;       //Contains a unique identifier to itentify an individual node
};


//Controls the weapon queue
//This ADT employes a Circular Linked List
class queueType
{
  public:
    queueType();      //Default constructor
    ~queueType();     //Default destructor
    int enqueue(const weaponType & newWeapon);  //Adds a new weapon the queue
    int dequeue(weaponType & foundWeapon);      //Removes a weapon from the queue
    int peek(weaponType & foundWeapon);         //Returns an item's contents w/o removing it
    int dispAll();    //Display all of the weapons in the list
    int isEmpty();    //Returns if the queue is empty
    int deleteAll();  //Deletes all of the weapons in the queue
  private:
    queueNode * tail; //The tail pointer for the Circular Linked List
    int id;           //Helps identify individual nodes
};



