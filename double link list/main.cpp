#include <iostream>
#include "DoubleLinkList.h"

using namespace std;
void main() {
	DoubleLinkList* List = new DoubleLinkList();

	List->AddNewItem(5);
	List->PrintForward();
	cout << endl;
	
	List->AddNewItem(7);
	List->PrintForward();
	cout << endl;
	List->AddNewItem(6);
	List->PrintForward();
	cout << endl;
	List->AddNewItem(4);
	List->PrintForward();
	cout << endl;
	List->AddNewItem(9);
	List->PrintForward();
	cout << endl;
	List->AddNewItem(8);
	List->PrintForward();
	cout << endl;

	//(Temp != NULL)
	system("Pause");
}