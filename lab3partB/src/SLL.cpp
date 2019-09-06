/*
 * SLL.cpp
 *
 *  Created on: Mar 14, 2019
 *
 */




#include "SLL.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}

void SLL::printSLL() {
	SNode *tmp = first;

	while (tmp != NULL) {
		tmp->printNode();
		tmp = tmp -> next; //Putting next’s address into tmp
	}
	cout << endl;

}

void SLL::insertInOrder(int r, string c) {

	//This method creates an ordered linked list (ordered by the rating).  If the
	//linked list is empty, it calls addFirst with r and c.  If the rating is less
	//than the first node’s rating in the list, it calls addAtFirst.  If the
	//rating is greater than the last node’s rating, it calls the push method.
	//Otherwise it creates a new node using r and c, and inserts that node in
	//order into the linked list.

	if (size == 0) {
		addFirst(r,c);
		return; //Exit the function
	}

	int firstRating = first -> rating;
	if (r < firstRating) {
		addAtFront(r,c);
		return; //Exit the function
	}

	int lastRating = last -> rating;
	if (r > lastRating) {
		push(r,c);
		return; //Exit the function
	}

	SNode *tmp = first;
	while (r > (tmp -> next -> rating)) {
		//Checking current node's rating with the next node's rating
		//Continue traversing if the rating is greater than next in linked list
		tmp = tmp -> next;
	}

	SNode *n = new SNode(r,c);
	n -> next = tmp -> next;
	tmp -> next = n;
	size++;
}

void SLL::push(int r, string c) {
	// pushes a new node (with rating r and c comments) onto the end of the linked list
	SNode *n = new SNode(r,c);

	last -> next = n;
	last = n; //makes the last point to the new last (n)
	size++;
}

void SLL::addAtFront(int r, string c) {
	SNode *n = new SNode(r,c);
	n -> next = first;
	first = n;
	size++;
}

void SLL::addFirst(int r, string c) {
	first = new SNode(r,c);
	size = 1;  //Size is now 1 since only one element in linked list
	last = first; //The first node is also the last node
}

int SLL::pop() {
	//remove the last node
	//returns the rating from the node removed

	SNode *tmp = first;
	for(int i=0; i< size-2;i++) {
		tmp = tmp -> next;
	}

	int x = last -> rating;
	delete last;
	last = tmp;
	last -> next = NULL;

	size = size-1;

	return x;
}

double SLL::getAve() {
	// calculates the average rating (by traversing the list) and then returns the average rating.
	double ave = 0;
	SNode *tmp = first;
	for(int i=0; i< size;i++) {
		ave += tmp -> rating;
		tmp = tmp -> next;
	}

	return (ave/size);
}

SLL::~SLL() {
	SNode *tmp = first;
	SNode *holder = first;
	for (int i= 0; i<size;i++) {
		holder = tmp -> next;
		delete tmp;
		tmp = holder;

	}
	cout << "Deleted each node is this LL" << endl;
}





