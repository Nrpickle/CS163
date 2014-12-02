//This class was prepared for a binary search tree implementation of
//a table abstraction. For the lab we will keep the underlying data
//simple - just an integer.
//
//Please see below for the prototypes that you will be implementing!
//These must be implemented before you can compile and run.

#include <iostream>
#include <cstring>
#include <cctype>

struct node
{
    int data;
    node * left;
    node * right;;
};

class table
{
    public:
	table();
	~table();
	int build(); //All of these functions are provided for you
	int display(int=-99);  //Provided for you. Send in zero for the final result

	//  ***These functions have been written for you   
	int count(); 	//These functions are called wrapper functions and
 	int height();	//simply call the private version of the functions
	int copy(const table & to_copy); //that you will be writing!
	int sum();
	int remove_all();

    private:

	node * root;

	//  ***These are the functions you will be writing recursively!
	int count (node * root);	//STEP 1.1
	int height (node * root);	//STEP 1.2
	int copy (node * & destination, node * source);	//STEP 1.3
	int sum (node * root);		//STEP 1.4
	int remove_all(node * & root);	//STEP 1.5	


};






 
  

