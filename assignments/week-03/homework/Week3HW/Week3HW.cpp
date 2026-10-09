/*
 Program Name: Week3HW.cpp
 Programmer: Kevin Fischer
 Date: 3-2-26
 Version: 1.0
 This program will have an abstract class called Student
 the point of this class is to have virtual functions
 that will be inherited by the Undergraduate class.
 */

#include <iostream>

using namespace std;

class Student
{
    protected:
        string name;
        int year;
    
    private:
        string major;
        int height;
    
    public:
        //virtual functions
        virtual void printInfo() = 0;
        virtual int agewhenGraduated() = 0;
};// abstract student class

class Undergraduate: public Student
{
    private:
        int age;
    public:
        //No declared constructor so the compiler uses the default c++ constructor
        
        //Setter Functions
        void setName(string n)
        {
            name = n;
        }
        
        void setYear(int y)
        {
            year = y;
        }
        
        void setAge(int a)
        {
            age = a;
        }
        
        //Getter functions
        int agewhenGraduated()
        {
            return (4 - year) + age;
        }
        void printInfo()
        {
            cout << "Student's Name: " << name << endl;
            cout << "Student's Year: " << year << endl;
            cout << "Student's Age: " << age << endl;
        }
        string getName()
        {
            return name;
        }
    
}; // End of undergraduate class

int main() {
    Undergraduate user;
    string name;
    int age, year;
    
    cout << "Enter Undergraduate's Name: ";
    getline(cin, name);
    user.setName(name);
    
    cout << "Enter Undergraduate's Age: ";
    cin >> age;
    user.setAge(age);
    
    cout << "Enter Undergraduate's Year: ";
    cin >> year;
    user.setYear(year);
    
    
    user.printInfo();
    cout << user.getName() << " will be " << user.agewhenGraduated() << " years old when they graduate." << endl;
}
