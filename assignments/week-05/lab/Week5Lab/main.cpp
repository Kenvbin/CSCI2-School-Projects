/*
 Program Name: Week5Lab.cpp
 Programmer: Kevin Fischer
 Date: 3-15-26
 Version: 1.0
 Test the linked list class with a driver program.
 Use the member functions for adding nodes at
 the beginning of the list, adding nodes at the
 end of the list, deleting nodes, and displaying
 the list.
 */

#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };
    private:
        Node *head;
    public:
        LinkedList() //default constructor
        {
            head = NULL;
        }
    
        void addNode(int num)
        {
            Node *n = new Node; //Dynamic memory allocation
            n -> data = num;
            if (head != NULL)
            {
                n -> next = head;
                head = n;
            }
            else //empty list
            {
                head = n;
                n -> next = NULL;
            }
        }//end addNode
    
        void display()
        {
            Node *curr = head;
            if (curr == NULL) // empty list
                cout << "Empty List!\n";
            else
            {
                while(curr != NULL) // we are not at the end of the list
                {
                    cout << curr -> data << endl;
                    curr = curr -> next;
                }
            }
        }// end display
    
        void DeleteNode(int m)
        {
            Node *dptr = nullptr; //or NULL, address 0
            Node *temp = head;
            Node *curr = head;
            while (curr != NULL && curr -> data != m)
            {
                temp = curr;
                curr = curr -> next;
            }
            if (curr == NULL) // we are at the end of the list
            {
                cout << m << " not in list\n";
                delete dptr;
            }
            else //we found the node
            {
                dptr = curr;
                curr = curr -> next;
                temp -> next = curr;
                if (dptr == head) //When we have a list with only one Node (or Node is the first Node in the list)
                {
                    head = head -> next;
                    temp = NULL;
                }
                delete dptr;
                cout << "The value " << m << " was deleted.\n";
            }
        }//end DeleteNode
    
        void addAtEnd(int num)
        {
            Node *n = new Node;
            n -> data = num;
            if (head == NULL) //empty list
            {
                head = n;
                n -> next = NULL;
                return;
            }
            Node *curr = head;
            while (curr -> next != NULL)
            {
                curr = curr -> next;
            }
            curr -> next = n;
            n -> next = NULL;
        }//end addAtEnd
    
};//End of LinkedList class

//Driver for class
int main()
{
    int input;
    LinkedList user;
    
    cout << "Add Node at beginning: ";
    cin >> input;
    user.addNode(input);
    user.display();
    
    cout << "Add another Node at beginning: ";
    cin >> input;
    user.addNode(input);
    user.display();
    
    cout << "\nAdd Node at end: ";
    cin >> input;
    user.addAtEnd(input);
    user.display();
    
    cout << "\nDelete Node: ";
    cin >> input;
    user.DeleteNode(input);
    user.display();
    
    cout << "\nDelete Node that doest exist: "; //Delete node prints not in list
    cin >> input;
    user.DeleteNode(input);
    user.display();
    
    cout << "\nDelete another Node: "; //deleting the whole list so display prints an empty list
    cin >> input;
    user.DeleteNode(input);
    user.display();
    
    cout << "\nDelete last Node: "; //display prints empty list
    cin >> input;
    user.DeleteNode(input);
    user.display();
    
}
