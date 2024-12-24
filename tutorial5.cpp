#include <iostream>
#include <iomanip>
using namespace std;

void question1(){
    string word = "abc";
    int integer = 1;
    float real = 10.4f;
    long long biginteger = 989898989ll;

    cout << "Value of character = " << word << " ; ";
    cout << "Address of character = " << &word << endl;

    cout << "Value of integer = " << integer << " ; ";
    cout << "Address of integer = " << &integer << endl;

    cout << "Value of real = " << real << " ; ";
    cout << "Address of real = " << &real << endl;

    cout << "Value of biginteger = " << biginteger << " ; ";
    cout << "Address of biginteger = " << &biginteger << endl;
}

void question2(){
    int num = 10;
    int * ptr;

    ptr = &num;

    cout << "Address of num = " << &num << endl;
    cout << "Value of num = " << num << endl << endl;
    cout << "Address of ptr = " << &ptr << endl;
    cout << "Value of ptr = " << ptr << endl;
    cout << "Value pointed by ptr = " << *ptr << endl;
}

void question3(){
    int num1, num2, sum;
    int *ptr1, *ptr2;

    cout << "Enter any two numbers : ";
    cin >> num1 >> num2;

    cout << "Address of num1: " << &num1 << " ; ";
    cout << "Value of num1: " << num1 << endl;

    cout << "Address of num2: " << &num2 << " ; ";
    cout << "Value of num2: " << num2 << endl;

    ptr1 = &num1;
    ptr2 = &num2;

    sum = *ptr1 + *ptr2;

    cout << "Sum: " << sum << endl; 
}

void swap(int *value1, int *value2){
    int temp;

    temp = *value1;
    *value1 = *value2;
    *value2 = temp;

    cout << "After swapping in swap function: " << endl;
    cout << "Value of value1: " << *value1  << endl;
    cout << "Value of value2: " << *value2  << endl;

};

void question4(){
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Before swapping in main function: " << endl;
    cout << "Value of num1: " << num1  << endl;
    cout << "Value of num2: " << num2  << endl;

    swap(&num1, &num2);

    cout << "After swapping in main function: " << endl;
    cout << "Value of num1: " << num1  << endl;
    cout << "Value of num2: " << num2  << endl;
}

void question5(){
    int array_size, *array;

    cout << "Enter the size of array: ";
    cin >> array_size;
    cout << "Now build the array with " << array_size << " columns" << endl;
    array = new int [array_size];
    cout << "Enter elements in the developed array: " << endl;
    for(int i = 0; i < array_size ; i++){
        cin >> array[i];
    }

    cout << "The array elements = ";
    for(int i = 0; i < array_size ; i++){
        cout << array[i];
        if ( i < array_size - 1){
            cout << ',';
        }
    }
}

void convert(double *measurement){
    *measurement = *measurement * 2.54;
}

void question6 (){
    double measurement;
    cout << "Enter a length in inches, and I will convert it to centimeters : ";
    cin >> measurement;
    convert(&measurement);
    cout << fixed << setprecision(2);
    cout << "Value in centimeters: " << measurement << " cm" << endl;
}

double getLength(){
    double length;
    cout << "Enter Rectangle Length: ";
    cin >> length;

    return length;
}

double getWidth(){
    double width;
    cout << "Enter Rectangle Width: ";
    cin >> width;

    return width;
}

double getArea(double length, double width){
    double area;
    area = length * width;

    return area;
}

void displayData(double *length, double *width, double *area){
    cout << "Rectangle Length: " << *length << endl;
    cout << "Rectangle Width: " << *width << endl;
    cout << "Rectangle Area: " << *area << endl;
}

void question7(){
    double rectLength, rectWidth, rectArea;
    rectLength = getLength();
    rectWidth = getWidth();
    rectArea = getArea(rectLength, rectWidth);

    displayData(&rectLength, &rectWidth, &rectArea);

}

void calcAverage(){

}

void findLowest(){

}

void question8(int totalSubjects){

}

int main(){

    question8(123);

    return 0;
}