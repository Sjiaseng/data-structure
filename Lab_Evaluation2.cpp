#include <iostream>
using namespace std;

/** data node */
struct Node {
    int data;
    Node* next;
};

/** linked list data structure */
struct LinkedList {
    Node* head;
    int size;

    /** constructor */
    LinkedList() {
        cout << "--- Constructing the LinkedList object ---" << endl;
        head = nullptr;
        size = 0;
    };

    /** add new element at the beginning */
    void insertAtBeginning(int i) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = head;
        head = newNode;
        size++;
    };

    /** add new element at the end */
    void insertAtEnd(int i) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    };

    /** get number of elements */
    int getSize() {
        return size;
    };

    /** display all elements */
    void show() {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
        } else {
            Node* trav = head;
            while (trav != nullptr) {
                cout << trav->data << " ";
                trav = trav->next;
            }
            cout << endl;
        }
    };

    /** find target element */
    bool linearSearch(int i) {
        Node* trav = head;
        while (trav != nullptr) {
            if (trav->data == i) {
                return true;
            }
            trav = trav->next;
        }
        return false; // not found after all visits
    };
};

// The main menu for user interaction
int main_menu() {
    int choice;
    cout << endl;
    cout << "Linked List Menu." << endl;
    cout << "1. EXIT" << endl;
    cout << "2. Insert at beginning" << endl;
    cout << "3. Insert at end" << endl;
    cout << "4. Get the size" << endl;
    cout << "5. Display all elements" << endl;
    cout << "6. Linear search" << endl;

    cout << "Enter your choice: ";
    cin >> choice;


    return choice;
}

int get_response() {
    int myint;
    cout << "Please Enter Your Numeric Input Here: ";
    cin >> myint;

    return myint;

}

// The main program to be executed.
int main() {
    LinkedList list;
    int choice;
    int response;

    do {
        choice = main_menu();
        switch (choice) {
            case 1:
                cout << "Exiting..." << endl;
                break;
            case 2:
                response = get_response();
                list.insertAtBeginning(response);
                break;
            case 3:
                response = get_response();
                list.insertAtEnd(response);
                break;
            case 4:
                cout << "Size of the list: " << list.getSize() << endl;
                break;
            case 5:
                list.show();
                break;
            case 6: {
                response = get_response();
                if (list.linearSearch(response)) {
                    cout << response << " is found in the list." << endl;
                } else {
                    cout << response << " is not found in the list." << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice! Please reenter..." << endl;
        }
    } while (choice != 1);

    return 0;
}
