#include <iostream>
#include <iomanip>
using namespace std;
#include "tutorial4.hpp"

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

// In Header File Requires BankAccount :: function(){content}
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

// Section 1
/*
int main(){
    int dollars, cents;
    BankAccount BankAccount;
    double rate;

    cout << "Dollars: ";
    cin >> dollars;

    cout << "Cents: ";
    cin >> cents;

    BankAccount.set(dollars, cents);

    cout << "Rate: ";
    cin >> rate;
    BankAccount.set_rate(rate);

    BankAccount.update();

    cout << endl << "Updated Balance: " << BankAccount.get_balance() << endl;
    cout << "Interest Rate: " << BankAccount.get_rate() << endl;

    return 0;
}
*/

class cashRegister{
    private: 
        int cashOnHand;
    
    public:
        void getCurrentBalance(){
            cout << "Current Balance: "<< cashOnHand << endl;
        };

        void acceptAmount(){
            int amount;
            cout << "Enter Cash: ";
            cin >> amount;
            cashOnHand += amount;
        };

        cashRegister(){
            cashOnHand = 500;
        };

        cashRegister(int cash){
            cashOnHand = cash;
        };

};

int main(){
    cashRegister myregister;

    myregister.getCurrentBalance();
}


/*
class dispenserType{
    private:
        int numberOfItems, cost;
    
    public:
        void getNoOfItems(){
            cout << "Number of Items: " << numberOfItems << endl;
        }

        void getCost(){
            cout << "Costs: " << cost << endl;
        }

        void makeSale(){
            numberOfItems = numberOfItems - 1;
        }

        dispenserType(){
            cost = 50;
            numberOfItems = 50;
        };

        dispenserType(int cost, int numberOfItems){
            this -> cost = cost;
            this -> numberOfItems = numberOfItems;
        };
};
*/



