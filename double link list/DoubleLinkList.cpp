#include <iostream>
#include "DoubleLinkList.h"

using namespace std;

//Constructor function of DoubleLinkList class.
DoubleLinkList::DoubleLinkList() {
	Head = NULL;
	Tail = NULL;
}

//Destructor function of DoubleLinkList class.
DoubleLinkList::~DoubleLinkList() {
	DoubleNode* Temp;
	while (Head != NULL) {
		Temp = Head;
		Head = Head->next;
		delete(Temp);
	}
}

//Traverses forward the double link list and prints its data.
void DoubleLinkList::PrintForward() {
	DoubleNode* Temp = Head;
	while (Temp !=NULL) {
		cout << Temp->data << endl;
		Temp = Temp->next;
	}
}

//Traverses reverse the double link list and prints its data.
void DoubleLinkList::PrintReverse() {
	DoubleNode* Temp = Tail;
	while (Temp != NULL) {
		cout << Temp->data << endl;
		Temp = Temp->prev;
	}
}

//Add an item at the begining of the List.
void DoubleLinkList::AddItemAtBegining(int newdata) {
	DoubleNode* Temp=new DoubleNode();

	Temp->data = newdata;
	Temp->prev = NULL;
	Temp->next = Head;
	Head = Temp;
	if (Tail == NULL) {
		Tail = Temp;
	}
}