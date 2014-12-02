/*
Nick McComb CS163
Assignment #3

*/

#include "table.h"

tableType::tableType()
{

}

tableType::~tableType()
{

}


//Hash function
int tableType::hash(char key[])
{
  int len = strlen(key);
  if(len < 2)
    return key[0];
  else
  {
    return key[0] + key[len - 1];
  }

}


