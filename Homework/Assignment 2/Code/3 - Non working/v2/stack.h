/*
Nick McComb CS163
2/5/2013
*/



struct stackNode
{
  int data;
  stackNode * next;
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
