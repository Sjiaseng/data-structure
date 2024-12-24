#include <iostream>
using namespace std;
 
struct node_type {
	int student_id;
	string student_name;
	int student_age;
	struct node_type* next;
};
 
void delete_front(struct node_type*& head, struct node_type*& last);
void delete_rear(struct node_type*& head, struct node_type*& last);
void delete_id(struct node_type*& head, struct node_type*& last);
void display(struct node_type* head);
struct node_type* get_newnode();
void insert_front(struct node_type*& head, struct node_type*& last);
void insert_rear(struct node_type*& head, struct node_type*& last);
int main_menu();
 
int main() {
	struct node_type* head = nullptr, * newnode, * last;
	int choice;
 
	do {
		choice = main_menu();
		switch (choice) {
		case 0:
			cout << "Exit" << endl;
			break;
		case 1:
			insert_front(head, last);
			break;
		case 2:
			insert_rear(head, last);
			break;
		case 3:
			delete_front(head, last);
			break;
		case 4:
			delete_rear(head, last);
			break;
		case 5:
			delete_id(head, last);
			break;
		case 6:
			display(head);
			break;
		default:
			cout << "Invalid choice! Please reenter..." << endl;
		}
	} while (choice != 0);
	return 0;
}
 
void delete_front(struct node_type*& head, struct node_type*& last) {
	if (head == nullptr)
		cout << "The list is empty... Cannot delete any node" << endl;
	else {
		struct node_type* deletenode = head;
		if (head == last) {
			head = nullptr;
			last = nullptr;
		}
		else {
			head = head->next;
			deletenode->next = nullptr;
		}
	}
}
 
void delete_rear(struct node_type*& head, struct node_type*& last) {
	if (last == nullptr)
		cout << "The list is empty... Cannot delete any node" << endl;
	else {
		struct node_type* deletenode = last;
		if (head == last) {
			head = nullptr;
			last = nullptr;
		}
		else {
			struct node_type* prev = head;
			while (prev->next != last)
				prev = prev->next;
			last = prev;
			prev->next = nullptr;
		}
		delete deletenode;//the node is destroyed and return the space to system
		deletenode = nullptr;
	}
}
 
void delete_id(struct node_type*& head, struct node_type*& last) {
	if (head == nullptr)
		cout << "List is empty! Cannot delete any data..." << endl;
	else {
		int id;
		cout << "Enter student id: ";
		cin >> id;
		int found = 0;
		struct node_type* trav = head;
		struct node_type* prev = nullptr;
		while (!found && trav != nullptr) {
			if (trav->student_id == id)
				found = 1;
			else {
				prev = trav;
				trav = trav->next;
			}
		}
		if (!found)
			cout << id << " is NOT found in the list" << endl;
		else {
			cout << id << " is found in the list" << endl;
			if (trav == head) {
				cout << "front" << endl;
				delete_front(head, last);
			}
			else if (trav == last) {
				cout << "front" << endl;
				delete_rear(head, last);
			}
			else {
				prev->next = trav->next;
				trav->next = nullptr;
			}
		}
	}
}
void display(struct node_type* head) {
 
	if (head == nullptr)
		cout << "The list is empty" << endl;
	else {
		struct node_type* trav;
		cout << "===========================" << endl;
		cout << "No.\tID\tname\tage" << endl;
		cout << "===========================" << endl;
		trav = head;
		int count = 0;
		while (trav != nullptr) {
			count++;
			cout << count << "\t";
			cout << trav->student_id << "\t";
			cout << trav->student_name << "\t";
			cout << trav->student_age << endl;
			trav = trav->next;
		}
	}
}
struct node_type* get_newnode() {
	struct node_type* newnode = new node_type;
 
	cout << "Enter new student id: ";
	cin >> newnode->student_id;
	cout << "Enter new student name: ";
	cin >> newnode->student_name;
	cout << "Enter new student age: ";
	cin >> newnode->student_age;
	newnode->next = nullptr;
	return newnode;
}
 
void insert_front(struct node_type*& head, struct node_type*& last) {
	struct node_type* newnode = get_newnode();
 
	if (head == nullptr) {
		head = newnode;
		last = head;
	}
	else {
		newnode->next = head;
		head = newnode;
	}
 
}
void insert_rear(struct node_type*& head, struct node_type*& last) {
	struct node_type* newnode = get_newnode();
 
	if (head == nullptr) {
		head = newnode;
		last = head;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
}
 
int main_menu() {
	int choice;
 
	cout << "Welcome to linked list menu" << endl;
	cout << "0. EXIT" << endl;
	cout << "1. Add to front of list" << endl;
	cout << "2. Add to rear of list" << endl;
	cout << "3. Delete to front of list" << endl;
	cout << "4. Delete to rear of list" << endl;
	cout << "5. Delete based on student id" << endl;
	cout << "6. Display all elementd" << endl;
	cout << endl;
	cout << "Enter choice: " << endl;
	cin >> choice;
	return choice;
}