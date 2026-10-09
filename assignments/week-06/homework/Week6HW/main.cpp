/*
 Program Name: Week6HW.cpp
 Programmer: Kevin Fischer
 Date: 3-27-26
 Version: 1.0
 The goal for this program is to have a Node class
 and a LinkedList class. The linkedlist class has
 functions meant to add data at the end of the linked list,
 return the size of the linked list, and search for a given
 value inside of the linked list.
 */

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
}; // End of node class

class LinkedList
{
    private:
        Node* head;
    
    public:
        LinkedList() // default constructor
        {
            head = nullptr;
        }
        
        //function meant to add an item at the end of the linked list
        void add(int data)
        {
            Node* addNew = new Node(data);
            
            if (head == nullptr)
            {
                head = addNew;
                return;
            }
            
            Node* cur = head;
            //iterate through the list so then the program can make sure its adding the item at the end
            while (cur -> next != nullptr)
            {
                cur = cur -> next;
            }
            cur -> next = addNew;
        }
        
        //function to return size of the linked list
        int getSize()
        {
            int size = 0;
            Node* cur = head;
            
            while (cur != nullptr)
            {
                size++;
                cur = cur -> next;
            }
            return size;
        }
        
        //function to search for data in the linked list
        bool search(int data)
        {
            Node* cur = head;
            
            while (cur != nullptr)
            {
                if (cur -> data == data)
                {
                    return true;
                }
                cur = cur -> next;
            }
            return false;
        }
    
}; // End of linkedlist class

//Driver for class
int main() {
    LinkedList test;
    
    test.add(0);
    test.add(1);
    test.add(2);
    test.add(3);
    
    cout << "Size of linked list: " << test.getSize() << endl;
    cout << "Search for 1: " << test.search(1) << endl;
    cout << "Search for 5 (not in list): " << test.search(5) << endl;
    
}
