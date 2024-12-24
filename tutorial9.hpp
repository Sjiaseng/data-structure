#include <iostream>
using namespace std;

struct node{
    double data;
    node* next; 
};

class Queue{
    private:
        node* front;
        node* rear;
        int size;
    
    public:
        Queue(){
            front = rear = nullptr;
            size = 0;
        }

        bool empty(){
            if(front == nullptr)
                return true;
            else
                return false;
        }

        void enqueue(double i){
            node* newnode = new node;
            newnode -> data = i;
            newnode -> next = nullptr;
            cout << "enqueue: " << newnode->data << endl;
            if(empty())
                front = rear = newnode;
            else{
                rear -> next = newnode;
                rear = rear -> next;
            }

        }

        double dequeue(){
            node* deletenode = new node;
            if(empty())
                return -1;
            else{
                node* deletenode = front;
                front = front -> next;
                deletenode -> next = nullptr;
                cout << "dequeue: " << deletenode -> data << endl;
                return deletenode -> data;

            }
        }

        double first(){
            if(empty())
                return -1;
            else
                return front -> data;  
        }

        double last(){
            if(empty())
                return -1;
            else
                return rear -> data;  
        }

        double sum(){

            node* trav = front;
            int sum = 0;
            while(trav != nullptr){
                sum += trav -> data;
                trav = trav -> next;
            }
            return sum;
        }


        void print(){
            node* trav = front;
            while(trav != nullptr){
                cout << trav->data << ", ";
                trav = trav -> next;
            }
        }

};