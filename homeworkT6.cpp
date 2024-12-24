#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct node_type {
    int no;
    string artist;
    string title;
    int released;
    string genre;
    double length;
    node_type* next;
};

void display(node_type* head);
node_type* get_newnode(int& songCounter);
void insert_front(node_type*& head, node_type*& last, int& songCounter);
void insert_rear(node_type*& head, node_type*& last, int& songCounter);
int main_menu();

int main() {
    node_type* head = nullptr;
    node_type* last = nullptr;
    int choice;
    int songCounter = 3;

 
    node_type* song1 = new node_type{1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58, nullptr};
    node_type* song2 = new node_type{2, "Taylor Swift", "You Belong With Me", 2008, "Pop", 3.48, nullptr};
    node_type* song3 = new node_type{3, "The Cranberries", "Promises", 1999, "Rock", 4.30, nullptr};

    head = song1;
    song1->next = song2;
    song2->next = song3;
    last = song3;

    do {
        choice = main_menu();
        switch (choice) {
            case 1:
                cout << "Exit" << endl;
                break;
            case 2:
                insert_front(head, last, songCounter);
                break;
            case 3:
                insert_rear(head, last, songCounter);
                break;
            case 4:
                display(head);
                break;
            default:
                cout << "Invalid choice! Please reenter..." << endl;
        }
    } while (choice != 1);

    return 1;
}

void display(node_type* head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
    } else {
        node_type* trav;
        cout << "=============================================================================================" << endl;
        cout << "No.     Artist                  Title                   Released    Genre       Length" << endl;
        cout << "=============================================================================================" << endl;
        trav = head;
        while (trav != nullptr) {
            cout << setw(8) << left << trav->no;
            cout << setw(24) << left << trav->artist;
            cout << setw(24) << left << trav->title;
            cout << setw(12) << left << trav->released;
            cout << setw(12) << left << trav->genre;
            cout << setw(6) << left << trav->length << endl;
            trav = trav->next;
        }
    }
}

node_type* get_newnode(int& songCounter) {
    node_type* newnode = new node_type;

    newnode->no = ++songCounter;

    cout << "Enter new song artist: ";
    cin.ignore();
    getline(cin, newnode->artist);

    cout << "Enter new song title: ";
    getline(cin, newnode->title);

    cout << "Enter new song release year: ";
    cin >> newnode->released;

    cout << "Enter new song genre: ";
    cin.ignore();
    getline(cin, newnode->genre);

    cout << "Enter new song length (in minutes): ";
    cin >> newnode->length;

    newnode->next = nullptr;

    return newnode;
}

void insert_front(node_type*& head, node_type*& last, int& songCounter) {
    node_type* newnode = get_newnode(songCounter);
    if (head == nullptr) {
        head = newnode;
        last = head;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void insert_rear(node_type*& head, node_type*& last, int& songCounter) {
    node_type* newnode = get_newnode(songCounter);
    if (head == nullptr) {
        head = newnode;
        last = head;
    } else {
        last->next = newnode;
        last = newnode;
    }
}

int main_menu() {
    int choice;
    cout << endl;
    cout << "Music player menu." << endl;
    cout << "1. EXIT" << endl;
    cout << "2. Add song to the front of the list" << endl;
    cout << "3. Add song to the rear of the list" << endl;
    cout << "4. Display all songs" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    return choice;
}
