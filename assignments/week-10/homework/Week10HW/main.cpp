/*
 Program Name: Week10HW.cpp
 Programmer: Kevin Fischer
 Date: 4-25-26
 Version: 1.0
 The point of this class is to convert the users input
 of a month, day, and year as integers and print them
 in 3 different formats. The program should throw and error
 if the day or month is out of bounds
 */

#include <iostream>
using namespace std;

class Date
{
    private:
        int month, day, year;
    string months[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    public:
    class invalidDay {};
    class invalidMonth {};
    
    void setMonth(int m)
    {
        if (m < 1 || m > 12)
            throw invalidMonth();
        month = m;
    }
    
    void setDay(int d)
    {
        if (d < 1 || d > 31)
            throw invalidDay();
        day = d;
    }
    
    void setYear(int y)
    {
        year = y;
    }
    
    void monthdayyearNumeral()
    {
        cout << month << "/" << day << "/" << year << endl;
    }
    
    void monthdayyearWords()
    {
        cout << months[month-1] << " " << day << ", " << year << endl;
    }
    
    void daymonthyearWords()
    {
        cout << day << " " << months[month-1] << " " << year << endl;
    }
};

int main()
{
    Date user;
    int m, d, y;
    
    while (true)
    {
        try {
            cout << "Enter a month: ";
            cin >> m;
            user.setMonth(m);
            
            cout << "Enter a day: ";
            cin >> d;
            user.setDay(d);
            
            cout << "Enter a year: ";
            cin >> y;
            user.setYear(y);
            
            cout << endl;
            
            user.daymonthyearWords();
            user.monthdayyearNumeral();
            user.monthdayyearWords();
            
        } catch (Date::invalidMonth) {
            cout << "You entered an invalid month" << endl;
        }
        catch (Date::invalidDay) {
            cout << "You entered an invalid day" << endl;
        }
        
        return 0;
    }
}
