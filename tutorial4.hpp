#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount { 
    private: 
        double balance; 
        double interest_rate; 

    public: 
        void set(int dollars, int cents); 
        void update();
        double get_balance();
        double get_rate();
        void set_rate(int rate);
};

void BankAccount :: set(int dollars, int cents){
    balance = dollars + double(cents) / 100;
    //cout << fixed << setprecision(2) << "Balance: " << balance << endl;
};

void BankAccount :: update(){
    double interest;
    interest = (interest_rate / 100) * balance;
    balance = balance + interest;
};

double BankAccount :: get_balance(){
    return balance;
}

double BankAccount :: get_rate(){
    return interest_rate;
}

void BankAccount :: set_rate(int rate){
    interest_rate = rate; 
}
