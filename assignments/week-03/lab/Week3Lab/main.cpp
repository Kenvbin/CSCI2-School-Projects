/*
 Program Name: Week3Lab.cpp
 Programmer: Kevin Fischer
 Date: 3-7-26
 Version: 1.0
 The goal for this program is to be able to take a fraction as
 an input from the user in the format "numerator/denominator"
 and then overload the operations such as multiplication,
 division, comparisons, insertion, and extraction
 */

#include <iostream>

using namespace std;

class Fraction
{
    private:
        double num, denom;
    
    public:
        //Default constructor
        Fraction()
        {
            num = 0;
            denom = 1;
        }
        
        //Constructor with 2 parameters
        Fraction(double n, double d)
        {
            num = n;
            denom = d;
        }
        //Getter or accessor functions
        double getDenom() const
        {
            return denom;
        }
        double getNum() const
        {
            return num;
        }
        
        //Setter or mutator functions
        void setNum(double n)
        {
            num = n;
        }
        void setDenom(double d)
        {
            denom = d;
        }
    
    //friend function prototypes
    friend Fraction operator* (Fraction f1, Fraction f2); // Multiplication operator overload
    friend Fraction operator/ (Fraction f1, Fraction f2); // Division operator overload
    friend ostream &operator<< (ostream &o, const Fraction &f); // Insertion operator overload
    friend istream &operator>> (istream &i, Fraction &f); // Extraction operator overload
    friend bool operator< (Fraction f1, Fraction f2); // Less than operator overload
    friend bool operator> (Fraction f1, Fraction f2); // Greater than operator overload
        
}; // End of fraction class

Fraction operator* (Fraction f1, Fraction f2)
{
    Fraction temp;
    temp.num = f1.num * f2.num;
    temp.denom = f1.denom * f2.denom;
    return temp;
}//end * func

Fraction operator/ (Fraction f1, Fraction f2)
{
    Fraction temp;
    temp.num = f1.num * f2.denom;
    temp.denom = f1.denom * f2.num;
    return temp;
}//end / func

ostream &operator<< (ostream &o, const Fraction &f)
{
    o << f.getNum() << "/" << f.getDenom();
    return o;
}// end << func

istream &operator>> (istream &i, Fraction &f)
{
    char slash = '/';
    i >> f.num >> slash >> f.denom;
    return i;
}//end >> func

bool operator< (Fraction f1, Fraction f2)
{
    return (f1.num * f2.denom) < (f2.num * f1.denom);
    
}// end < func

bool operator> (Fraction f1, Fraction f2)
{
    return (f1.num * f2.denom) > (f2.num * f1.denom);
}// end > func

//Driver for class
int main() {
    //Create 2 fraction objects for the user
    Fraction userF1, userF2;
    
    //Prompt the user for 2 fractions in the format of "Numerator/Denominator"
    cout << "Enter the numerator and denominator for fraction 1 (num/denom): ";
    cin >> userF1;
    
    cout << "Enter the numerator and denominator for fraction 2 (num/denom): ";
    cin >> userF2;
    
    
    //usage of all the different overriden operators
    cout << "You entered " << userF1 << " for fraction 1." << endl;
    cout << "You entered " << userF2 << " for fraction 2." << endl;
    
    
    cout << "Multiply fraction 1 by fraction 2: " << userF1 * userF2 << endl;
    cout << "Divide fraction 1 by fraction 2: " << userF1 / userF2 << endl;
    if (userF1 < userF2)
        cout << "Fraction 1 is less than Fraction 2" << endl;
    else if (userF1 > userF2)
        cout << "Fraction 1 is greater than Fraction 2" << endl;
    else
        cout << "Both fractions are equal" << endl;
}
