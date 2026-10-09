/*
 Program Name: Week11HW.cpp
 Programmer: Kevin Fischer
 Date: 5-1-26
 Version: 1.0
 This program should have a queue class
 the user should be able to input 2 sentences
 and then the program checks whether or not
 they are equal
 */

#include <iostream>
using namespace std;

class DynQueue
{
    private:
        struct Node
        {
            char value;
            Node *next;
        };
    Node *front;
    Node *rear;
    int numItems;
    
    public:
        DynQueue()
        {
            front = nullptr;
            rear = NULL;
            numItems = 0;
        }
    
        ~DynQueue()
        {
            clear();
        }
    
        void enqueue(char num)
        {
            Node *n = new Node;
            n -> value = num;
            n -> next = NULL;
            if (isEmpty())
            {
                front = n;
                rear = n;
            }
            
            else
            {
                rear -> next = n;
                rear = n;
            }
            numItems++;
        }
    
        void dequeue(char &num)
        {
            if (isEmpty())
                cout << "The queue is empty\n";
            else
            {
                if (numItems == 1)
                {
                    num = front -> value;
                    delete front;
                    rear = NULL;
                    numItems --;
                }
                else
                {
                    num = front -> value;
                    Node *temp = front;
                    front = front -> next;
                    delete temp;
                    numItems--;
                }
            }
        }
    
        bool isEmpty() const
        {
            if (numItems > 0)
                return false;
            else
                return true;
        }
    
        void clear()
        {
            char val;
            while (!isEmpty())
            {
                dequeue(val);
            }
        }
};

int main()
{
    
    DynQueue sent1, sent2;
    string sen1, sen2;
    char c1, c2;
    
    cout << "Enter a sentence: ";
    getline(cin, sen1);
    
    
    cout << "Enter a second sentence: ";
    getline(cin, sen2);
    
    //add each character from the sentences the user inputed into each queue object
    for (char ch : sen1)
        sent1.enqueue(ch);
    
    for (char ch : sen2)
        sent2.enqueue(ch);
    
    while (!sent1.isEmpty() || !sent2.isEmpty())
    {
        //if one of the objecs is empty while the other still has characters then the sentences arent equal
        if (sent1.isEmpty() != sent2.isEmpty())
        {
            cout << "Sentences are not equal!\n";
            return 0;
        }
        
        sent1.dequeue(c1);
        sent2.dequeue(c2);
        //check if each character is equal
        if (c1 != c2)
        {
            cout << "Sentences are not equal!\n";
            return 0;
        }
    }
    // if the while loop runs through then the sentences are equal
    cout << "The sentences are equal.\n";
    return 0;
}
