#include <iostream>
using namespace std;

struct node_type{
    int student_id;
    string student_name;
    int student_age;
    struct node_type * next;
};

// question 1 part c (Assign Data Manually)
// int main(){
//     struct node_type * head = nullptr, *newnode, *trav;

//     newnode = new node_type;
//     newnode -> student_id = 34;
//     newnode -> next = nullptr;
//     head = newnode;


//     newnode = new node_type;
//     newnode-> student_id = 45;
//     newnode -> next = nullptr;
//     head -> next = newnode;


//     newnode = new node_type;
//     newnode-> student_id = 33;
//     newnode -> next = nullptr;
//     head -> next -> next = newnode;



//     trav = head;
//     while(trav != nullptr){
//         cout << trav-> student_id << endl;
//         trav = trav -> next;
//     }
// }



struct node_type* get_newnode() {
	struct node_type *newnode = new node_type;
 
	cout << "Enter new student id: ";
	cin >> newnode->student_id;
    cout << "Enter new student name: ";
	cin >> newnode->student_name;
    cout << "Enter new student age: ";
	cin >> newnode->student_age;

	newnode->next = nullptr;
	return newnode;
}

// question 2 part c
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

// question 3 part c
void insert_rear(struct node_type *& head, struct node_type *& last){
    struct node_type* newnode = get_newnode();

    if(head == nullptr){
        head = newnode;
        last = head;
    }else{
        last-> next = newnode;
        last = newnode;
    }
}

void display(struct node_type* head) {
    if(head == nullptr){
        cout << "The list is empty";
    }else{
        struct node_type* trav;
        cout << "============================" << endl;
        cout << "No.\tID\tname\tage" << endl; 
        cout << "============================" << endl;
        trav = head;
        int count = 0;
        while (trav != nullptr) {
            count++;
            cout << count << "\t";
            cout << trav-> student_id << "\t";
            cout << trav-> student_name << "\t";
            cout << trav-> student_age << "\t";
            cout << endl;
            cout << endl;
            trav = trav->next;
        }
    }
}

int main_menu(){
    int choice;
    cout << "Welcome to Linked list menu" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Add to Front of List" << endl;
    cout << "2. Add to Rear of List" << endl;
    cout << "3. Display all elements " << endl;
    cout << endl;

    cout << "Enter the Choice: " << endl;
    cin >> choice;

    return choice;
}


int main(){
    struct node_type * head = nullptr, *newnode, *trav, *last;
    int choice;
    do{
        choice = main_menu();
        switch(choice){
            case 0:
                cout << "Exited System..." << endl;
                break;
            case 1:
                insert_front(head, last);
                break;
            case 2:
                insert_rear(head, last);
                break;
            case 3:
                display(head);
                break;
            default:
                cout << "Invalid Choice! Please reenter... " << endl;
        }
    }while(choice != 0);

}