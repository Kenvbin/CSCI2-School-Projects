/*
 Program Name: Rectangle.cpp
 Programmer: Kevin Fischer
 Version: 1.0
 I want to create the rectangle class with constructors set length/width,
 get length/width, CalcArea, and display functions. I will create an object
 for the user and they need to input their values for the length and width.
 */

#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle
{
    private:
        double width;
        double length;
    public:
        
        //Default constructor
        Rectangle()
        {
            width = 0;
            length = 0;
        }
        
        //Constructor with 2 parameters
        Rectangle(double len, double wid)
        {
            //Make sure the length isnt negative
            while (len < 0)
            {
                cout << "Enter a valid length: ";
                cin >> len;
            }
            length = len;
            
            //Make sure the width isnt negative
            while (wid < 0)
            {
                cout << "Enter a valid width: ";
                cin >> wid;
            }
            width = wid;
        }
        
        //Getter functions
        double getWidth()
        {
            return width;
        }
        double getLength()
        {
            return length;
        }
        
        //Setter functions
        void setWidth(double wid)
        {
            //Make sure width isnt negative
            while (wid < 0)
            {
                cout << "Enter a valid width: ";
                cin >> wid;
            }
            width = wid;
        }
        
        void setLength(double len)
        {
            //Make sure length isnt negative
            while (len < 0)
            {
                cout << "Enter a valid length: ";
                cin >> len;
            }
            length = len;
        }
        
        //Calculates and returns the area of the rectangle
        double CalcArea()
        {
            return length*width;
        }
        
        //Displays length, width, and area
        void display()
        {
            cout << "Length: " << length << endl;
            cout << "Width: " << width << endl;
            cout << "Area: " << CalcArea() << endl;
        }
        
    
};//end class

//Driver for class
int main()
{
    //Create a user object for the user
    Rectangle user;
    double userLength;
    double userWidth;
    
    cout << "Enter length: ";
    cin >> userLength;
    user.setLength(userLength);
    
    cout << "Enter width: ";
    cin >> userWidth;
    user.setWidth(userWidth);
    
    user.display();
    
    cout << "\nTest get length, get width, and CalcArea functions." << endl;
    cout << "The length is: " << user.getLength() << endl;
    cout << "The width is: " << user.getWidth() << endl;
    cout << "The area is: " << user.CalcArea() << endl;
    
}//end main
