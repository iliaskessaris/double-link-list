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

public:
	DoubleLinkList();
	~DoubleLinkList();
	void PrintForward();
	void PrintReverse();
	void AddItemAtBegining(int newdata);
};

#endif