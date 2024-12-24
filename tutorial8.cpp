#include <iostream>
using namespace std;

/*
Lab 8: Doubly Linked Lists
Part A: Learn how to insert and delete node from a doubly linked list
1.
In Lab 6 - Lab 7, you wrote codes for inserting and deleting values to and from a singly linked list.
Now, using the same question, write the following insert functions:
•
an insert function that inserts a new student at the beginning of the doubly linked list
•
an insert function that inserts a new student at the end of the doubly linked list; and
•
an insert function that inserts a new student into a sorted doubly linked list
 
Next, using the same question, write the following delete functions:
•
a delete function that deletes a student from the beginning of the doubly linked list
•
a delete function that deletes a student from the end of the doubly linked list; and
•
a delete function that deletes a student from a sorted doubly linked list
 
Using the same program, write the following display functions:
•
a display function that displays the values in the doubly linked list in forward order (from beginning to end)
•
a display function that displays the values in the doubly linked list in reverse order (from end to beginning)
*/
 
#include <iostream>
using namespace std;
 
struct dnode {
	int student_id;
	dnode* prev, * next;
 
	dnode(int value) : student_id(value), next(nullptr), prev(nullptr) {}
};
 
struct hnode {
	dnode *head;
	dnode *rear;
	int size;
};
 
struct dlinkedlist {
	hnode dlist;
	dnode *newnode;
	dnode* trav;
    bool larger;
 
	dlinkedlist() {
		dlist.head = nullptr;
		dlist.rear = nullptr;
		dlist.size = 0;
	}
 
	void display() {
		if (dlist.size == 0)
			cout << "The list is empty" << endl;
		else {
			int i = 0;
			trav = dlist.head;
			while (trav != nullptr) {
				cout << ++i << "." << " student id = " << trav->student_id << endl;
				trav = trav->next;
			}
		}
	}
	void insertfront(int x) {
		newnode = new dnode(x);
		if (dlist.head == nullptr) {
			dlist.head = dlist.rear = newnode;
		}
		else {
			newnode->next = dlist.head;
			dlist.head->prev = newnode;
			dlist.head = newnode;
		}
        newnode = nullptr;
        dlist.size ++;
	}

    void insertrear(int x){
		newnode = new dnode(x);
		if (dlist.rear == nullptr) {
			dlist.head = dlist.rear = newnode;
		}
		else {
            dlist.rear -> next = newnode;
            newnode -> prev = dlist.rear;
            dlist.rear = newnode;
		} 
        newnode = nullptr;
        dlist.size ++;
    }

    bool searchlarger(int x){
        trav = dlist.head;
        larger = false;
        while(trav != null && !larger){
            if(trav -> student_id){
                larger = true;
                trav = trav -> next;
            }
        }
        return larger;
    }

    void sort(){
        dnode *uhead = dlist.head -> next, *urear = dlist.rear;
        if(dlist.head != nullptr || dlist.head != dlist.rear){
            dlist.rear = dlist.head;
            dlist.rear -> next = nullptr;
            uhead -> prev = nullptr;
            while (uhead != nullptr){
                newnode = uhead;
                uhead = uhead->next;
                newnode -> next = uhead -> prev = nullptr;
                if(uhead != nullptr)
                    uhead-> prev = nullptr;
                if (searchlarger(newnode -> student_id)){
                    if(trav == dlist.head){
                        insertfront(newnode->student_id);
                    }else{
                        newnode ->next = trav;
                        newnode-> prev = trav -> prev;
                        trav -> perv -> next = newnode;
                        trav -> prev = newnode;
                    }
                }
                else{
                    insertrear(newnode -> student_id);
                }
            }
        }
    }
};
 
void menu(int* choice);
 
int main() {
	dlinkedlist dlinkedlist;
	int choice, student_id;
 
	do {
		menu(&choice);
		switch (choice) {
			case 1:
				cout << "Enter student id: ";
				cin >> student_id;
				dlinkedlist.insertfront(student_id);
				break;
			case 2:
                cout << "Enter student id: ";
				cin >> student_id;
                dlinkedlist.insertrear(student_id);
				break;			
			case 3:
                dlinkedlist.sort();
                dlinkedlist.display();
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				dlinkedlist.display();
				break;
			case 8:
				break;
			case 9:
				break;
		}
	} while (choice != 9);
}
 
void menu(int* choice) {
	cout << "Menu list: " << endl;
	cout << "---------------------" << endl;
	cout << "1. Add student id in the front of the list" << endl;
	cout << "2. Add student id at the end of the list" << endl;
	cout << "3. Sort current student list based on ID and display" << endl;
	cout << "4. Delete student id from the front of the list" << endl;
	cout << "5. Delete student id from the end of the list" << endl;
	cout << "6. Delete student id based on the user input" << endl;
	cout << "7. Display student list" << endl;
	cout << "8. Display the reversed student list" << endl;
	cout << "9. Exit" << endl;
	cout << endl;
	cout << "choice: ";
	cin >> *choice;
}