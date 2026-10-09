/*
 Program Name: Week5HW.cpp
 Programmer: Kevin Fischer
 Date: 3-15-26
 Version: 1.0
 The goal of this program is to make a DayOfYear class
 which takes an integer from 1 - 365 and converts it
 into a Month Day format
 */

#include <iostream>
using namespace std;

class DayOfYear
{
    private:
        int day, dayofMonth;
        string date;
    
    public:
    
    static string months[12]; // static member holding string of months
    
        DayOfYear(int d)
        {
            day = d;
        }
        
        string calculateDate() // Member function meant to calculate the date
        {
            if (day <= 31) // 31
            {
                date = months[0];
                dayofMonth = day;
            }
            
            else if (day <= 59) // 31 + 28
            {
                date = months[1];
                dayofMonth = day - 31; // subtract the days from the previous month
            }
            
            else if (day <= 90) // 31 + 28 + 31
            {
                date = months[2];
                dayofMonth = day - 59;
            }
                
            else if (day <= 120) // 31 + 28 + 31 + 30
            {
                date = months[3];
                dayofMonth = day - 90;
            }
                
            else if (day <= 151) // 31 + 28 + 31 + 30 + 31
            {
                date = months[4];
                dayofMonth = day - 120;
            }
                
            else if (day <= 181) // 31 + 28 + 31 + 30 + 31 + 30
            {
                date = months[5];
                dayofMonth = day - 151;
            }
                
            else if (day <= 212) // 31 + 28 + 31 + 30 + 31 + 30 + 31
            {
                date = months[6];
                dayofMonth = day - 181;
            }
                
            else if (day <= 243) // 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31
            {
                date = months[7];
                dayofMonth = day - 212;
            }
                
            else if (day <= 273) // 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30
            {
                date = months[8];
                dayofMonth = day - 243;
            }
                
            else if (day <= 304) // 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31
            {
                date = months[9];
                dayofMonth = day - 273;
            }
                
            else if (day <= 334) // 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30
            {
                date = months[10];
                dayofMonth = day - 304;
            }
                
            else // 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31
            {
                date = months[11];
                dayofMonth = day - 334;
            }
            return date;
        }
        
        void setDay(int d)
        {
            day = d;
        }
        
        void print() // Prints in Month Day format
        {
            cout << calculateDate() << " " << dayofMonth << endl;
        }
        
    
};//End of DayOfYear class

string DayOfYear::months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//Driver for class
int main()
{
    DayOfYear test(2);
    test.print(); // Prints Janurary 2
    
    test.setDay(32);
    test.print(); // Prints February 1
    
    test.setDay(365);
    test.print(); // Prints December 31
    
    test.setDay(247);
    test.print(); // Prints September 4
}
