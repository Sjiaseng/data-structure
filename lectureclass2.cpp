#include <iostream>
using namespace std;

// Class Activity 1
void calculatelength(){
    string option;

    cout << "Choose an option: " << endl;
    cout << "a. Inches " << endl;
    cout << "b. Feet " << endl;
    cin >> option;

    if(option == "a"){
        int mynumber1;
        cout << "Enter a number in inches (inch): ";
        cin >> mynumber1;

        int result;
        
        result = mynumber1 * 2.54;

        cout << "Result is: " << result << "cm" << endl;  

    }else if (option == "b"){
        int mynumber2;
        cout << "Enter a number in feet (ft): ";
        cin >> mynumber2;

        int result;
        
        result = mynumber2 * 12;

        cout << "Result is: " << result << "cm" << endl;  
    }else{
        cout << "Invalid Input" << endl;
    }

}

// Class Activity 2
void question1(){
    int x, y;

    if(y > 0){
        x = 1;
    }
}

void question2(){
    double score;

    if (score >= 80 && score <= 90){
        score = score + 5;
    }
}

void question3(){
    int x;
    cout << "Enter a number: ";
    cin >> x;

    if(x > 0 && x % 2 == 0){
        cout << "This is a Even Number" ;
    }
    else if (x > 0 && x % 2 != 0){
        cout << "This is a Odd Number";
    }else{
        cout << "Invalid Input";
    }
}

void question4(){
    int x, y;

    if(x > 0 && y > 0){
        cout << "true" << endl;
    }

}

void question5(){

    int speed, ticket;
    if(speed > 55){
        ticket = 1;
    }else{
        ticket = 0;
    }
}

// Class Activity 3
void turnfor(){
    
    for(int number = 100 ; number > 10; number -= 5){
        cout << number << endl;
    }

}

void turndo(){
    int number = 100;
    do{
        number = number - 5;
        cout << number << endl;
    }while(number > 10);
}

// Class Activity 4
void checkupper(){
    int count = 0;
    string mystring = "";
    cout << "Enter a String: ";
    cin >> mystring;

    for(char c: mystring){
        if(isupper(c)){
            count++ ;
        }
        continue;
    }
    cout << count;
}

// Class Activity 5
void getprime(){
    int start, end;
    cout << "Enter Start Value: ";
    cin >> start;
    cout << "Enter End Value: ";
    cin >> end;

    for(int i = start ; i <= end; i++){
        if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0){
            cout << i << endl;
        }
    }

}

int factorial(int);

int factorial(int num)
{
    if(num == 0)
        return 1;
    else 
        return num * factorial (num - 1);
}

int fibonnaci(int num)
{
    if(num == 0)
        return 0;
    else 
        return fibonnaci(num - 2) + fibonnaci (num - 1);
}

char main(){
    int x = 5;
    cout << factorial(x) << endl;
}

/*
int main(){
  
    return 0;
}
*/