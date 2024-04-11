#include "LinkedList.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool createLL(LinkedList*);
void addCustomer(LinkedList*);
bool inputValidation(int, string, string, double, double);
int choiceInt();
double choiceDouble();

int main() {
	bool run = true;
	cout << "===Customer Info Linked List===\n" << endl;
	LinkedList* LL = nullptr;
	while (run) {
		int choice;
		cout << "==Main Menu==\n" << endl;
		cout << "Choose from the following options:\n\n" <<
			"1. Create Linked List\n" <<
			"2. Add New Customer Node to Linked List\n" <<
			"3. Search Customer from Linked List\n" <<
			"4. Edit Customer from Linked List\n"<<
			"5. Delete Customer from Linked List\n" <<
			"6. Show All Customers in Linked List\n" <<
			"7. End Program\n" << endl;
		choice = choiceInt();
		switch (choice) {
		case 1: {
			if (LL == nullptr) {
				LL = new LinkedList();
				cout << "Linked List created successfully! You can now add customer nodes!\n" << endl;
			}
			else {
				cout << "Linked List already exists!\n" << endl;
			}
		}
			break;
		case 2: {
			addCustomer(LL);
		}
			break;
		case 3: {
			int subchoice;
			cout << "Choose what parameter to search by: \n" <<
				"1. Customer ID\n" <<
				"2. Customer First name\n" <<
				"3. Customer Last name\n" <<
				"4. Customer Balance\n" <<
				"5. Customer Spent\n" <<
				"6. Return to main menu\n" <<endl;
			subchoice = choiceInt();
			switch (subchoice) {
			default: {
				int ids;
				cout << "Enter ID to search for:\n" << endl;
				ids = choiceInt();
				LL->printResult(LL->searchById(ids));
			}
				break;
			case 2: {
				string firsts;
				cout << "Enter First name to search for:\n" << endl;
				cin >> firsts;
				LL->printResult(LL->searchByFirst(firsts));
			}
				break;
			case 3: {
				string lasts;
				cout << "Enter Last name to search for:\n" << endl;
				cin >> lasts;
				LL->printResult(LL->searchByLast(lasts));
			}
				break;
			case 4: {
				double bals;
				cout << "Enter balance amount to search for:\n" << endl;
				bals = choiceDouble();
				LL->printResult(LL->searchByBalance(bals));
			}
				break;
			case 5: {
				double spents;
				cout << "Enter spent amount to search for:\n" << endl;
				spents = choiceDouble();
				LL->printResult(LL->searchBySpent(spents));
			}
				break;
			case 6: {

			}
				break;
			}
		}
			break;
		case 4: {
			if (LL == nullptr) {
				cout << "Linked List is not created yet! Create Linked List first and populate with customer data!\n" << endl;
			}
			else if (LL->getStart() == nullptr) {
				cout << "Linked List is empty! Try populating with customer data!\n" << endl;
			}
			else {
				cout << "Enter Customer ID to edit:\n" << endl;
				int ide = choiceInt();
				Node* temp = LL->searchById(ide);
				if (temp == nullptr) {
					cout << "No such ID exists in Linked List!\n" << endl;
				}
				else {
					LL->printResult(temp);
					cout << "Which parameter would you like to edit?\n" << endl;
					cout << "1. First Name\n" <<
						"2. Last Name\n" <<
						"3. Balance\n" <<
						"4. Spent\n" << endl;
					int choicee = choiceInt();
					switch (choicee) {
					case 1: {
						cout << "Enter new first name:\n" << endl;
						string input;
						cin >> input;
						temp->setFirst(input);
					}
						  break;
					case 2: {
						cout << "Enter new last name:\n" << endl;
						string input;
						cin >> input;
						temp->setLast(input);
					}
						  break;
					case 3: {
						cout << "Enter new balance:\n" << endl;
						double input = choiceDouble();
						temp->setBal(input);
					}
						  break;
					case 4: {
						cout << "Enter new spent:\n" << endl;
						double input = choiceDouble();
						temp->setSpent(input);
					}
						  break;
					default:
						cout << "Invalid choice! Returning to main menu.\n" << endl;
						break;
					}
				}
			}
		}
			break;
		case 5: {
			cout << "Choose parameter to search for and delete customer node by:\n" << endl;
			cout << "1. Customer ID\n" <<
				"2. Customer First Name\n" <<
				"3. Customer Last Name\n" <<
				"4. Return to main menu\n" << endl;
			int choiced = choiceInt();
			switch (choiced) {
			default: {
				cout << "Enter Customer ID you wish to delete:\n" << endl;
				int idd = choiceInt();
				LL->delRec(idd);
			}
			break;
			case 2: {
				cout << "Enter Customer First name to search for and delete (Warning: This will delete ALL customers with this first name):\n" << endl;
				string first;
				cin >> first;
				LL->delRecFirst(first);
			}
			break;
			case 3: {
				cout << "Enter Customer Last name to search for and delete (Warning: This will delete ALL customers with this last name):\n" << endl;
				string last;
				cin >> last;
				LL->delRecLast(last);
			}
			break;
			case 4: {
				break;
			}
			break;
			}
		}
			break;
		case 6: {
			LL->printAll();
		}
			 break;
		case 7: {
			run = false;
		}
		}
	}
}

void addCustomer(LinkedList* LL) {
	int id;
	string first, last;
	double bal, spent;
	addCustomerBP:
	if (LL == nullptr) {
		cout << "You must first create a Linked List!\n" << endl;
	}
	else {
		cout << "What is the customer's ID? (8 Digit MAX)\n" << endl;
		id = choiceInt();
		cout << endl;
		cout << "What is the customer's First Name? (10 Characters MAX)\n" << endl;
		cin >> first;
		cout << endl;
		cout << "What is the customer's Last Name? (10 Characters MAX)\n" << endl;
		cin >> last;
		cout << endl;
		cout << "What is the customer's current balance?($9,999,999 MAX)\n" << endl;
		bal = choiceDouble();
		cout << endl;
		cout << "How much has the customer spent so far?($9,999,999 MAX)\n" << endl;
		spent = choiceDouble();
		cout << endl;
		if (!inputValidation(id, first, last, bal, spent)) {
			cout << "Error found in customer data. Please try again!\n" << endl;
			goto addCustomerBP;
		}
		else {
			LL->add(new Node(id, first, last, bal, spent));
		}
	}
}

bool inputValidation(int id, string first, string last, double bal, double spent) {
	string msg = "";
	bool ret = true;
	if (id > 99999999) { msg += "Invalid ID! Must be 8 digits or less!\n"; ret = false; }
	if (first.length() > 10) { msg += "First name too long!\n"; ret = false; }
	if (last.length() > 10) { msg += "Last name too long!\n"; ret = false; }
	if (bal > 9999999) { msg += "Balance too large! Must be less than or equal to $9,999,999\n"; ret = false; }
	if (spent > 9999999) { msg += "Spent too large! Must be less than or equal to $9,999,999\n"; ret = false; }
	if (!ret) { cout << msg << endl; return false; }
	else {
		cout << "Customer Node created successfully!\n" << endl;
		return true;
	}
}

int choiceInt() {
	int ret;
	while (!(cin >> ret)) {
		cout << "Must be a integer! Try again!\n" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return ret;
}

double choiceDouble() {
	double ret;
	while (!(cin >> ret)) {
		cout << "Must be a double! Try again!\n" << endl;
		cin.clear();
		cin.ignore();
	}
	return ret;
}