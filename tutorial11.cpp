#include <iostream>
using namespace std;

struct node{
    string data;
    node* parent;
    node* left;
    node* right;
    // constructor for node
    node(string i) : data(i), parent(nullptr), left(nullptr), right(nullptr) {}
};

class Tree{
    public:
        node* root;

        Tree(){
            root = nullptr;
        }

        bool empty(){
            return root == nullptr;
        }

        void insert(string i){
            node* newnode = new node(i);
            if(empty()){
                root = newnode;
            }else{
                node * parent = NULL, * current = root;
                while(current != NULL){
                    parent = current;
                    if(current->data == i){
                        cout << "Duplicates not allowed." << endl;
                        return;
                    }
                    else if (i < current->data){
                        current = current->left;
                    }else{
                        current = current->right;
                    }
                }
                newnode->parent = parent;
                if (i < parent->data){
                    parent->left = newnode;
                }else{
                    parent->right = newnode;
                }
            }
        }

        // helper function
        void preorder(){
            preorder(root);
            cout << endl;
        }

        void preorder(node* n){
            if(n != nullptr){
                cout << n->data << ", ";
                preorder(n->left);
                preorder(n->right);
            }
        }

        void inorder(){
            inorder(root);
            cout << endl;
        }

        void inorder(node* n){
            if(n != nullptr){
                inorder(n->left);
                cout << n->data << ", ";
                inorder(n->right);
            }
        }

        void postorder(){
            postorder(root);
            cout << endl;
        }

        void postorder(node* n){
            if(n != nullptr){
                postorder(n->left);
                postorder(n->right);
                cout << n->data << ", ";
            }
        }
};

int main(){
    Tree tree;
    string animals[] = {"Monkey", "Rat", "Tiger", "Dog", "Cat", "Elephant", "Salmon", "Zebra", "Panda"};
    int size = sizeof(animals) / sizeof(animals[0]);

    for(int i = 0; i < size; i++){
        tree.insert(animals[i]);
    }

    cout << "Preorder: ";
    tree.preorder();

    cout << "Inorder: ";
    tree.inorder();

    cout << "Postorder: ";
    tree.postorder();

    return 0;
}
