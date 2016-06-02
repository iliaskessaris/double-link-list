#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H

class DoubleLinkList {
private:
	struct DoubleNode {
		int data;
		DoubleNode* next;
		DoubleNode* prev;
	};

	DoubleNode* Head;
	DoubleNode* Tail;

	void InsertNodeIntoList(int newdata, DoubleNode* Temp);
	void DeleteNodeFromList(DoubleNode* Temp);

public:
	DoubleLinkList();
	~DoubleLinkList();
	void PrintForward();
	void PrintReverse();
	void AddNewItem(int newdata);
	void DeleteItem(int existingdata);
	void StoreListToFile();
	void ReadListFromFile();
};

#endif
