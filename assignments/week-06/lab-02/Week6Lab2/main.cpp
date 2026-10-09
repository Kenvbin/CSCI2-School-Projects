/*
 Program Name: Week6Lab.cpp
 Programmer: Kevin Fischer
 Date: 3-28-26
 Version: 1.0
 This program has an IntStack class with function
 prototypes for things like pop, push, isFull, isEmpty,
 copy constructor, search for a value, and a
 display function
 */

#include <iostream>
using namespace std;

class IntStack
{
    private:
        int *StackArray;
        int size; // size of stack
        int top; // top of the stack or index
    public:
        IntStack() // default constructor
        {
            top = -1;
        }
        IntStack(int); // constructor prototype
        IntStack(const IntStack&);//Copy constructor prototype
        ~IntStack(); // destructor prototype
        //operations
        void display(); // prototype
        void push(int); // prototype
        void pop(int &); // prototype
        bool isFull() const; // prototype
        bool isEmpty() const; // prototype
        int peek() const; // prototype displays top of the stack
        bool search(int) const; //prototype searches for value
};// end class
IntStack :: IntStack(int sz) // constructor
{
    StackArray = new int[sz]; // Dynamic Memory Allocation
    size = sz;
    top = -1;
}// end IntStack constructor

//Push func.
void IntStack::push(int num)
{
    if(isFull())
    {
        cout << "The Stack is full\n";
        return;
    }
    else
    {
        top ++;
        StackArray[top] = num;
    }
}//end push

//display func.
void IntStack::display()
{
    int t = top;
    while (t>=0)
    {
        cout << StackArray[t] << endl;
        t--;
    }
}// end display

//Deconstructor
IntStack::~IntStack()
{
    delete[] StackArray;
}

//Pop member function
void IntStack::pop(int &num)
{
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        return;
    }
    else
    {
        num = StackArray[top];
        top--;
    }
}// end pop

//isFull() func.
bool IntStack::isFull() const
{
    return(top == size-1);
}

//isEmpty() func.
bool IntStack::isEmpty() const
{
    return (top == -1);
}

//peek() func. returns top value without removing it
int IntStack::peek() const
{
    if(isEmpty())
    {
        cout << "The stack is empty.\n";
        return -1;
    }
    else
    {
        return StackArray[top];
    }
}//end peek

//copy constructor (initialize (assign) one object using another object)
IntStack::IntStack(const IntStack &obj)
{
    //Create StackArray
    if(obj.size>0)
        StackArray = new int[obj.size];
    else
        StackArray = NULL;
    //copy the size variable
    size = obj.size;
    //copy the stack contents
    for (int count = 0; count < size; count++)
    {
        StackArray[count] = obj.StackArray[count];
        top = obj.top;
    }
}// end of copy constructor

bool IntStack::search(int s) const
{
    for (int i = top; i >= 0 ; i--)
    {
        if (StackArray[i] == s)
            return true;
    }
    return false;
}

//Driver for IntStack class
int main() {
    IntStack st1(10); // using constructor
    int x;
    st1.push(7);
    st1.push(10);
    st1.push(8);
    cout << "The top element is: " << st1.peek() << endl; // 8
    st1.pop(x);
    cout << "Popped from stack.\n"; // 8
    st1.display(); // 10 7
    IntStack st3 = st1; //using copy constructor & default constructor
    IntStack st4(st1); // using copy constructor
    
    //Test the search function with if statements, which say if a certain number is found in the array
    if (st1.search(10))
        cout << "Found item through search.\n";
    else
        cout << "Couldnt find item through search.\n";
    
    if (st1.search(11))
        cout << "Found item through search.\n";
    else
        cout << "Couldnt find item through search.\n";
}// end main
