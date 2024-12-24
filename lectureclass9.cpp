#include <iostream>
using namespace std;

struct node{
    char item;
    node* next;

    node (char i) : item(i), next(nullptr){}
};



struct queue2{
    node* front;
    node* rear;
    int size = 0;
    node* newnode;
    node* deletenode;
    
    front = nullptr;
    rear = nullptr;

    bool emptyqueue{
        if (front == nullptr){
            return true;
        }else{
            return false;
        }
    }

    bool fullqueue(){
        if(rear == size - 1 && front == 0 || rear = front - 1){
            return true;
        }else{
            return false;
        }
    }

    queue(){
        front =nullptr;
        rear = nullptr;
        size = 0;
    }

    void enqueue(char i){
        node newnode = new node(i);
        
        if(emptyqueue()){
            front = newnode;
            rear = newnode;
            
        }else{
            rear -> next = newnode;
            rear = newnode;
        }
    }

    void dequeue(char i){
        deletenode = front;
        if(front != nullptr){
            node* 
            if(front == rear){
                front = rear = nullptr;
            }
        }else{
            front = front -> next;
            deletenode -> next = nullptr;
        }
        delete deletenode; // if not used.
        deletenode = nullptr;
    }
}

struct queue{
    int items[5];
    int front;
    int rear;
    int size = 5;

    queue(){
        front = rear = size - 1;
    }

    void enqueue(char i){
        if(rear == size - 1){
            rear = 0;
            items[rear] = i;
        }else{
            rear ++
        }
        items[rear] = i;
    }

    void dequeue(char i){
        if(front == size - 1){
            front = 0;
            items[front] = i;
        }else{
            front ++
        }
        items[front] = i;
    }
};




int main(){
    queue2 queue;





    return 0;
}