#include <iostream>
using namespace std;

struct data_type {
	int age;
	double weight;
};
 
struct node_type {
	int data;
	node_type* link;
};

struct list_type {
	node_type* head;
	int size;
};

// No need to use node_type* in main section
typedef struct node_type* nodeptr;

void menu(){
    cout << "1. Add an element to list" << endl;
    cout << "2. Remove an element from the list" << endl;
    cout << "3. Print all elements in the list" << endl;
    cout << "4.Search an element in the list" << endl;
    cout << "5.Exit the system" << endl;
}

int main() {
	nodeptr temp, trav, newnodeptr, last;
	list_type s_header;
	int num;
    char choice;
    s_header.head = NULL;
	s_header.size = 0;
    int age;
    int found = 0;
    
    do {
        cout << endl;
        menu();
        cout << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch(choice){
            case '1':
                cout << "Adding an element to list:" << endl;
                newnodeptr = new node_type;
                cout << "Enter new node data: ";
                cin >> newnodeptr -> data;
                newnodeptr -> link = NULL;
                if(s_header.head == NULL){
                    s_header.head = newnodeptr;
                    last = newnodeptr;
                }else{
                    last -> link = newnodeptr;
                    last = newnodeptr;
                }
                s_header.size++;
                break;
            case '2':
                cout << "Removing an element to list:" << endl;
                break;
            case '3':
                cout << "Printing all element in list:" << endl;
                trav = s_header.head;
                while(trav != NULL){
                    cout << trav -> data << endl;
                    trav = trav -> link;
                }
                break;
            case '4': //got error remember to copy code
                cout << "Searching an element in the list:" << endl;
                cout << "Enter age to search: ";
                cin >> age;
                trav = s_header.head;
                while (trav != NULL && !found){
                    if(trav -> data.age == age){
                        cout << trav -> data.weight << endl;
                        found = 1;
                    }else{
                    trav = trav -> link;
                    }
                }
                break;  
            case '5':
                cout << "Exiting the system, Bye~" << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid choice" << endl;                              
        }

    }
    while (choice != '5');
 
	/*temp = new node_type;
	temp->data = 17;
	temp->link = NULL;
	s_header.head = temp;
	s_header.size++;
 
	temp = new node_type;
	temp->data = 92;
	temp->link = NULL;
	s_header.head->link = temp;
	s_header.size++;
 
	temp = new node_type;
	temp->data = 63;
	temp->link = NULL;
	s_header.head->link->link = temp;
	s_header.size++;
 
	temp = new node_type;
	temp->data = 45;
	temp->link = NULL;
	s_header.head->link->link->link = temp;
	s_header.size++;
	*/
    /*
	//print all elements
	trav = s_header.head;
	while (trav != NULL) {
		cout << trav->data;
		if (trav->link != NULL)
			cout << ", ";
		trav = trav->link;
	}
	cout << endl;
 
	//search for certain data
	int found = 0;
	cout << "enter a number: ";
	cin >> num;
	trav = s_header.head;
	while (trav != NULL && !found) {
		if (trav->data == num)
			found = 1;
		else
			trav = trav->link;
	}
	if (found)
		cout << trav->data << " is found" << endl;
	else
		cout << num << " is not found" << endl;
 
	//insert an element after number 92
	int found = 0;
	cout << "enter a number: ";
	cin >> num;
	trav = s_header.head;
	while (trav != NULL && !found) {
		if (trav->data == num)
			found = 1;
		else
			trav = trav->link;
	}
	if (found) {
		cout << trav->data << " is found" << endl;
 
	}
	else
		cout << num << " is not found" << endl;
    */
}


