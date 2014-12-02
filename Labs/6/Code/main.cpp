#include "list.h"
using namespace std;

int main()
{
    list my_list;
    my_list.display(-99);
    cout << endl << endl;
	
	
    my_list.display_all();

	cout << endl << "Count of first: " << my_list.count_first() << endl;
	
	cout << endl;
	 
	if(my_list.last_occurance())
	  cout << "Last node occurs more than once" << endl;
	else
	  cout << "Last node does not repeat" << endl;

	cout << "Appending 400000000" << endl;
	my_list.append(400000000);
	
	
	if(my_list.last_occurance())
	  cout << "Last node occurs more than once" << endl;
	else
	  cout << "Last node does not repeat" << endl;
	
	cout << "Removing last" << endl;
	my_list.remove_last();

	if(my_list.last_occurance())
	  cout << "Last node occurs more than once" << endl;
	else
	  cout << "Last node does not repeat" << endl;
		
	
	
    my_list.display(0);
    
	
	
    return 0;
}
