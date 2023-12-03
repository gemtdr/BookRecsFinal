#pragma once
#include "Book.h"
using namespace std;

struct Node {
	Book inputBook;
	Node* nextPtr;
};

class Linked {
private:
	Node* headPtr;
	Node* tailPtr;
public:
	Linked();
	void addNode(Book d);
	void delNode(Book d);
	void printList();

};
