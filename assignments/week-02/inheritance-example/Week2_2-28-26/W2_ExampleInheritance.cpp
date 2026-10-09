/*
 Program Name: W2ExampleInheritance.cpp
 Programmer: Kevin Fischer
 Date: 2-28-26
 Version: 1.0
 We create class Rectangle then we inherit
 Box class then we find the volume of the Box.
 */

#include <iostream>
using namespace std;

class Rectangle
{
protected:
    double width, length;
public:
    //Default constructor
    Rectangle()
    {
        width = 0.0;
        length = 0.0;
    }
    //Constructor with two arguments
    Rectangle(double w, double len)
    {
        width = w;
        length = len;
    }
    //getter or accessor member functions
    //
    //setter or mutator
    
    //To calculate area
    double calcArea()
    {
        return width * length;
    }
    void display()
    {
        cout << "The area is " << calcArea() << endl;
    }
};//end Rectangle

//Box inherits from Rectangle class
class Box: public Rectangle
{
private:
    double height;
public:
    //default constructor
    Box()
    {
        height = 0.0;
        Rectangle(); //We invoke the parent default constructor
    }
    //Constructor with 3 arguments
    Box(double wid, double ln, double h):Rectangle(wid, ln) //We invoke the parent constructor
    {
        height = h;
    }
    //getter or accessor function
    double getHeight()
    {
        return height;
    }
    //setter or mutator
    void setHeight(double he)
    {
        height = he;
    }
    double volume()
    {
        return calcArea() * height;
    }
    void displayVolume()
    {
        cout << "The volume of Box is " << volume()<< endl;
    }
};
//Driver for classes

int main() {
    Box b1; //using default constructor
    Box b2(8,10,3); //constructor with 3 arguments
    b2.displayVolume();
    
    cout << "The volume of b1 is \n";
    b1.displayVolume();
    
    cout << "The area of rectangle is:" << endl;
    Rectangle rect1(2.4, 5.6);
    rect1.display();
}
