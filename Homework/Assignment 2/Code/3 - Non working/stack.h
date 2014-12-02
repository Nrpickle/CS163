/*
Nick McComb CS163
2/5/2013

Assignment #2

This is the stack header file
And also includes the avatar implementation
*/


//Handles the avatar information
struct avatarType
{
  char * name;
  int rank;
  queueType weapons;
};


struct stackNode
{
  stackNode();
  ~stackNode();
  avatarType avatar;
  stackNode * next;

  int data;  //Relic
};


class stackType
{
  public:
    stackType();
    ~stackType();
    int push(const stackNode & newData);
    int pop(stackNode & foundData);
    int peek(stackNode & foundData);
    int isEmpty();

    void debugDisp();
  private:
    stackNode * head;
};


