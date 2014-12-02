//This function appends a node onto the end of the linear linked list
void mappingType::appendNode()
{
  node * temp = new node;
  temp->next = NULL;           //Node is going to be appended at end

  if(!head)                    //If head is NULL, insert at head
    head = temp;      
  else                         //Else, traverse to the end
  {
    node * current = head;     //Create a new current pointer
    while(current->next)       //Traverse to the end
      current = current->next;
    current->next = temp;      //Append the temp node at the end
  }
  ++nodeNum;                   //Increase the number of nodes
}