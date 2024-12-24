#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

// Section A Question 1
void add(){
    int num1, num2, result;
    cout<< "Enter 1st Integer:"<< endl;
    cin >> num1;
    cout<< "Enter 2nd Integer:"<< endl;
    cin >> num2;

    result = num1 + num2;

    cout << "Sum = " << result << endl;

}

/*
int main(){
    add();
}
*/

// Section B Question 1
void RecursiveReverseDisplayNumber(int number1, int number2){

    int numbers[number2 - number1 + 1];
    int index = 0;

    for (int i = number2; i >= number1; i--) {
        numbers[index] = i;
        index++; 
    }

    string output;

    for (int j = 0; j < index; j++){
        output += to_string(numbers[j]);
        output += " + ";
        
    }

    output.pop_back();
    cout << output << " = ";
}


int RecursiveCalSum(int number1, int number2){
    int sumresult;

    for (int i = number2; i >= number1; i--) {
        sumresult += i;
    }

    return sumresult;

}

/*
int main(){

    int startvalue, endvalue;
    cout<< "Enter a start value: " << endl;
    cin >> startvalue;
    cout << "Enter a end value: " << endl;
    cin >> endvalue;

    RecursiveReverseDisplayNumber(startvalue, endvalue);

    cout << RecursiveCalSum(startvalue, endvalue) << endl;

    return 0;
}
*/

// Section B Question 2

string reverseString(string text){
    string reversedtext;
    for (int i = text.length() - 1; i >= 0; i--) {
        reversedtext += text[i];
    }

    return reversedtext;
}

bool compareString(string text1, string text2){
    string reversedtext;

    for (int i = text1.length() - 1; i >= 0; i--) {
        reversedtext += text1[i];
    }

    return reversedtext == text1;
}

/*
int main(){
    string mystring;
    string checkpalindrome;

    cout << "Enter a String: ";
    cin >> mystring;
    cout << "Reversed Entered String: " << reverseString(mystring) << endl;

    checkpalindrome = reverseString(mystring);

    if(compareString(mystring, checkpalindrome)){
        cout << "The entered string is a palindrome!" << endl;
    }else {
        cout << "The entered string is not a palindrome!" << endl;
    }

}
*/

int hot = 0;
int rainy = 0;
int cloudy = 0;

int ConvertLetterString(string month) {
    map<string, int> monthMap{
        {"January", 1},
        {"February", 2},
        {"March", 3},
        {"April", 4},
        {"May", 5},
        {"June", 6},
        {"July", 7},
        {"August", 8},
        {"September", 9},
        {"October", 10},
        {"November", 11},
        {"December", 12}
    };

    auto intmonth = monthMap.find(month);

    int monthNumber = 0;

    if (intmonth != monthMap.end()) {
        monthNumber = intmonth->second;
    }

    return monthNumber;
}

void FindDaysInMonth(int monthNumber) {
    map<int, int> daynumber{
        {1, 31},
        {2, 29},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31}
    };

    auto totaldays = daynumber.find(monthNumber);

    string weather;

    if (totaldays != daynumber.end()) {
        int dayNumber = totaldays->second;

        for (int i = 1; i <= dayNumber; i++) {
            cout << "Day " << i << " Enter 'H' for hot, 'R' for rainy, 'C' for cloudy, 'E' to end: ";
            cin >> weather;
            if (weather == "E") {
                break;
            } else if (weather == "H") {
                hot++;
            } else if (weather == "R") {
                rainy++;
            } else if (weather == "C") {
                cloudy++;
            } else {
                cout << "Invalid input please try again" << endl;
                i--; // Decrement i to stay on the same day
            }
        }

    }
}

void displayReport() {
    cout << "Report Analysis as Below: " << endl;
    cout << "Number of hot days: ";
    for (int i = 1; i <= hot; i++) {
        cout << '*';
    }
    cout << endl;

    cout << "Number of rainy days: ";
    for (int i = 1; i <= rainy; i++) {
        cout << '*';
    }
    cout << endl;

    cout << "Number of cloudy days: ";
    for (int i = 1; i <= cloudy; i++) {
        cout << '*';
    }
    cout << endl;
}

void weatherReport() {
    cout << "Number of hot days = " << hot << endl;
    cout << "Number of rainy days = " << rainy << endl;
    cout << "Number of cloudy days = " << cloudy << endl;
}

int main() {
    string month_year = "";
    string month;
    string year;
    string empty;

    cout << "Enter Your Month (e.g. August 2019): ";
    getline(cin, month_year);


    istringstream mydate(month_year);

    mydate >> month >> empty >> year;

    int mymonthnum = ConvertLetterString(month);

    FindDaysInMonth(mymonthnum);
    displayReport();
    weatherReport();

    return 0;
}