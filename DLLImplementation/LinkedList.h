#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
private:
	Node* start;
public:
	struct Result {
		int count;
		Node** arr;
	};
	LinkedList();
	bool isDuplicate(Node*);
	void add(Node*);
	Node* searchById(int);
	Result* searchByFirst(std::string);
	Result* searchByLast(std::string);
	Result* searchByBalance(double);
	Result* searchBySpent(double);
	void printResult(LinkedList::Result*);
	void printResult(Node*);
	void printAll();
	void delRec(int);
};
#endif
