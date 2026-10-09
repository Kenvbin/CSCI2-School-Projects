/*
 Program Name: Week8HW.cpp
 Programmer: Kevin Fischer
 Date: 4-11-26
 Version: 1.0
 The goal for this program is to be able to take an
 input of a string from the user with parenthesis
 and the program lets the user know if the parenthesis are
 balanced of not
 */

#include <iostream>
#include <string>
using namespace std;

class Balanced
{
    private:
        struct Node
        {
            char value;
            Node *next;
        };
    Node *top;
    
    public:
        Balanced() // default constructor
        {
            top = nullptr;
        }
        
        void push(char c)
        {
            Node *newNode = new Node;
            newNode -> value = c;
            newNode -> next = top;
            top = newNode;
        }// end of push function
    
        bool isEmpty()
        {
            if (top == NULL)
            {
                return true;
            }
            else
                return false;
        }// end of isEmpty function
        
        void pop()
        {
            if(top != nullptr)
            {
                Node *temp = top;
                top = top -> next;
                delete temp;
            }
        }//end of pop function
    
        bool isBalanced(string a)
        {
            for (int i = 0; i < a.length(); i++)
            {
                if (a[i] == '(') // finds the start of parenthesis and if it finds it then it gets pushed to the stack
                {
                    push(a[i]);
                }
                else if (a[i] == ')')
                {
                    if(isEmpty()) // if the program finds a right parenthesis before finding a left one then the parenthesis' arent balanced
                    {
                        return false;
                    }
                    pop(); // empty list when finding pair of parenthesis'
                }
            }
            
            return isEmpty();
        }//end of isBalanced function
    
}; // end of balanced class

int main() {
    Balanced user;
    string input;
    
    cout << "Enter a string to check if the parenthesis are balanced: ";
    cin >> input;
    
    if (user.isBalanced(input))
        cout << "Its balanced\n";
    else
        cout<< "Not balanced\n";
}
