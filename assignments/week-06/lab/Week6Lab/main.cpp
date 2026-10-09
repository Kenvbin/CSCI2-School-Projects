/*
 Program Name: Week6Lab.cpp
 Programmer: Kevin Fischer
 Date: 3-21-26
 Version: 1.0
 The goal of this program is to have a linkedlist class
 that has member functions to append a node at the end of
 a list, adding a node at the beginning, deleting a node,
 inserting a node before a value, inserting a node at
 a position, printing, and a function to count the nodes
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
        
        void insertAtPos(int value, int pos)
        {
            Node *n = new Node;
            n -> data = value;
            n -> next = NULL;
            if (pos == 1)
            {
                n -> next = head;
                head = n;
            }
            else
            {
                Node *prev = head;
                int count = 1;
                while (count < pos - 1 && prev != NULL)
                {
                    prev = prev -> next;
                    count++;
                }
                if (prev == NULL)
                {
                    cout << "Invalid Position";
                }
                else
                {
                    n -> next = prev -> next;
                    prev -> next = n;
                }
            }
        }
        void insertNode(int num) //insets a node before a given value
        {
            Node *n = new Node();
            n -> data = num;
            n -> next = NULL;
            Node *curr;
            Node *preNode;
            if (head == NULL)
            {
                head = n;
                return;
            }
            else
            {
                curr = head;
                preNode = NULL;
                while (curr != NULL && curr -> data < num)
                {
                    preNode = curr;
                    curr = curr -> next;
                }
                if (preNode == NULL)
                {
                    head = n;
                    n -> next = curr;
                }
                else
                {
                    preNode -> next = n;
                    n -> next = curr;
                }
            }
        }
        
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
    
        void addNode(int num) // Adds node at beginning
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
        
        int countNodes()
        {
            Node *curr = head;
            int count = 0;
            while (curr != NULL)
            {
                count++;
                curr = curr -> next;
            }
            return count;
        }
    
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
};//End of LinkedList class

int main()
{
    LinkedList test;
    test.addNode(8);
    test.addNode(7);
    test.addNode(5);
    test.addNode(6);
    cout << "Test adding nodes:\n";
    test.display();
    cout << "Test adding 10 at the end:\n";
    test.addAtEnd(10);
    test.display();
    cout << "Test inserting 3 at position 2:\n";
    test.insertAtPos(3, 2);
    test.display();
    test.DeleteNode(6);
    cout << "List after deleting 6:\n";
    test.display();
    cout << "Insert 6 back into list:\n";
    test.insertNode(6);
    test.display();
    cout << "There are " <<test.countNodes() << " nodes in the list." << endl;
}
