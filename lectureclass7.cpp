#include <iostream>
using namespace std;
 
struct stack_type {
	char items[20];
	int top;
};
 
stack_type stack;
 
int empty();
char pop();
void push(char symbol);
 
int main() {
	char exp[] = { '(', 'x', '+', '(', 'y', '/', '(', 'z', '^', 'a', ')', ')', ')', '.'};
	char symbol, psymbol;
	stack.top = -1;
 
	int i = 0;
	do {
		symbol = exp[i];
		if (symbol == '(' || symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '^')
			push(symbol);
		else if (symbol == ')')
			do {
				psymbol = pop();
				if (psymbol == '+' || psymbol == '-' || psymbol == '/' || psymbol == '*' || psymbol == '^')
					cout << psymbol;
			} while (psymbol != '(');
		else
			cout << symbol;
		i++;
	} while (symbol != '.');
 
}
 
char pop() {
	char symbol;
	symbol = stack.items[stack.top];
	stack.top--;
	return symbol;
}
 
void push(char symbol) {
	stack.top++;
	stack.items[stack.top]= symbol;
}

int empty() {
	if (stack.top == -1)
		return 1;
	else return 0;
}
 

// If symbol is operator or (
//     Push symbol on to the operator stack
// Otherwise if symbol is )
//     Repeat
//         Pop the stack
//         If the popped symbol is operator
//             Affix symbol to the postfix expressions
//     Until popped symbol is (
// Else 
//     Affix symbol to the postfix expression

// If symbol is an operand
//    push symbol onto the stack
// Otherwise 
//    If it is an operator
//      Pop 2 Operand from Operand Stack
//        (pop 1 -> Op2 , pop2 -> Op1)
//            Perform Calculation in Result
//              Push Result to Operand Stack