#include "table.h"
using namespace std;

int main()
{
    table BST;	
	table BST2;
    BST.build();
    BST.display();

    cout << endl << "Leaf Count: " << BST.count() << endl;
	cout << "Height: " << BST.height() << endl;
    cout << "Sum: " << BST.sum() << endl;
	
	BST2.copy(BST);
	
	
    BST.display(0);

	BST2.display(0);

	BST.remove_all();
	
	BST.display(0);
	
    return 0;
}
