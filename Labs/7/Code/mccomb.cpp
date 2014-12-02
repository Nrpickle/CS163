#include "table.h"
using namespace std;

//Nick McComb CS163

//  ***These are the functions you will be writing recursively!
int table::count (node * root){
  if(!root)
    return 0;
  
  if(!count(root->left) || !count(root->right))
    return 1;
  else
    return count(root->left) + count(root->right);  
}        


int table::height (node * root){
  if(!root)
   return 0;
  return 1 + max(height(root->left), height(root->right));
}

int table::copy (node * & destination, node * source){
  if(!source)
    destination = NULL;
	
  else
  {
    destination = new node;
	destination->data = source->data;
	copy(destination->left, source->left);
	copy(destination->right, source->right);
  }
}

int table::sum (node * root){
  if(!root)
    return 0;
	
  return sum(root->left) + sum(root->right) + root->data;
}

int table::remove_all(node * & root){
  if(!root)
    return 0;
  
  remove_all(root->left);
  remove_all(root->right);
  delete root;
  root = NULL;
}
