#include <iostream>
#include "doublyLL.cpp"
using namespace std;

int main()
{
	doublyLL list;
	list.insertNodeAtEnd(1);
	list.insertNodeAtEnd(2);
	list.insertNodeAtEnd(3);
	list.insertNodeAtEnd(4);
	list.insertNodeAtEnd(4);
	list.insertNodeAtEnd(4);
	list.insertNodeAtEnd(4);
	list.insertNodeAtEnd(4);
	list.insertNodeAtEnd(5);
	list.insertNodeAtEnd(6);
	list.insertNodeAtEnd(7);
	list.insertNodeAtEnd(8);
	list.insertNodeAtEnd(9);
	list.insertNodeAtEnd(10);
	list.insertNodeAtEnd(11);
	list.insertNodeAtEnd(12);
	list.insertNodeAtEnd(13);
	list.insertNodeAtEnd(14);
	list.insertNodeAtEnd(15);
	list.insertNodeAtEnd(16);
	list.print_list();
	list.deleteNode(4);
	list.print_list();
	return 0;
}