#include <iostream>
 
using namespace std;
 
class Node
{
public:
    int data;
    Node *next;
};
 
class Queue
{
    Node *front;
    Node *rear;
 
public:
    Queue()
    {
        front = rear = nullptr;
    }
    // Adding Elements on Front
    void enqueue(int value)
    {
        cout << "Enqueue element = " << value << endl;
        if (isEmpty())
        {
            rear = new Node();
            rear->data = value;
            rear->next = nullptr;
            front = rear;
        }
        else
        {
            Node* newnode = new Node();
            newnode->data = value; 
            newnode->next = nullptr;  
            rear->next = newnode;  
            rear = newnode;  
        }
    }
    // Adding Elements at Last
    void dequeue() {
        Node* temp = front;
        if (front == nullptr) {
            cout << "Queue is underflow!" << endl;
        } else {
            Node* deletenode = front;     
            front = front->next;          
            cout << "Dequeue: " << deletenode->data << endl;
            delete deletenode;            
            if (front == nullptr) {       
                rear = nullptr;         
            }
        }
    }

    // Checking whether is the queue empty
    bool isEmpty()
    {
        if(front == nullptr)
            return true;
        else
            return false;
    }
    
    // Checking First Element
    int first()
    {
        return (!isEmpty()) ? front->data : -1;
    }
    // Checking Last Element
    int last()
    {
        return (!isEmpty()) ? rear->data : -1;
    }

};

// menu
int main_menu(){
    int choice;
    cout << "Menu" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Enqueue Data" << endl;
    cout << "2. Dequeue Data" << endl;
    cout << "3. Is Empty?" << endl;
    cout << "4. First Element " << endl;
    cout << "5. Rear Element " << endl;

    cout << endl;

    cout << "Enter the Choice: ";
    cin >> choice;

    return choice;
}

int main() {
    Queue myqueue;
    int element;
    int choice;

    do {
        choice = main_menu();
        switch (choice) {
            case 1:
                cout << "Enter Element to Enqueue: ";
                cin >> element;
                myqueue.enqueue(element);
                cout << endl;
                break;
            case 2:
                myqueue.dequeue();
                cout << endl;
                break;
            case 3:
                cout << (myqueue.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                cout << endl;
                break;
            case 4:
                if(myqueue.first() == -1){
                    cout << "No Element Found ! " << endl;
                } else
                {
                    cout << "First Element: " << myqueue.first() << endl;
                }
                cout << endl;
                break;
            case 5:
                if(myqueue.last() == -1){
                    cout << "No Element Found ! " << endl;
                } else
                {
                    cout << "Last Element: " << myqueue.last() << endl;
                }
                cout << endl;
                break;
            default:
                if (choice != 0) {
                    cout << "Invalid Choice Selected!" << endl;
                }
                break;
        }
    } while (choice != 0);

    return 0;
}