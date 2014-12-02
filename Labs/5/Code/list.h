//list.h
#include <iostream>
#include <cstring>
#include <cctype>


struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head, int unused); //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
/* These are the prototypes for the functions you will be writing for LAB #5 */
//Step1
bool find(node * head, int match); //return true if there is a match in the list

//Step2
void insert_9(node * & head);      //insert number 9 after each number 2 in the list

//Step3
void display_last_two(node * head); //display the last two items in teh list

//Step4
bool same_length(node * head1, node * head2); //see if they are the same length!
