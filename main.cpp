#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
    int accountNo;
    string name;
    double balance;
    double fdrAmount;

    static const double fdrInterestRate; // default FDR interest rate
    static const double dpsInterestRate; // default DPS interest rate

    BankAccount(int accNo, string accName, double initialBalance) {
        accountNo = accNo;
        name = accName;
        balance = initialBalance;
        fdrAmount = 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\nNew balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\nNew balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal or insufficient balance!" << endl;
        }
    }

    void createFDR(double amount, int years) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            fdrAmount += amount;
            double interest = amount * fdrInterestRate / 100 * years;
            double maturity = amount + interest;
            cout << "FDR created for " << amount << " for " << years << " years.\n";
            cout << "Maturity amount: " << maturity << endl;
        } else {
            cout << "Invalid amount for FDR or insufficient balance!" << endl;
        }
    }

    void createDPS(double monthlyAmount, int months) {
        if (monthlyAmount > 0 && months > 0) {
            double totalDeposited = monthlyAmount * months;
            double interest = totalDeposited * dpsInterestRate / 100 * months / 12;
            double maturity = totalDeposited + interest;
            cout << "DPS created with monthly amount " << monthlyAmount << " for " << months << " months.\n";
            cout << "Maturity amount: " << maturity << endl;
        } else {
            cout << "Invalid DPS input!" << endl;
        }
    }

    void showAccount() {
        cout << "Account No: " << accountNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "FDR Amount: " << fdrAmount << endl;
        cout << "----------------------" << endl;
    }
};

// Initialize static members
const double BankAccount::fdrInterestRate = 6.5;
const double BankAccount::dpsInterestRate = 5.0;

int main() {
    // Create 10 users with simple IDs and initial balance
    BankAccount users[10] = {
        BankAccount(1, "Alice", 1000),
        BankAccount(2, "Bob", 1500),
        BankAccount(3, "Charlie", 2000),
        BankAccount(4, "David", 2500),
        BankAccount(5, "Eve", 3000),
        BankAccount(6, "Frank", 3500),
        BankAccount(7, "Grace", 4000),
        BankAccount(8, "Hannah", 4500),
        BankAccount(9, "Ivan", 5000),
        BankAccount(10, "Judy", 5500)
    };

    // Show initial account info
    for (int i = 0; i < 10; i++) {
        users[i].showAccount();
    }

    cout << "\n--- Sample Transactions ---\n" << endl;

    // Some example transactions
    users[0].deposit(500);
    users[1].withdraw(200);
    users[2].createFDR(1000, 3);
    users[3].createDPS(100, 12);

    cout << "\n--- Updated Account Info ---\n" << endl;

    for (int i = 0; i < 10; i++) {
        users[i].showAccount();
    }

    return 0;
}

