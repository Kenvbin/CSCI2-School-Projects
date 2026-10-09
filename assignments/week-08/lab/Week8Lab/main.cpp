/*
 Program Name: Week8Lab.cpp
 Programmer: Kevin Fischer
 Date: 4-11-26
 Version: 1.0
 Create a MathStack class which has the
 following functions add, sub, mult, div,
 addAll, and multAll.
 */

#include <iostream>
using namespace std;

class MathStack
{
    private:
        struct Node
        {
            int value;
            Node *next;
        };
    Node *top;
    
    public:
        MathStack() // default constructor
        {
            top = nullptr;
        }
        
        bool isEmpty()
        {
            if (top == NULL)
            {
                return true;
            }
            else
                return false;
        }// end of isEmpty function
        
        void push(int num)
        {
            Node *n = new Node;
            n -> value = num;
            n-> next = NULL;
            if (isEmpty())
            {
                top = n;
            }
            else
            {
                n -> next = top;
                top = n;
            }
        }//end of push function
    
        void add()
        {
            Node *temp;
            if (top == nullptr || top -> next == nullptr)
            {
                cout << "Not enough items in stack.\n";
                return;
            }
            else
            {
                int temp1 = top -> value;
                temp = top;
                top = top -> next;
                delete temp;
                
                int temp2 = top -> value;
                temp = top;
                top = top -> next;
                delete temp;
                
                Node *newNode = new Node;
                newNode -> value = temp1 + temp2;
                newNode -> next = top;
                top = newNode;
            }
        }//end of add function
        
        void sub()
        {
            Node *temp;
            if (top == nullptr || top -> next == nullptr)
            {
                cout << "Not enough items in stack.\n";
                return;
            }
            else
            {
                int temp1 = top -> value;
                temp = top;
                top = top -> next;
                delete temp;
                
                int temp2 = top -> value;
                temp = top;
                top = top -> next;
                delete temp;
                
                Node *newNode = new Node;
                newNode -> value = temp1 - temp2;
                newNode -> next = top;
                top = newNode;
            }
        }//end of sub function
        
        void mult()
        {
            Node *temp;
            if (top == nullptr || top -> next == nullptr)
            {
                cout << "Not enough items in stack.\n";
                return;
            }
            else
            {
                int temp1 = top -> value;
                temp = top;
                top = top -> next;
                delete temp;
                
                int temp2 = top -> value;
                temp = top;
                top = top -> next;
                delete temp;
                
                Node *newNode = new Node;
                newNode -> value = temp1 * temp2;
                newNode -> next = top;
                top = newNode;
            }
        }// end of mult function
        
        void div()
        {
            Node *temp;
            if (top == nullptr || top -> next == nullptr)
            {
                cout << "Not enough items in stack.\n";
                return;
            }
            else
            {
                int temp1 = top -> value;
                temp = top;
                top = top -> next;
                delete temp;
                
                int temp2 = top -> value;
                temp = top;
                top = top -> next;
                delete temp;
                
                Node *newNode = new Node;
                newNode -> value = temp2 / temp1;
                newNode -> next = top;
                top = newNode;
            }
        }// end of div function
    
        void addAll()
        {
            Node *temp;
            int total = 0;
            
            if (isEmpty())
            {
                cout << "Stack is empty.\n";
                return;
            }
            else
            {
                while (top != NULL)
                {
                    total = total + top -> value;
                    temp = top;
                    top = top -> next;
                    delete temp;
                }
                
                Node *newNode = new Node;
                newNode -> value = total;
                newNode -> next = top;
                top = newNode;
            }
        }// end of addAll function
    
        void multAll()
        {
            Node *temp;
            int total = 1;
            
            if (isEmpty())
            {
                cout << "Stack is empty.\n";
                return;
            }
            else
            {
                while (top != NULL)
                {
                    total = total * top -> value;
                    temp = top;
                    top = top -> next;
                    delete temp;
                }
                
                Node *newNode = new Node;
                newNode -> value = total;
                newNode -> next = top;
                top = newNode;
            }
        }//end of multAll function
    
        void display()
        {
            Node *curr;
            curr = top;
            while (curr != NULL)
            {
                cout << curr -> value << " ";
                curr = curr -> next;
            }
        }// end of display function
}; // end of MathStack class


int main() {
    MathStack user;
    int input;
    
    //get numbers from the user for the stack and then run functions
    while (true)
    {
        cout << "Enter numbers to add to stack (0 to exit): ";
        cin >> input;
        if (input == 0)
            break;
        user.push(input);
    }
    
    user.add();
    cout << "List after adding: ";
    user.display();
    
    
    user.sub();
    cout << "List after subtracting: ";
    user.display();
    
    
    user.mult();
    cout << "List after multiplying: ";
    user.display();
    
    user.div();
    cout << "List after dividing: ";
    user.display();
    
    
    user.addAll();
    cout << "List after adding all: ";
    user.display();
    
    input = 1;
    
    // get more values from user so then they can test multiplying all numbers
    while (true)
    {
        cout << "Enter more numbers to add to stack (0 to exit): ";
        cin >> input;
        if (input == 0)
            break;
        
        user.push(input);
    }
    user.multAll();
    cout << "List after multiplying all: ";
    user.display();
}
