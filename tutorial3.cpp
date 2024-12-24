#include <iostream>
#include <ctime>
using namespace std;

void question1(){
    string numbers[10];

    for (int i = 0 ; i < 10 ; i++){
        cout << "Enter 10 Numbers: ";
        cin >> numbers[i];

        int j = 0;
        int duplicate = 0;

        while(j < i && !duplicate){
            if(numbers[j] == numbers[i]){
                duplicate = 1;
                cout<< "Duplicate, Please Reenter!" << endl;
                i--;
            }
            j++;
        }
    }

    for(int a = 0; a < 10; a++){
        cout << numbers[a];
        if(a < 9){
            cout << ", ";
        }
    }

}

void question2(){ // linear search
    string numbers[10], num;

    for (int i = 0 ; i < 10 ; i++){
        cout << "Enter 10 Numbers: ";
        cin >> numbers[i];

        int j = 0;
        int duplicate = 0;

        while(j < i && !duplicate){
            if(numbers[j] == numbers[i]){
                duplicate = 1;
                cout<< "Duplicate, Please Reenter!" << endl;
                i--;
            }
            j++;
        }
    };

    cout << "Enter the number to search: ";
    cin >> num;

    clock_t start = clock();

    int k = 0;
    int found = 0;

    while (k < 9 && !found){
        if (numbers[k] == num){
            found = 1;
        }else{
            k++;
        }
    }

    clock_t end = clock();

    if (found){
        cout << num << " is found at index "<< k << endl;
    }else{
        cout << num << " is not found" << endl;
        double time_taken = double(end - start) / CLOCKS_PER_SEC * 1000;
        cout << "Time taken by linear search: " << time_taken << " milliseconds";
    }

}

void question3(){ // binary search
    


}

int main(){
    question3();

    return 0;
}