/*
 Program Name: Week7HW.cpp
 Programmer: Kevin Fischer
 Date: 3-27-26
 Version: 1.0
 Create A Student class, linked list class, and a node class.
 */

#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        string name, grade;
    public:
    
    Student()
    {
        name = "N/A";
        grade = "N/A";
    }
    
    Student(string n, string g)
    {
        name = n;
        grade = g;
    }
    
    void setName(string n)
    {
        name = n;
    }
    void setGrade(string g)
    {
        grade = g;
    }
    string getName()
    {
        return name;
    }
    string getGrade()
    {
        return grade;
    }
    
}; // End of student class

class Node
{
    public:
        Student data;
        Node *next;
    
    Node(Student d)
    {
        data = d;
        next = nullptr;
    }
}; // end of Node class

class LinkedList
{
    private:
        Node *head;
    
    public:
        LinkedList()
        {
            head = nullptr;
        }
    
        void addatEnd(Student s)
        {
            Node* add = new Node(s);
            
            if (head == nullptr) // if list is empty
            {
                head = add;
                return;
            }
            
            Node* temp = head;
            
            while (temp -> next != nullptr)
            {
                temp = temp -> next;
            }
            
            temp -> next = add;
        }
    
        void viewInfo(string n)
        {
            Node* temp = head;
            
            while (temp != nullptr && temp->data.getName() != n)
            {
                temp = temp -> next;
            }
            
            if (temp == nullptr)
            {
                cout << "Student not found\n";
                return;
            }
            cout << "Student's Name: " << temp->data.getName() << " Student's Grade: " << temp->data.getGrade() << endl;
        }
    
        void changeStudent(string studentsName, string newName, string newGrade)
        {
            Node* temp = head;
            
            while (temp != nullptr)
            {
                if (temp -> data.getName() == studentsName)
                {
                    temp -> data.setName(newName);
                    temp -> data.setGrade(newGrade);
                }
                temp = temp -> next;
            }
        }
    
        void deleteStudent(string n)
        {
            if (head == nullptr) // list is empty
            {
                cout << "List is empty\n";
                return;
            }
            
            if (head->data.getName() == n)
            {
                Node* d = head;
                head = head -> next;
                delete d;
                cout << n << " has been deleted.\n";
                return;
            }
            
            Node* temp = head;
            
            while (temp->next != nullptr && temp->next->data.getName() != n)
            {
                temp = temp -> next;
            }
            
            if (temp->next == nullptr)
            {
                cout << "Couldnt find student: " << n << endl;
                return;
            }
            
            Node* d = temp-> next;
            temp-> next = temp -> next-> next;
            delete d;
            
            cout << "Deleted Student: " << n << endl;
        }
    
        void viewAll()
        {
            Node *temp = head;
            
            while (temp != nullptr)
            {
                cout << "Student's Name: " <<temp->data.getName() << " Student's Grade: " << temp->data.getGrade() << endl;
                temp = temp -> next;
            }
        }
};

int main()
{
    LinkedList students;
    string name, grade, findName, oldName, newName, newGrade, deleteName;

    cout << "Enter first student's name: ";
    cin >> name;
    cout << "Enter first student's grade (A-F): ";
    cin >> grade;
    students.addatEnd(Student(name, grade));

    cout << "Enter second student's name: ";
    cin >> name;
    cout << "Enter second student's grade (A-F): ";
    cin >> grade;
    students.addatEnd(Student(name, grade));

    cout << "Enter third student's name: ";
    cin >> name;
    cout << "Enter third student's grade (A-F format): ";
    cin >> grade;
    students.addatEnd(Student(name, grade));

    cout << "\nAll students:\n";
    students.viewAll();

    cout << "\nEnter a student to view info: ";
    cin >> findName;
    students.viewInfo(findName);

    cout << "\nEnter the name of the student you want to change: ";
    cin >> oldName;
    cout << "Enter the new name: ";
    cin >> newName;
    cout << "Enter the new grade (A-F): ";
    cin >> newGrade;
    students.changeStudent(oldName, newName, newGrade);

    cout << "\nAll students after change:\n";
    students.viewAll();

    cout << "\nEnter the name of the student you want to delete: ";
    cin >> deleteName;
    students.deleteStudent(deleteName);

    cout << "\nAll students after deletion:\n";
    students.viewAll();

    return 0;
}
