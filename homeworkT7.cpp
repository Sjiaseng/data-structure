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

// Function declarations
void display(node_type* head);
node_type* get_newnode(int& songCounter);
void insert_front(node_type*& head, node_type*& last, int& songCounter);
void insert_rear(node_type*& head, node_type*& last, int& songCounter);
void insert_sorted(node_type*& head, node_type* newnode);
void sorted_list(node_type*& head, int& songCounter);
void delete_front(node_type*& head, node_type*& last);
void delete_rear(node_type*& head, node_type*& last);
void delete_song_artist(node_type*& head, node_type*& last);
void delete_song_number(node_type*& head, node_type*& last);
void search_by_genre(node_type* head); 
int main_menu(); 

int main() {
    node_type* head = nullptr;
    node_type* last = nullptr;
    int choice;
    int songCounter = 3;

    // Predefined songs for testing
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
                cout << "Exiting..." << endl;
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
            case 5:
                delete_front(head, last);
                break;
            case 6:
                delete_rear(head, last);
                break;
            case 7:
                sorted_list(head, songCounter);
                break;
            case 8:
                delete_song_artist(head, last); // Corrected function call
                break;
            case 9:
                delete_song_number(head, last);
                break;
            case 10:
                search_by_genre(head); 
                break;
            default:
                cout << "Invalid choice! Please reenter..." << endl;
        }

    } while (choice != 1);

    // Clean up allocated memory
    node_type* temp = head;
    while (temp != nullptr) {
        node_type* del = temp;
        temp = temp->next;
        delete del;
    }

    return 0;
}

void display(node_type* head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
    } else {
        node_type* trav = head;
        cout << "=============================================================================================" << endl;
        cout << "No.     Artist                  Title                   Released    Genre       Length" << endl;
        cout << "=============================================================================================" << endl;
        while (trav != nullptr) {
            cout << setw(8) << left << trav->no;
            cout << setw(24) << left << trav->artist;
            cout << setw(24) << left << trav->title;
            cout << setw(12) << left << trav->released;
            cout << setw(12) << left << trav->genre;
            cout << setw(6) << left << fixed << setprecision(2) << trav->length << endl;
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

void insert_sorted(node_type*& head, node_type* newnode) {
    node_type* current;
    if (head == nullptr || head->no >= newnode->no) {
        newnode->next = head;
        head = newnode;
    } else {
        current = head;
        while (current->next != nullptr && current->next->no < newnode->no) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void sorted_list(node_type*& head, int& songCounter) {
    node_type* sortedHead = nullptr;
    node_type* temp = head;

    while (temp != nullptr) {
        node_type* nextNode = temp->next;
        insert_sorted(sortedHead, temp);
        temp = nextNode;
    }

    display(sortedHead);

    // Clean up allocated memory for sorted list
    node_type* del = sortedHead;
    while (del != nullptr) {
        node_type* nextDel = del->next;
        delete del;
        del = nextDel;
    }
}

void delete_front(node_type*& head, node_type*& last) {
    if (head == nullptr) {
        cout << "The list is empty... Cannot delete any node" << endl;
    } else {
        node_type* deletenode = head;
        head = head->next;
        deletenode->next = nullptr;
        delete deletenode;
    }
}

void delete_rear(node_type*& head, node_type*& last) {
    if (last == nullptr) {
        cout << "The list is empty... Cannot delete any node" << endl;
    } else {
        node_type* deletenode = last;
        if (head == last) {
            head = nullptr;
            last = nullptr;
        } else {
            node_type* prev = head;
            while (prev->next != last) {
                prev = prev->next;
            }
            last = prev;
            prev->next = nullptr;
        }
        delete deletenode;
    }
}

void delete_song_artist(node_type*& head, node_type*& last) {
    if (head == nullptr)
        cout << "List is empty! Cannot delete any data..." << endl;
    else {
        string artist_name;
        cout << "Enter artist Name: ";
        cin.ignore();
        getline(cin, artist_name);
        int found = 0;
        node_type* trav = head;
        node_type* prev = nullptr;
        while (!found && trav != nullptr) {
            if (trav->artist == artist_name)
                found = 1;
            else {
                prev = trav;
                trav = trav->next;
            }
        }
        if (!found)
            cout << artist_name << " is NOT found in the list" << endl;
        else {
            cout << artist_name << " is found in the list" << endl;
            if (trav == head) {
                delete_front(head, last);
            } else if (trav == last) {
                delete_rear(head, last);
            } else {
                prev->next = trav->next;
                trav->next = nullptr;
                delete trav;
            }
        }
    }
}

void search_by_genre(node_type* head) {
    if (head == nullptr) {
        cout << "List is empty! Cannot search for any songs." << endl;
    } else {
        string genre;
        cout << "Enter genre to search: ";
        cin.ignore(); // Ignore any leftover newline characters
        getline(cin, genre);

        bool found = false;
        node_type* trav = head;

        cout << "Songs in genre '" << genre << "':" << endl;
        cout << "=============================================================================================" << endl;
        cout << "No.     Artist                  Title                   Released    Genre       Length" << endl;
        cout << "=============================================================================================" << endl;

        while (trav != nullptr) {
            if (trav->genre == genre) {
                found = true;
                cout << setw(8) << left << trav->no;
                cout << setw(24) << left << trav->artist;
                cout << setw(24) << left << trav->title;
                cout << setw(12) << left << trav->released;
                cout << setw(12) << left << trav->genre;
                cout << setw(6) << left << fixed << setprecision(2) << trav->length << endl;
            }
            trav = trav->next;
        }

        if (!found) {
            cout << "No songs found in genre '" << genre << "'." << endl;
        }
    }
}

void delete_song_number(node_type*& head, node_type*& last) {
    if (head == nullptr) {
        cout << "List is empty! Cannot delete any data..." << endl;
    } else {
        int song_number_int;
        cout << "Enter song number: ";
        cin >> song_number_int; 

        int found = 0;
        node_type* trav = head;
        node_type* prev = nullptr;
        
        while (!found && trav != nullptr) {
            if (trav->no == song_number_int)  
                found = 1;
            else {
                prev = trav;
                trav = trav->next;
            }
        }

        if (!found) {
            cout << song_number_int << " is NOT found in the list" << endl;
        } else {
            cout << song_number_int << " is found in the list" << endl;
            if (trav == head) {
                delete_front(head, last);
            } else if (trav == last) {
                delete_rear(head, last);
            } else {
                prev->next = trav->next;
                trav->next = nullptr;
                delete trav;
            }
        }
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
    cout << "5. Delete song from the front of the list" << endl;
    cout << "6. Delete song from the rear of the list" << endl;
    cout << "7. Sort and display songs" << endl;
    cout << "8. Delete song by artist" << endl;
    cout << "9. Delete song by number" << endl;
    cout << "10. Search by genre" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
