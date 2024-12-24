#include <iostream>
using namespace std;

struct node{
    string data;
    node *parent, *left, *right;

    node (string i) : data(i), parent(nullptr), left(nullptr), right(nullptr) {};
};

struct tree{
    node * root;

    tree(){
        root = nullptr;
    }

    void insertBST(string i){
        node * newnode = new node(i);
        if(root == nullptr){
            root = newnode;
        }
        else{
            if(newnode -> data < i){
                
            }
        }

    }
}



int main(){
    string fruits[] = {"mango", "apple", "strawberry"};
    int size = sizeof(fruits)/sizeof(fruits[0]);

    int i;
    while (i < size){
        tree.insertBST(fruits[i]);
        i++ ;
    }

    return 0;
}