/*
 Program Name: Week4HW.cpp
 Programmer: Kevin Fischer
 Date: 3-9-26
 Version: 1.0
 The goal for this program is to make a preferredCustomer class which
 inherits from a customerData class. The preferredCustomer class will
 track how much the customer spends and will calculate the discount that
 the customer will have on all future purchases.
 */

#include <iostream>
#include <iomanip>
using namespace std;

class customerData
{
    protected:
        string customerName;
        int customerAge;
    
    public:
        customerData() // default constructor
        {
            customerName = "None";
            customerAge = 0;
        }
        
        customerData(string n, int a)// constructor with 2 arguments
        {
            customerName = n;
            while (a < 0)
            {
                cout << "Enter a valid age: ";
                cin >> a;
            }
            customerAge = a;
        }
        
        //Setter or mutator functions
        void setName(string n)
        {
            customerName = n;
        }
        void setAge(int a)
        {
            //input validation for negative values
            while (a < 0)
            {
                cout << "Enter a valid age: ";
                cin >> a;
            }
            customerAge = a;
        }
        
        //getter or accessor functions
        string getName()
        {
            return customerName;
        }
        int getAge()
        {
            return customerAge;
        }
}; // end of customer data class

class preferredCustomer: public customerData
{
    private:
        double purchaseAmount;
        double discountLevel;
    public:
        preferredCustomer(): customerData() // default constructor
        {
            purchaseAmount = 0;
            discountLevel = 0;
        }
        preferredCustomer(double a, string name, int age): customerData(name, age)// constructor with 3 arguments
        {
            //input validation for negative values
            while (a < 0)
            {
                cout << "Enter a valid purchase ammount: ";
                cin >> a;
            }
            purchaseAmount = a;
            discountLevel = calculateDiscount();
        }
        double calculateDiscount()
        {
            if (purchaseAmount < 500)
                return 0;
            else if (purchaseAmount < 1000)
                return 0.05;
            else if (purchaseAmount < 1500)
                return 0.06;
            else if (purchaseAmount < 2000)
                return 0.07;
            else
                return 0.1;
        }
        
        //Add a purchase that the customer makes potentially changing their discount
        void addaPurchase(double p)
        {
            while (p < 0)
            {
                cout << "Enter a valid purchase price: $";
                cin >> p;
            }
            purchaseAmount = purchaseAmount + p;
            discountLevel = calculateDiscount();
        }
        
        //setter or mutator function
        void setpurchaseAmount(double a)
        {
            while (a < 0)
            {
                cout << "Enter a valid purchase ammount: $";
                cin >> a;
            }
            purchaseAmount = a;
            discountLevel = calculateDiscount();
        }
        
        //getter or accessor functions
        double getPurchaseAmount()
        {
            return purchaseAmount;
        }
        double getDiscount()
        {
            return discountLevel;
        }
        void Display()
        {
            cout << "Name: " << getName() << "\nAge: " << getAge() << endl;
            cout << fixed << setprecision(2) << "Purchase Ammount: $" << getPurchaseAmount() << endl;
            cout << "Discount Level: " << fixed << setprecision(0) << (getDiscount() * 100) << "%" << endl;
        }
};// end of preferred customer class

int main()
{
    string name;
    int age;
    double purchaseammount;
    double newpurchase;
    preferredCustomer user;
    
    cout << "What is your name?: ";
    getline(cin, name);
    user.setName(name);
    
    cout << "What is your age?: ";
    cin >> age;
    user.setAge(age);
    
    cout << "What is your purchase ammount?: $";
    cin >> purchaseammount;
    user.setpurchaseAmount(purchaseammount);
    
    user.Display();
    
    cout << "\nEnter a new purchase: $";
    cin >> newpurchase;
    user.addaPurchase(newpurchase);
    
    user.Display();
}
