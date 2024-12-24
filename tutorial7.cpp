#include <iostream>
using namespace std;

struct node_type{
    int student_id;
    string student_name;
    int student_age;
    struct node_type * next;
};

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
    cout << "4. Delete Front elements " << endl;
    cout << "5. Delete Rear elements " << endl;
    cout << "6. Delete elements with Student ID " << endl;

    cout << endl;

    cout << "Enter the Choice: " << endl;
    cin >> choice;

    return choice;
}

// Tutorial 7 (Start Here)
void delete_front(struct node_type *& head, struct node_type *& last){
    struct node_type* deletenode;
    if(head == nullptr){
        cout << "Cannot delete from an empty list." << endl;
    }else{
        if( head == last){
            head = last = nullptr;
        }else{
            deletenode = head;
            head = head-> next = nullptr;
        }
        delete deletenode;// if it is no longer needed
        deletenode = nullptr;
    }
}

void delete_rear(struct node_type *& head, struct node_type *& last){
    struct node_type* deletenode;
    if(head == nullptr){
        cout << "Cannot delete from an empty list" << endl;
    }else{
        struct node_type* deletenode = head;
        if( head == last){
            head = last = nullptr;
        }else{
            deletenode = last;
            struct node_type* trav = head;
            while (trav -> next != last){
                trav = trav-> next;
            }
            last = trav;
            trav -> next = nullptr; // last -> next = nullptr
        }
        delete deletenode;// if it is no longer needed
        deletenode = nullptr;
    }
}

// bool linearsearch(struct node_type* head , struct node_type* prev , int id){
//     struct node_type* trav = head;
//     bool found = false;
//     while(trav != null){
//         if(trav -> student_id == id){
//             found = true;
//         }else{
//             prev = trav;
//             trav = trav -> next;
//         }
//     }
//
// }

void delete_with_id(struct node_type *& head, struct node_type *& last){
    int id;
    cout << "Enter Student ID: ";
    cin >> id;
        struct node_type* trav = head;
        struct node_type* prev = prev;
    bool found = false;
    while(trav != nullptr && !found){
        if(trav -> student_id == id){
            found = true;
        }else{
            prev = trav;
            trav = trav -> next;
        }
    }
    if(!found){
        cout << "ID Connot be found" << endl;
    }else{
        if (trav == head){
            delete_front(head, last);
        }else if(trav == last){
            delete_rear(head, last);
        }else{
            prev -> next = trav ->next;
            trav -> next = nullptr;
            delete trav;
            trav = nullptr;
        }
    }
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
            case 4:
                delete_front(head, last);
                break;
            case 5:
                delete_rear(head, last);
                break;
            case 6:
                delete_with_id(head, last);
                break;
            default:
                cout << "Invalid Choice! Please reenter... " << endl;
        }
    }while(choice != 0);

}