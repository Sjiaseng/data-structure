#include <iostream>
using namespace std;


struct node{
    string data;
    node* next;

    node(string i) : data(i), next(nullptr){}
};

class Stack{
    private:
        node * top;
        int size;
    public:
        Stack(){
            top = nullptr;
            size = 0;
        }

        bool empty(){
            if(top == nullptr)
                return true;
            else 
                return false;
        }

        void push(string i){
            cout << "push: " << i << endl;
            node* newnonde = new node(i);
            if(empty()){
                top = newnode;
            }else{
                newnode -> next = top;
                top = newnode;

            }
            size ++;
            newnode = nullptr;
        }

        string pop(){
            node* deletenode = top;
            if(deletenode == nullptr)
                return "nullptr";
            else{
                top = top -> next;
                deletenode -> next = nullptr;
                size --;
                return deletenode -> data;
            }
        
        }

        string peek(){
            if(empty())
                return "nullptr";
            else
                return top->data;
        }

};

void menu(){
    cout << "1. push" << endl;
    cout << "2. pop" << endl;
    cout << "3. peek" << endl;
    cout << "4. empty" << endl;
    cout << "0. exit" << endl;
    
}

int main(){
    Stack stack;
    int choice;
    string TP_number;

    do{
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter TP numebr: ";
                cin >> TP_number;
                stack.push(TP_number);
                break;
            case 2:
                TP_number = stack.pop();
                break;
            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;
            case 4:
                if(stack.empty())
                    cout << "The stack is empty" << endl;
                else
                    cout << "The stack is not empty" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 0);

}