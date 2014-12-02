#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * head2 = NULL;
	
	cout << "List 1" << endl;
    build(head);
    display(head,-99);

	
	cout << endl << "List 2" << endl;
	build(head2);
	display(head2,-99);
	
/*	
	cout << endl << "Seach for numbers:" << endl;
	for(int i = 0; i < 100; ++i)
      if(find(head, i))
	    cout << "Found " << i << endl;
*/

//    insert_9(head);

/*    
	cout << "Display Last Two" << endl;
	display_last_two(head);
*/
    cout << endl;
    
	if(same_length(head,head2))
		cout << "The lists are the same length!" << endl;
	else
		cout << "The lists are not the same length!" << endl;

	cout << endl << "Display Last Two" << endl;
	display_last_two(head);
		
	cout << endl << "Insert 9 to first list" << endl << endl;
	insert_9(head);

	cout << "Display Last Two" << endl;
	display_last_two(head);
	
	display(head,0);
	
	cout << endl;
	
	if(same_length(head,head2))
		cout << "The lists are the same length!" << endl;
	else
		cout << "The lists are not the same length!" << endl;	
		
//    display(head,0);
    
    return 0;
}

