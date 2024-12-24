#include <iostream>
using namespace std;


/* Class Example Section 1
struct date_type{
    int day, month, year;
};

struct student_type{
    int ID;
    date_type birthdate;
    date_type reg_date;
};

// if use structure no security / encapsulation
struct node_type{
    student_type data;
    struct node_type *link;
};

class NodeType{
    public: 
        int info;
        NodeType *link;
};

int main(){
    struct node_type header;
}
*/

struct info_type{
    string name, gender;
    double height, weight;
    int age;
};

// only the node need to put struct initiator.
struct patient_type{
    info_type info;
    struct patient_type *next;
};

int main(){
    patient_type *patient;
    patient -> info.name = "John";
    patient -> info.gender = "M";
    patient -> info.height = 157.60;
    patient -> info.age = 45;
    patient -> info.weight = 67.8;
}