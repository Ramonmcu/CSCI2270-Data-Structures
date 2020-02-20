#include <iostream>

using namespace std;


struct Node
{
	int ID;
	Node* next=NULL;
};

Node* createNode(int nodeID, Node* nextNode)
{
	Node* newNode= new Node;
	newNode->ID=nodeID;
	newNode->next=nextNode;
	return newNode;
}

Node* insertNode(Node* head, int newNodeID)
{

		Node* currentNode=head;
		while(currentNode != NULL)
		{
			if(currentNode->ID %2 ==0)
			{
				Node* newNode=createNode(newNodeID,currentNode->next);
				currentNode->next=newNode;			

			}
			currentNode=currentNode->next;

		}

return head;		
}

Node* insertNodes(Node* head, int newNodeID)
{
	if(head==NULL)
	{
		Node* newNode = createNode(newNodeID,NULL);
		head=newNode;
	}
	else
	{
		Node* currentNode=head;
		while(currentNode->next != NULL)
		{
			currentNode=currentNode->next;
		}
		Node* newNode=createNode(newNodeID,NULL);
		currentNode->next=newNode;
		}
		return head;
}

void printlist(Node*head)
{
	if(head==NULL)
	{
		cout<<"empty list!"<<endl;
	}
	else
	{
		Node* currentNode=head;
		while(currentNode != NULL)
			{
				cout<<"Node ID:"<<currentNode->ID<<endl;
				currentNode=currentNode->next;
			}
	}
}

int main()
{
	Node* head = NULL;
	head = insertNodes(head,1);
	head = insertNodes(head,2);
	head = insertNodes(head,3);
	head = insertNodes(head,4);
	printlist(head);
	cout<<"new list"<<endl;
	head=insertNode(head,3);
	printlist(head);
	
}