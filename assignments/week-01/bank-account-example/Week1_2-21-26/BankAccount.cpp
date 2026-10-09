/*
 Program Name: BankAccount.cpp
 Programmer: Kevin Fischer
 Date: 2/21/2026
 Version: 1.0
 We want to create a BankAccount class with constructors
 withdraw and deposit functions. We create objects with balance
 and bank account number then we withdraw and deposit some
 money.
 */

#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount
{
    private:
        string accountNo;
        double balance;
    public:
        //default constructor
        BankAccount()
        {
            accountNo = "None";
            balance = 0.0;
        }
        
        //Constructor with two arguments
        BankAccount(string accNo, double bal)
        {
            accountNo = accNo;
            balance = bal;
        }
        
        //getter or accessor functions
        string getAccountNo()
        {
            return accountNo;
        }
        double getBalance()
        {
            return balance;
        }
        
        //setter or mutator functions
        void setAccountNo(string accn)
        {
            accountNo = accn;
        }
        void setBalance(double bl)
        {
            balance = bl;
        }
        
        //We want to deposit some money
        void deposit(double amount)
        {
            balance += amount;
        }
        
        //We want to withdraw some money
        void withdraw(double money)
        {
            if (balance < money)
                cout << "Insufficient Funds." << endl;
            else
                balance -= money;
        }
        
        //Display account info
        void display()
        {
            cout << "Account Number: " << accountNo << endl;
            cout << "Balance is $" << fixed << setprecision(2) << balance << endl;
        }
}; //end class

//Driver for class
int main()
{
    BankAccount myaccount("12345", 15000);//constructor with 2 arguments
    myaccount.display();
    myaccount.withdraw(17000);
    myaccount.deposit(50000);
    myaccount.withdraw(24000);
    myaccount.display();
    
    cout << "Information of another account number\n";
    BankAccount acc2; //using default constructor
    acc2.display();
    acc2.setAccountNo("678910");
    acc2.setBalance(90000);
    acc2.display();
    
    cout << "The balance is $" << acc2.getBalance() << endl;
    
}//end main
