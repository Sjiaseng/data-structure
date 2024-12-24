#include <iostream>
using namespace std;

struct node_type{
    char symbol;
    struct node_type *next;
};

node_type *stack;

char pop() {
	char symbol;
	symbol = stack.items[stack.top];
	stack.top--;
	return symbol;
}
 
void push(char symbol) {
    newnode = getnode();
	if (stack == nullptr)
        stack = newnode;
}

int empty() {
	if (stack == nullptr)
		return 1;
	else return 0;
}



int main(){

}