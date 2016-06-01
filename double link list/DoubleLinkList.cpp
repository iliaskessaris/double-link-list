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

//Add an item in the list.
void DoubleLinkList::InsertNodeIntoList(int newdata, DoubleNode* Temp) {
	DoubleNode* Item = new DoubleNode;
	Item->data = newdata;

	if (Head  == NULL) {
		Item->prev = NULL;//Insert first node in the list.
		Item->next = NULL;
		Head = Item;
		Tail = Item;
	} else if (Head == Temp && Temp != NULL) {
			Item->prev = NULL; //Insert at the begining of the list.
			Item->next = Head;
			Head = Item;
			} else if (Head != NULL && Temp == NULL) {
				Item->next = NULL;  //Insert at the end of the list.
				Item->prev = Tail;
				Tail->next = Item;
				Tail = Item;
			} 	else {
					Item->prev = Temp->prev;  //Insert between two nodes.
					Item->next = Temp;
					Temp->prev->next = Item;
					Temp->prev = Item;
				}
}


//Search the list for the appropriate place to add a new node.
void DoubleLinkList::AddNewItem(int newdata) {
	DoubleNode* Temp = Head;

	while (Temp != NULL && newdata > Temp->data) { //How the list is build up.
		Temp = Temp->next;
	}
	InsertNodeIntoList(newdata, Temp);
}

//Delete a node from the list.
void DoubleLinkList::DeleteNodeFromList(DoubleNode* Temp) {

	if (Head == NULL) {
		cout << "The list is empty\n"; //Nothing to delete the list is empty.
	}
	else if (Head == Tail && Tail != NULL) {
		delete(Head); //Delete the first node when there is not second.
		Head = NULL;
		Tail = NULL;
	}
	else if (Head == Temp && Temp != NULL) {
		Head = Head->next; //Delete a node from the begining of the list.
		Head->prev = NULL;
		delete(Temp);
	}
	else if (Head != NULL && Temp == Tail) {
		Tail = Tail->prev; //Delete last node.
		delete(Tail->next);
		Tail->next = NULL;
	}
	else {
		Temp->prev->next = Temp->next; //Delete a node between two others.
		Temp->next->prev = Temp->prev;
		delete(Temp);
	}
}

//Searches the list for the item to delete.
void DoubleLinkList::DeleteNode(int existingdata) {
	DoubleNode* Temp = Head;

	while (Temp != NULL && existingdata != Temp->data) {
		Temp = Temp->next; //Search the list for the item to delete.
	}
	if (existingdata == Temp->data) {
		DeleteNodeFromList(Temp);
	}
}