#include <iostream>
#include <string>
using namespace std;

struct name_type{

    string fname, mname, lname;
};

struct student_type {

    string TP_num;
    int age;
    name_type name;
};

void section1(){
    int I;
    string grade = "A";
    float CGPA;
    student_type student[2];

    for (int i = 0 ; i < 2 ; i++){
        cout << "TP number: ";
        cin >> student[i].TP_num;

        cout << "name >> fname mname lname: ";
        cin >> student[i].name.fname >> student[i].name.mname >> student[i].name.lname;
    }

    for (int j = 0 ; j < 2 ; j++){
        cout << "student: "<< j << ". ";
        cout << student[j].name.fname << student[j].name.mname << student[j].name.lname << " ";
        cout << student[j].TP_num << endl;
    }

}

void section2(){
    int num, s, sum, square;
    cout << "Enter a number: ";
    cin >> num;

    sum = num + num;
    square = num * num;

    cout << sum << endl;
    cout << square << endl;

}

int main(){


    return 0;

}
