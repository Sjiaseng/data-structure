#include <iostream>
using namespace std;
 
struct node {
	string data;
	node* child, * father, * mother;
 
	node(string i) : data(i), child(nullptr), father(nullptr), mother(nullptr) {}
};
 
struct tree {
	node* root;
    
    void preorder(node* p){
        if(p != nullptr){
            cout << p -> data << endl;
            preorder(p -> father);
            preorder(p -> mother);
        }
    }

    void inorder(node* p){
        if (p!= nullptr){
            inorder(p -> father);
            cout << p -> data << endl;
            inorder(p -> mother);
        }
    }

    void postorder(node* p){
        if (p!= nullptr){
            postorder(p -> father);
            postorder(p -> mother);
            cout << p -> data << endl;

        }
    }
 
};
 
int main() {
	tree tree;
	node* newnode = new node("steven");
	tree.root = newnode;
	newnode = new node("stephen");
	newnode->child = tree.root;
	tree.root->father = newnode;
	newnode = new node("stephanie");
	newnode->child = tree.root;
	tree.root->mother = newnode;
	newnode = new node("sylvia");
	newnode->child = tree.root->father;
	tree.root->father->mother = newnode;

    tree.preorder(tree.root);
    cout << endl;
    tree.inorder(tree.root);
    cout << endl;
    tree.postorder(tree.root);
}