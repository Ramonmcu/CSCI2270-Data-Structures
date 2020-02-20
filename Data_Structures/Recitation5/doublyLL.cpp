#include <iostream>
#include "doublyLL.h"
using namespace std;

doublyLL::doublyLL() {

}

doublyLL::doublyLL(int nodeID) {
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL() {

}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;

	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
	if (head == nullptr) {
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

bool doublyLL::deleteNode(int nodeID)
{
	Node* currentNode=head;
	while(currentNode !=NULL)
	{
		if(currentNode->id==nodeID)
		{
				
			if(currentNode == head)
			{
				currentNode->next->prev=NULL;
				delete currentNode;
			}
			else if(currentNode	== tail)
			{
				currentNode->prev->next=currentNode->next;
				delete currentNode;
			}
			else
			{
				currentNode->next->prev	= currentNode->prev;
				currentNode	->prev->next=currentNode->next;
				delete currentNode;
			}
		}
		currentNode=currentNode->next;
	}		
}

void doublyLL::print_list()
{
	Node* temp= head;
	while(temp !=NULL)
	{
		cout<< temp->id<<endl;
		temp=temp->next;
	}
}









