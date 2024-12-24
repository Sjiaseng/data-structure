#include <iostream>
using namespace std;

struct student_type{
    int id;
    double gpa;
};

struct node_type{
    student_type info;
    struct node_type *next;
};

typedef struct node_type *studentptr;

int main(){
    studentptr student;
}