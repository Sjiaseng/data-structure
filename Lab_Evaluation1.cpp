#include <iostream>
using namespace std;

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

        // allow to set other initial values
        cashRegister(int cash){
            cashOnHand = cash;
        };

};

int main(){
    cashRegister myregister;
    myregister.getCurrentBalance();
    myregister.acceptAmount();
    myregister.getCurrentBalance();
}
