/*
 Program Name: Week2Lab.cpp
 Programmer: Kevin Fischer
 Date: 2-28-26
 Version: 1.0
 The goal for this program is to make a class called Employee
 which would have things like EmployeeName, EmployeeNumber, and HireDate
 Then I will make another class named ProductionWorker which will inherit the Employee
 class. Production worker will hold things like the worker's shift, and hourly pay rate
 The class will also be able to calculate the employee's salary for a set number of hours
 */

#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
private:
    string employeeName, hireDate;
    int employeeNumber;
public:
    //Constructor with 3 arguments
    Employee(string name, string date, int num)
    {
        employeeName = name;
        hireDate = date;
        employeeNumber = num;
    }
    
    //Constructor with no arguments
    Employee()
    {
        employeeName = "";
        hireDate = "";
        employeeNumber = 0;
    }
    
    //Setter or mutator functions
    void setName(string name)
    {
        employeeName = name;
    }
    
    void setHireDate(string date)
    {
        hireDate = date;
    }
    
    void setNumber(int num)
    {
        employeeNumber = num;
    }
    
    //Getter or accessor functions
    
    string getName()
    {
        return employeeName;
    }
    
    string getHireDate()
    {
        return hireDate;
    }
    
    int getNumber()
    {
        return employeeNumber;
    }
};// End of employee class

class ProductionWorker: public Employee
{
private:
    int shift;
    double hourlyPay;
public:
    //Constructor with 5 arguments
    ProductionWorker(int s, double pay, string name, string date, int num): Employee(name, date, num)
    {
        //Check to make sure the user entered a valid shift (1 or 2)
        while (s != 1 && s != 2)
        {
            cout << "Enter a valid shift: ";
            cin >> s;
        }
        
        shift = s;
        hourlyPay = pay;
    }
    
    //Setter or mutator functions
    void setShift(int s)
    {
        //Check to make sure the user entered a valid shift (1 or 2)
        while (s != 1 && s != 2)
        {
            cout << "Enter a valid shift: ";
            cin >> s;
        }
        
        shift = s;
    }
    void setHourlyPay(double p)
    {
        hourlyPay = p;
    }
    
    
    //Getter or accessor functions
    string getShiftString()
    {
        if (shift == 1)
            return "Day Shift";
        else
            return "Night Shift";
    }
    
    int getShift()
    {
        return shift;
    }
    
    double getHourlyPay()
    {
        return hourlyPay;
    }
    
    void display()
    {
        cout << "Employee Name: " << getName() << "\nEmployee Number: " << getNumber() << "\nHire Date: " << getHireDate() << "\nShift: " << getShiftString() << "\nHourly Pay Rate: $" << getHourlyPay() << endl;
    }
    
    double calculateSalary(int hours)
    {
        return hours * hourlyPay;
    }
};// end ProductionWorker class

//Driver for classes
int main() {
    string name, date;
    int number, shift;
    double pay;
    
    cout << "Enter Employee Name: ";
    getline(cin, name);
    
    cout << "Enter Employee Number: ";
    cin >> number;
    
    cin.ignore();
    cout << "Enter Hire Date: ";
    getline(cin, date);
    
    cout << "Enter Shift: ";
    cin >> shift;
    
    cout << "Enter Hourly Pay Rate: $";
    cin >> pay;
    
    //Create an object for the user
    ProductionWorker user(shift, pay, name, date, number);
    
    cout << "Display user input" << endl;
    user.display();
    
    //Calculate and print employee salary for 40 hours of work
    cout << "Employee salary for 40 hours of work: $" << fixed << setprecision(2) << user.calculateSalary(40) << endl;
}
