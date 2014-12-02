
/*
Nick McComb CS163
2/5/2013

Assignment #2
*/


struct queueNode
{
  queueNode();
  ~queueNode();
  int data;
  queueNode * next;
};



class queueType
{
  public:
    queueType();
    ~queueType();
    int enqueue(const queueNode & newData);
    int dequeue(queueNode & foundData);
    int peek(queueNode & foundData);
    int isEmpty();
  private:
    queueNode * tail;
};



