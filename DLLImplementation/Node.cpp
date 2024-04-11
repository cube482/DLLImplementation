#include "Node.h"

Node::Node() {
	this->customerId = -1;
	this->customerFirst = "NULL";
	this->customerLast = "NULL";
	this->customerBalance = -1;
	this->customerSpent = -1;
	this->previous = nullptr;
	this->next = nullptr;
}

Node::Node(int customerId, std::string customerFirst, std::string customerLast, double customerBalance, double customerSpent) {
	this->customerId = customerId;
	this->customerFirst = customerFirst;
	this->customerLast = customerLast;
	this->customerBalance = customerBalance;
	this->customerSpent = customerSpent;
	this->previous = nullptr;
	this->next = nullptr;
}

void Node::setFirst(std::string customerFirst) { this->customerFirst = customerFirst; }

void Node::setLast(std::string customerLast) { this->customerLast = customerLast;  }

void Node::setBal(double customerBalance) { this->customerBalance = customerBalance; }

void Node::setSpent(double customerSpent) { this->customerSpent = customerSpent; }

void Node::setPrev(Node* input) { this->previous = input; }

void Node::setNext(Node* input) { this->next = input; }

int Node::getId() { return this->customerId; }

std::string Node::getFirst() { return this->customerFirst; }

std::string Node::getLast() { return this->customerLast; }

double Node::getBal() { return this->customerBalance; }

double Node::getSpent() { return this->customerSpent; }

Node* Node::getPrev() { return this->previous; }

Node* Node::getNext() { return this->next; }