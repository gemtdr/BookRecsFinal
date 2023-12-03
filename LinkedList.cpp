#include "LinkedList.h"

Linked::Linked() {

    //blank constructor

	headPtr = nullptr;
	tailPtr = nullptr;
}

void Linked::addNode(Book d) {

    //PRE: take book object input
    //POST: add to list based on number of points

    Node* tempNode = new Node;
    tempNode->inputBook = d;
    tempNode->nextPtr = nullptr;

    if (headPtr == nullptr) { //if list is empty
        headPtr = tempNode;
        tailPtr = tempNode;
    }
    else {
        if (tempNode->inputBook.getPts() > headPtr->inputBook.getPts()) {
            tempNode->nextPtr = headPtr;
            headPtr = tempNode;
        }
        else {
            Node* tempPtr = headPtr;

            while (tempPtr->nextPtr != nullptr && tempNode->inputBook.getPts() < tempPtr->nextPtr->inputBook.getPts()) {
                tempPtr = tempPtr->nextPtr;
            }

            tempNode->nextPtr = tempPtr->nextPtr;
            tempPtr->nextPtr = tempNode;

            if (tempPtr == tailPtr) {
                tailPtr = tempNode;
            }
        
       
        }
        
    }
}

void Linked::delNode(Book d) {

    //PRE: Take book object
    //POST: delete book object from linked list

    Node* tempNode = headPtr;
    Node* delNode;
    if (tempNode != nullptr &&
        tempNode->inputBook.getTitle() == d.getTitle()) {
        headPtr = headPtr->nextPtr;
        delete tempNode;
        tempNode = nullptr;
    }
    else {
        while (tempNode != nullptr &&
            tempNode->nextPtr != nullptr) {
            if (tempNode->nextPtr->inputBook.getTitle() == d.getTitle()) {
                delNode = tempNode->nextPtr;
                tempNode->nextPtr = tempNode->nextPtr->nextPtr;
                if (tempNode->nextPtr == tailPtr)
                    tailPtr = tempNode;
                delete delNode;
                delNode = nullptr;
            }
            tempNode = tempNode->nextPtr;
        }
    }
}

void Linked::printList() {

    //PRE: Reference linked list object
    //POST: Print the top 10 items, so those with the most points

    Node* tempNode = headPtr;
    int i = 10;
    while (tempNode != nullptr && i > 0) {
        i--;
        cout << tempNode->inputBook.getTitle() << " by " << tempNode->inputBook.getAuthor() << " PTS: " << tempNode->inputBook.getPts() << endl << endl;
        tempNode = tempNode->nextPtr;
    }
}
