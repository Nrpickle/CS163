/*
Nick McComb CS163
2/12/2013

Assignment #2

This is the stack header file
And also includes the avatar declaration
*/


//Handles the avatar information
struct avatarType
{
  avatarType();
  ~avatarType();
  char * name;
  int rank;
  queueType weapons;
};

//Handles the information that is in a struct node
struct stackNode
{
  stackNode();     //Default Constructor  
  ~stackNode();    //Default Destructor
  stackNode * next;//Points to the next node

  avatarType avatar;//Contains the information

};


class stackType
{
  public:
    stackType();
    ~stackType();

    int push(const avatarType & newAvatar);
    int pop(avatarType & foundAvatar);
    int peek(avatarType & foundAvatar);

    int enqueueWeapon(const weaponType & weapon);
    int dequeueWeapon(weaponType & foundWeapon);
    int peekWeapon(weaponType & foundWeapon);
    int dispAllWeapon();
    int deleteAllWeapons();

    int isEmpty();

    int dispAll();
  private:
    stackNode * head;
};


