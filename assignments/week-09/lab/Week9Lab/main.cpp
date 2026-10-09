/*
 Program Name: Week9Lab.cpp
 Programmer: Kevin Fischer
 Date: 4-11-26
 Version: 1.0
 This program is supposed to take a string input
 from the user and puts it into a queue of characters
 The program should dequeue each character, convert it
 to uppercase and store the result as a string.
 */

#include <iostream> 
#include <string>
using namespace std;

class StrQueue
{
    private:
        char *QArray;
        int QSize;
        int front;
        int rear;
        int numItems;
    
    public:
    
        StrQueue(string s)
        {
            QSize = s.length();
            QArray = new char[QSize];
            front = 0;
            rear = -1;
            numItems = 0;
            
            addSentence(s);
        }
        
        ~StrQueue()
        {
            delete[] QArray;
        }
    
        bool isFull()
        {
            return numItems == QSize;
        }
    
        bool isEmpty()
        {
            return numItems == 0;
        }
        
        void enqueue(char c)
        {
            if (isFull())
                cout << "The queue is full!\n";
            else
            {
                rear = (rear+1) % QSize;
                QArray[rear] = c;
                numItems++;
            }
        }
    
        void dequeue(char &c)
        {
            if (isEmpty())
            {
                cout << "Queue is empty\n";
            }
            else if (front == rear)
            {
                c = QArray[front];
                front = -1;
                rear = -1;
                numItems = 0;
            }
            else
            {
                c = QArray[front];
                front = (front+1) % QSize;
                numItems--;
            }
        }
    
        void addSentence(string i)
        {
            for(int x = 0; x < i.length(); x++)
            {
                enqueue(i[x]);
            }
        }// end of addSentence function
    
        string convertUppercase()
        {
            string final = "";
            
            while (!isEmpty())
            {
                char ch;
                dequeue(ch);
                final += toupper(ch);
            }
            return final;
        }//end of convertUppercase function
    
        void display()
        {
            if (numItems == 0)
            {
                cout << "The queue is empty!\n";
            }
            else
            {
                for (int i = 0; i < numItems;i++)
                    cout << QArray[(front+i)%QSize]<< " ";
            }
        }
        
};// end of StrQueue

int main() {
    string input;
    
    cout << "Enter sentence to convert: ";
    getline(cin, input);
    
    StrQueue user(input);
    
    user.display();
    
    string converted = user.convertUppercase();
    cout << "\nThe result converted: " << converted << endl;
    
}
