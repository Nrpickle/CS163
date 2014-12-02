/*
Nick McComb CS163

Assignment #4
*/

#include "tree.h"

courseData::courseData()
{
  course = NULL;
  topic = NULL;
  
  directory = NULL;
  year = 0;
}

courseData::~courseData()
{
  delete [] course;
  delete [] topic;
  delete [] directory;
}

courseClass::courseClass()
{

}

void courseClass::insertCourse(char newCourse[])
{
  int len = strlen(newCourse);
  data.course = new char[len + 1];
  strcpy(data.course, newCourse);
}

void courseClass::insertTopic(char newTopic[])
{
  int len = strlen(newTopic);
  data.topic = new char[len + 1];
  strcpy(data.topic, newTopic);
}

void courseClass::insertDirectory(char newDirectory[])
{
  int len = strlen(newDirectory);
  data.directory = new char[len + 1];
  strcpy(data.directory, newDirectory);
}

//Returns 1 if there was a topic found and a 0 if there was not
	//0 - No class found
	//1 - Class found
int courseClass::getTopic(char * & foundTopic)
{
  if(data.topic)
  {
    int len = strlen(data.topic);
	foundTopic = new char[len + 1];
	strcpy(foundTopic, data.topic);
	return 1;
  }
  else
    return 0;
}


//Returns 1 if there was a course found and a 0 if there was not
	//0 - No class found
	//1 - Class found
int courseClass::getCourse(char * & foundCourse)
{
  if(data.course)
  {
    int len = strlen(data.course);
	foundCourse = new char[len + 1];
	strcpy(foundCourse, data.course);
	return 1;
  }
  else
    return 0;
}

//Returns 1 if there was a course found and a 0 if there was not
	//0 - No class found
	//1 - Class found
int courseClass::getDirectory(char * & foundDirectory)
{
  if(data.directory)
  {
    int len = strlen(data.directory);
	foundDirectory = new char[len + 1];
	strcpy(foundDirectory, data.directory);
	return 1;
  }
  else
    return 0;
}



int courseClass::validData()
{
  if(data.course && data.topic && data.directory)
    return 1;
  return 0;
}


//BEGIN BINARY SEARCH TREE IMPLEMENTATION

treeClass::treeClass()
{
  root = NULL;
}

int treeClass::insert(int data)
{
  addAtEnd(root, data);
}

void treeClass::addAtEnd(node * & root, int data)
{
  if(!root)  //Simple Case
  {
    root = new node;
	root->data = data;
	root->left = root->right = NULL;
	cout << "--Inserted Node" << endl;
  }
  else if (data < root->data)   //Move left
    addAtEnd(root->left, data);
  else
    addAtEnd(root->right, data);//Move right
}



int treeClass::displayAll()
{
  if(!root)
    return 0;
	
  display(root);
  return 1;
}

void treeClass::display(node * root)
{
  if(root->left)
    display(root->left);

  cout << root->data << endl;
  
  if(root->right)
    display(root->right);
}












