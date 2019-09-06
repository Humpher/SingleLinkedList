/*
 * SNode.cpp
 *
 *  Created on: Mar 14, 2019
 *
 */



/*
 * Declaration file
 */

#include "SNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

SNode::SNode() {
	rating = 0;
	comments = "";

	cout << "Please enter the rating for this book" << endl;
	cin >> rating;
	cout << "Please enter any comments pertaining to this book" << endl;
	cin >> comments;

	next = NULL; //Assume adding a new node to the end of the linked list
}

SNode::SNode(int r, string c) {
	rating = r;
	comments = c;
	next = NULL; //Assume adding a new node to the end of the linked list
}

void SNode::printNode() {
	cout <<"Rating: " << rating << ", Comments: "<< comments << endl;
}

SNode::~SNode() {
	cout << "Deleting this node: " <<  rating <<" " <<comments << endl;
}
