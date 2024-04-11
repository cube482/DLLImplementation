#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <iomanip>

LinkedList::LinkedList() {
	this->start = nullptr;
}

bool LinkedList::isDuplicate(Node* input) {
	Node* temp = this->start;
	while (temp != nullptr) {
		if (temp->getId() == input->getId()) {
			return true;
		}
		else if (temp == nullptr) {
			return false;
		}
		else {
			temp = temp->getNext();
		}
	}
	return false;
}

void LinkedList::add(Node* input) {
	bool set = false;
	if (this->isDuplicate(input) && this->start != nullptr) {
		std::cout << "Duplicate entry! Customer ID:" << input->getId() << " already exists!\n " << std::endl;
		return;
	}
	if (this->start == nullptr) {
		this->start = input;
		set = true;
	}
	Node* temp = this->start;
	while (temp->getId() < input->getId() && set == false) {
		if (temp->getNext() == nullptr) {
			temp->setNext(input);
			input->setPrev(temp);
			set = true;
		}
		else {
			if (set == false) {
				temp = temp->getNext();
			}
		}
	}
	if (temp->getPrev() == nullptr && set == false) {
		start = input;
		input->setNext(temp);
		temp->setPrev(input);
		set = true;
	}
	else {
		if (set == false) {
			temp->getPrev()->setNext(input);
			input->setPrev(temp->getPrev());
			input->setNext(temp);
			temp->setPrev(input);
		}
	}
}

Node* LinkedList::searchById(int id) {
	Node* temp = this->start;
	while (temp != nullptr) {
		if (temp->getId() == id) {
			return temp;
		}
		temp = temp->getNext();
	}
	return nullptr;
}

LinkedList::Result* LinkedList::searchByFirst(std::string first) {
	Node* temp = this->start;
	Node** arr;
	int count = 0;
	std::vector<Node*> collect;
	LinkedList::Result* ret = new LinkedList::Result;
	while (temp != nullptr) {
		if (temp->getFirst() == first) {
			collect.push_back(temp);
			count++;
		}
		temp = temp->getNext();
	}
	if (count > 0) {
		arr = new Node * [count];
		for (int i = 0; i < count; i++) {
			arr[i] = collect.at(i);
		}
		ret->arr = arr;
		ret->count = count;
		return ret;
	}
	else {
		return nullptr;
	}
}

LinkedList::Result* LinkedList::searchByLast(std::string last) {
	Node* temp = this->start;
	Node** arr;
	int count = 0;
	std::vector<Node*> collect;
	LinkedList::Result* ret = new LinkedList::Result;
	while (temp != nullptr) {
		if (temp->getLast() == last) {
			collect.push_back(temp);
			count++;
		}
		temp = temp->getNext();
	}
	if (count > 0) {
		arr = new Node * [count];
		for (int i = 0; i < count; i++) {
			arr[i] = collect.at(i);
		}
		ret->arr = arr;
		ret->count = count;
		return ret;
	}
	else {
		return nullptr;
	}
}
LinkedList::Result* LinkedList::searchByBalance(double balance) {
	Node* temp = this->start;
	Node** arr;
	int count = 0;
	int choice;
	std::vector<Node*> collect;
	LinkedList::Result* ret = new LinkedList::Result;
	while (temp != nullptr) {
		if (temp->getBal() == balance) {
			collect.push_back(temp);
			count++;
		}
		temp = temp->getNext();
	}
	if (count > 0) {
		arr = new Node * [count];
		for (int i = 0; i < count; i++) {
			arr[i] = collect.at(i);
		}
		ret->arr = arr;
		ret->count = count;
		return ret;
	}
	else {
		return nullptr;
	}
}
LinkedList::Result* LinkedList::searchBySpent(double spent) {
	Node* temp = this->start;
	Node** arr;
	int count = 0;
	std::vector<Node*> collect;
	LinkedList::Result* ret = new LinkedList::Result;
	while (temp != nullptr) {
		if (temp->getSpent() == spent) {
			collect.push_back(temp);
			count++;
		}
		temp = temp->getNext();
	}
	if (count > 0) {
		arr = new Node * [count];
		for (int i = 0; i < count; i++) {
			arr[i] = collect.at(i);
		}
		ret->arr = arr;
		ret->count = count;
		return ret;
	}
	else {
		return nullptr;
	}
}
void LinkedList::printResult(LinkedList::Result* result) {
	if (result == nullptr) { std::cout << "Illegal Operation: Search came back empty.\n" << std::endl; }
	else {
		std::cout << "Search Results:\n" << std::endl;
		Node** arr = result->arr;
		int i = 0;
		while (i < result->count) {
			std::cout << std::left << "Customer ID:" << std::right << std::setw(8) << arr[i]->getId() << " | " << "Name: " << std::right << std::setw(10) << arr[i]->getFirst() << " , " << std::left << std::setw(10) << arr[i]->getLast() << " | " << "Customer Balance: $"
				<< std::right << std::setw(11) << std::fixed << std::setprecision(2) << arr[i]->getBal() << std::left << " | " << "Customer Spent: $" << std::right << std::setw(11) << arr[i]->getSpent() << std::endl;
			i++;
		}
		std::cout << std::endl;
		delete result;
		delete arr;
	}
}

void LinkedList::printResult(Node* arr) {
	if (arr == nullptr) { std::cout << "Illegal Operation: Search came back empty.\n" << std::endl; }
	else {
		std::cout << "Search Results:\n" << std::endl;
		std::cout << std::left << "Customer ID:" << std::right << std::setw(8) << arr->getId() << " | " << "Name: " << std::right << std::setw(10) << arr->getFirst() << " , " << std::left << std::setw(10) << arr->getLast() << " | " << "Customer Balance: $"
			<< std::right << std::setw(11) << std::fixed << std::setprecision(2) << arr->getBal() << std::left << " | " << "Customer Spent: $" << std::right << std::setw(11) << arr->getSpent() << "\n" << std::endl;
	}
}

void LinkedList::printAll() {
	if (this->start == nullptr) { std::cout << "Illegal Operation: List is Empty\n" << std::endl; }
	else {
		Node* temp = this->start;
		while (temp != nullptr && temp->getNext() != nullptr) {
			std::cout << std::left << "Customer ID:" << std::right << std::setw(8) << temp->getId() << " | " << "Name: " << std::right << std::setw(10) << temp->getFirst() << " , " << std::left << std::setw(10) << temp->getLast() << " | " << "Customer Balance: $"
				<< std::right << std::setw(11) << std::fixed << std::setprecision(2) << temp->getBal() << std::left << " | " << "Customer Spent: $" << std::right << std::setw(11) << temp->getSpent() << std::endl;
			temp = temp->getNext();
		}
		std::cout << std::left << "Customer ID:" << std::right << std::setw(8) << temp->getId() << " | " << "Name: " << std::right << std::setw(10) << temp->getFirst() << " , " << std::left << std::setw(10) << temp->getLast() << " | " << "Customer Balance: $"
			<< std::right << std::setw(11) << std::fixed << std::setprecision(2) << temp->getBal() << std::left << " | " << "Customer Spent: $" << std::right << std::setw(11) << temp->getSpent() << "\n" << std::endl;
	}	
}

void LinkedList::delRec(int id) {
	Node* temp = this->searchById(id);
	if (temp == nullptr) { std::cout << "Cannot delete, ID number not found\n" << std::endl; }
	else {
		if (temp->getPrev() == nullptr) {
			if (temp->getNext() == nullptr) {
				this->start = nullptr;
				delete temp;
			}
			else {
				this->start = temp->getNext();
				temp->getNext()->setPrev(nullptr);
				delete temp;
			}
		}
		else {
			if (temp->getNext() == nullptr) {
				temp->getPrev()->setNext(nullptr);
				delete temp;
			}
			else {
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
				delete temp;
			}
		}
	}
}

void LinkedList::delRecFirst(std::string first) {
	LinkedList::Result* r = this->searchByFirst(first);
	if (r == nullptr) {
		std::cout << "Customer with first name: " << first << " not found!\n" << std::endl;
	}
	else {
		for (int i = 0; i < r->count; i++) {
			this->delRec(r->arr[i]->getId());
		}
		std::cout << "Record(s) deleted successfully.\n" << std::endl;
	}
}

void LinkedList::delRecLast(std::string last) {
	LinkedList::Result* r = this->searchByLast(last);
	if (r == nullptr) {
		std::cout << "Customer with last name: " << last << " not found!\n" << std::endl;
	}
	else {
		for (int i = 0; i < r->count; i++) {
			this->delRec(r->arr[i]->getId());
		}
		std::cout << "Record(s) deleted successfully.\n" << std::endl;
	}
}
