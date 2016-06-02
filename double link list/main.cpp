#include <iostream>
#include "DoubleLinkList.h"

using namespace std;

void MainMenu() {
	cout << "\nTo add an item in the list press 1\n";
	cout << "To delete an item in the list press 2\n";
	cout << "To print forward the list press 3\n";
	cout << "To print in reverse order the list press 4\n";
	cout << "To exit any other character\n";
}


void main() {
	DoubleLinkList* List = new DoubleLinkList();
	char choice;
	int newdata;

	List->ReadListFromFile();
	MainMenu();
	cin >> choice;
	while (choice == '1' || choice == '2' || choice == '3' || choice == '4') {
		switch (choice) {
		case '1':
			cout << "\nType number to insert in the List\n";
			cin >> newdata;
			List->AddNewItem(newdata);
			break;
		case '2':
			cout << "\nType number to delete from the list\n";
			cin >> newdata;
			List->DeleteItem(newdata);
			break;
		case '3':
			List->PrintForward();
			break;
		case '4':
			List->PrintReverse();
			break;
		}
		MainMenu();
		cin >> choice;
	}
	List->StoreListToFile();

	system("Pause");
}