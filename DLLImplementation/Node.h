#ifndef NODE_H
#define NODE_H
#include <string>
class Node
{
private:
	Node* next;
	Node* previous;
	int customerId;
	std::string customerFirst;
	std::string customerLast;
	double customerBalance;
	double customerSpent;

public:
	Node(int, std::string, std::string, double, double);
	Node();
	int getId();
	std::string getFirst();
	std::string getLast();
	double getBal();
	double getSpent();
	Node* getPrev();
	Node* getNext();
	void setFirst(std::string);
	void setLast(std::string);
	void setBal(double);
	void setSpent(double);
	void setPrev(Node*);
	void setNext(Node*);
};

#endif

