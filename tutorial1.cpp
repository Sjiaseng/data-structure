#include <iostream>
#include <iomanip>
using namespace std;

void question1(){

    string myborder = "===============================================================================================================";

    cout << "My Course Name: \t\t";
    cout << "Data Structure" << endl;

    cout << "My Program Name: \t\t";
    cout << "Software Engineering" << endl;

    cout << "My Age: \t\t\t\t";
    cout << "20 years old" << endl;

    cout << "My Apcard Balance: \t\t";
    cout << "RM 2024.00" << endl;

    cout << myborder << endl;
    cout << "Student details as below:" << endl;
    cout << myborder << endl;
    
    cout << "Course \t\t\t Program \t\t\t\t Age \t\t Apcard Balance" << endl;
    cout << myborder << endl;
    cout << "Data Structure \t Software Engineering \t 20 \t\t RM2024.00" << endl;
    cout << myborder << endl;
}

void question2(){
    string myborder = "===============================================================================================================";

    cout << "My Course Name: \t\t";
    cout << "Data Structure" << endl;

    cout << "My Program Name: \t\t";
    cout << "Software Engineering" << endl;

    cout << "My Age: \t\t\t";
    cout << "20 years old" << endl;

    cout << "My Apcard Balance: \t\t";
    cout << "RM 2024.00" << endl;

    cout << myborder << endl;
    cout << "Student details as below:" << endl;
    cout << myborder << endl;

    cout << "Course:";
    cout << right << setw(35) << "Data Structure" << endl;
    cout << "Program:";
    cout << right << setw(34) << "Software Engineering" << endl;
    cout << "Age:";
    cout << right << setw(38) << "20 years old" << endl;
    cout << "ApCard Balance:";
    cout << right << setw(27) << "RM 2024.00" << endl;
}

void question3(){
    int hours, minutes, seconds = 0;
    string input = "";
    char colon;
    int result;

    cout << "Please Enter your elapsed time (in HH:MM:SS format): " << endl;
    cin >> input;

    istringstream mydate(input);
    mydate >> hours >> colon >> minutes >> colon >> seconds; 
    result = (hours * 3600) + (minutes * 60) + seconds;
    cout << "Answer is: " << result << endl;

}

void question4(){
    int input;
    int random;

    bool win = 0;

    while (win != 0){
        cout << "Guess a number from 1 to 10: ";
        cin >> input;

        srand(time(nullptr));
        random = rand() % 10 + 1;

        if(input == random){
            cout << "You Win!" << endl;
            win == 1;
        }else{
            cout << "Please Retry!" << endl;
        }

    }
}

void question5(){
    int intlist[4];
    int input;
    int i = 0;

    while(i < 5){
        cout << "Enter five numbers: ";
        cin >> input;
        intlist[i] = input;
        i++;
    }

    cout << "Numbers in the array: " << endl;
    for(int j = 0; j < 5; j++){
        cout << intlist[j] << ",";
    }
}

int main() {
    question4();
    return 0;
}