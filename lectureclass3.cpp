#include <iostream>
#include "myClasses.hpp"
using namespace std;

class lecturer{
    private:
        int number;
    
    public:
        int lecture(){
            cout << "Enter the number of studetns in the class: ";
            cin >> number;
            cout << "Total number of students are: " << number << endl;

            return 0;
        };
        int increasenumber(int num){
            number += num;
            cout << "Total numbers are: " << number << endl;

            return 0;
        };

        /* Constructor
        lecturer(int number){
            this -> number = number;
        }
        */
};

int Greeting::greet() {
    cout << "Hello World" << endl;
    return 0;
}

class Employee{
    public:
        string employee_name, employee_id, employee_department, employee_salary, employee_job_title;

        Employee() {
            employee_name = "";
            employee_id = "0";
            employee_department = "";
            employee_job_title = "";
        }   

        /*
        Employee(string employee_name, string employee_id, string employee_department, string employee_job_title){
            this -> employee_name = employee_name;
            this -> employee_id = employee_id;
            this -> employee_department = employee_department;
            this -> employee_job_title = employee_job_title;
        };
        
        Employee(string employee_name, string employee_id, string employee_department, string employee_job_title){
            this -> employee_name = employee_name;
            this -> employee_id = employee_id;
            this -> employee_department = "";
            this -> employee_job_title = "";
        };        
       */
       void setname(string employee_name){
            this -> employee_name = employee_name;
       }

       void setid(string employee_id){
            this -> employee_id = employee_id;
       }

        void setdepartment(string employee_department){
            this -> employee_department = employee_department;
       }

       void setsalary(string employee_id){
            this -> employee_salary = employee_salary;
       }        

        void setposition(string employee_job_title){
            this -> employee_job_title = employee_job_title;
       }

        string getname(){
            return employee_name;
       }

        string getid(){
            return employee_id;
       }

        string getdepartment(){
            return employee_department;
       }

        string getsalary(){
            return employee_salary;
       }        

        string getposition(){
            return employee_job_title;
       }

        void displayinfo(){
            cout << "Name: "<< employee_name << endl;
            cout << "ID: "<< employee_id << endl;
            cout << "Department: "<< employee_department << endl;
            cout << "Salary: "<< employee_salary << endl;
            cout << "Position: "<< employee_job_title << endl;
       }

};




int main(){
    Employee employee1, employee2, employee3;

    employee1.setname("Susan");
    employee1.setid("47899");
    employee1.setdepartment("Accounting");
    employee1.setsalary("13500.00");
    employee1.setposition("Vice President");

    employee2.setname("Matthew");
    employee2.setid("34522");
    employee2.setdepartment("IT");
    employee2.setsalary("6500.00");
    employee2.setposition("Programmer");

    employee3.setname("James");
    employee3.setid("65881");
    employee3.setdepartment("Manufacturing");
    employee3.setsalary("7500.00");
    employee3.setposition("Engineer");

    employee1.displayinfo();
    employee2.displayinfo();
    employee3.displayinfo();


    //lecturer mylecturer;
    //mylecturer.lecture();
    //mylecturer.increasenumber(20);

    //Greeting mygreeting;
    //mygreeting.greet();


    return 0;
}