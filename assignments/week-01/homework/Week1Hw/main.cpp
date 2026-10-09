/*
 Program Name: mortgagePayment.cpp
 Programmer: Kevin Fischer
 Version 1.0
 The goal for this program is to make a class which is able
 to calculate the monthly payment for someones mortgage. As well as
 output the total amount paid for the mortgage.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class mortgagePayment
{
    private:
        double principal;
        double interest;
        int years;
    
    public:
        // default constructor
        mortgagePayment()
        {
            principal = 0.0;
            interest = 0.0;
            years = 0;
        }
    
        //setter functions
        void setPrincipal(double l)
        {
            //Make sure the user doesnt input a negative value
            while (l < 0)
            {
                cout << "Enter a valid principal value: ";
                cin >> l;
            }
            principal = l;
        }
        
        void setInterest(double i)
        {
            //Make sure the user doesnt input a negative value
            while (i < 0)
            {
                cout << "Enter a valid interest value: ";
                cin >> i;
            }
            interest = i;
        }
        
        void setYears(int y)
        {
            //Make sure the user doesnt input a negative value
            while (y < 0)
            {
                cout << "Enter a valid value for the term: ";
                cin >> y;
            }
            years = y;
        }
        
        // getter functions
        double getmonthlyPayment()
        {
            //Calculate the interest rate and term from the user's input
            double rate = interest / 1200.0;
            double term = years * 12.0;

            //to prevent error if user enters 0 for interest
            if (rate == 0)
                return principal / term;
            
            //Calculate and return monthly payments for user
            return ((principal*rate)/(1.0-pow(rate+1, -term)));
        }
        double gettotalPaid()
        {
            //Calculate and return the total mortgage payment for the user
            return getmonthlyPayment() * (years * 12);
        }
        
}; // End of class

int main() {
    double principal;
    double rate;
    int term;
    
    //Make an object for the user
    mortgagePayment user;
    
    //Prompt the user for the principal, interest rate, and term for mortgage
    cout << "Enter the principal for the mortgage: $";
    cin >> principal;
    user.setPrincipal(principal);
    
    cout << "Enter the interest for the mortgage: ";
    cin >> rate;
    user.setInterest(rate);
    
    cout << "Enter the term for the mortgage: ";
    cin >> term;
    user.setYears(term);
    
    //Output the monthly payments for the user's mortgage as well as the total amount the user will pay for the mortgage
    cout << "\nYour monthly payment will be: $" << fixed << setprecision(2) << user.getmonthlyPayment() << endl;
    cout << "The total ammount you will pay to the bank for the mortgage will be: $" << fixed << setprecision(2) << user.gettotalPaid() << endl;
    
}// End of main
