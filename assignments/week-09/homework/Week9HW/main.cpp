/*
 Program Name: Week9HW.cpp
 Programmer: Kevin Fischer
 Date: 4-19-26
 Version: 1.0
 The purpose of this program is to simulate
 an airport check in by using dynamic queues.
 The program needs to store details from the passengers
 and simulate passenger arrivals and check-ins
 */

#include <iostream>
#include <string>
using namespace std;

class CheckInQueue
{
    private:
        
        struct PassengerNode
        {
            string name;
            int waitTime;
            PassengerNode *next;
        };
        
        PassengerNode *front;
        PassengerNode *rear;
        int numItems;
    
    public:
        
        void enqueue(string name, int num)
        {
            PassengerNode *n = new PassengerNode;
            n -> name = name;
            n -> waitTime = num;
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
        } // end enqueue func
    
        ~CheckInQueue()
        {
            clear();
        }
    
        CheckInQueue()
        {
            front = nullptr;
            rear = NULL;
            numItems = 0;
        }
    
        void clear()
        {
            string name;
            int val;
            while(!isEmpty())
            {
                dequeue(name, val);
            }
        }
    
        bool isEmpty() const
        {
            if (numItems > 0)
            {
                return false;
            }
            else
                return true;
        }
    
        void dequeue(string &name, int &num)
        {
            
            if (isEmpty())
                cout << "The queue is empty\n";
            else
            {
                PassengerNode *temp = front;
                
                name = front -> name;
                num = front -> waitTime;
                
                front = front -> next;
                delete temp;
                numItems--;
                
                if (numItems == 0)
                    rear = NULL;
            }
        }
    
        void displayQueue()
        {
            if (isEmpty())
                cout << "Queue is empty!\n";
            else
            {
                PassengerNode *curr = front;
                
                while(curr != NULL)
                {
                    cout << curr -> name << " " << curr -> waitTime << " minutes\n";
                    
                    curr = curr -> next;
                }
            }
        }
    
        void peek()
        {
            if (isEmpty())
                cout << "Queue is empty\n";
            else
                cout << "Next passenger: " << front -> name << " " << front -> waitTime << " minutes\n";
        }
};

int main()
{
    CheckInQueue c1;
    
    c1.enqueue("Kevin", 5);
    c1.enqueue("Andrew", 4);
    c1.enqueue("Manny", 9);
    c1.enqueue("Matthew", 8);
    
    c1.displayQueue();
    
    string name;
    int wait;
    double totalPassengers = 0.0;
    double totalWaitTime = 0.0;
    
    //go through the queue and find out all the passengers and total wait time
    while (!c1.isEmpty())
    {
        c1.dequeue(name, wait);
        totalPassengers++;
        totalWaitTime += wait;
    }
    
    cout << "\nTotal passengers: " << totalPassengers << endl;
    
    if (totalPassengers > 0)
        cout << "Average wait: " << totalWaitTime / totalPassengers << " minutes\n";
    
}
