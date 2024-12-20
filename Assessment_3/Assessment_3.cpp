#include <iostream>
#include <string>
#include <ctime>  
using namespace std;

class ATM {
private:
    string pin;             
    double balance;          
    double startingBalance;  

public:
	
    ATM(string initPin, double initBalance) {
        pin = initPin;              
        balance = initBalance;       
        startingBalance = 60000;     
    }

    void displayDateTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "\nWelcome to ATM\n";
        cout << "\n\n\t Current Date and Time: " << dt ;
    }

    bool validatePin() {
        string enteredPin;
        cout << "Enter your ATM PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            return true; 
        } else {
            cout << "\n\n\t Incorrect PIN.";
            return false;
        }
    }
    void displayHelp() {
        cout << "\nATM Help:\n";
        cout << "\n\n\t 1. Enter correct PIN to access account";
        cout << "\n\n\t 2. You can deposit or withdraw money from your account";
        cout << "\n\n\t 3. You can check your account balance at any time";
        cout << "\n\n\t 4. Always keep your PIN confidential";
    }

    void depositMoney() {
        double depositAmount;
        cout << "\n\n\t Enter the amount to deposit: Rs. ";
        cin >> depositAmount;

        if (depositAmount > 0) {
            balance += depositAmount;
            cout << "Rs. " << depositAmount << "\n\n\t deposited successfully.";
            cout << "\n\n\t New Balance: Rs. " << balance ;
        } else {
            cout << "\n\n\t Invalid deposit amount!";
        }
    }
    void withdrawMoney() {
        double withdrawAmount;
        cout << "\n\n\t Enter the amount to withdraw: Rs. ";
        cin >> withdrawAmount;

        if (withdrawAmount > 0 && withdrawAmount <= balance) {
            balance -= withdrawAmount;
            cout << "Rs. " << withdrawAmount << "\n\n\t withdrawn successfully.";
            cout << "\n\n\t Remaining Balance: Rs. " << balance ;
        } else {
            cout << "\n\n\t Insufficient balance or invalid amount!";
        }
    }
    void checkBalance() {
        cout << "\n\n\t Current Account Balance: Rs. " << balance;
    }
};


int main() {
    ATM atm("12345", 20000);  

    int choice;
    bool pinVerified = false;

    atm.displayDateTime();  

    pinVerified = atm.validatePin();
    if (!pinVerified) {
        return 0;  
    }

    do {
        cout << "\n\n\t ------------------------ATM Menu---------------------------\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Help\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                atm.depositMoney();  
                break;

            case 2:
                atm.withdrawMoney();  
                break;

            case 3:
                atm.checkBalance();  
                break;

            case 4:
                atm.displayHelp(); 
                break;

            case 5:
                cout << "\n\n\t Exiting the ATM.";
                break;

            default:
                cout << "\n\n\t Invalid choice! Please try again.";
        }

    } while (choice != 5);  

}

