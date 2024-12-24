#include <iostream>
#include "tutorial9.hpp"
using namespace std;


int main(){
    Queue Q1, Q2, Q3;

    Q1.enqueue(123);
    Q1.enqueue(123);
    double testing = Q1.sum();
    cout << testing << endl;
    Q1.dequeue();
    Q1.print();
    

}

