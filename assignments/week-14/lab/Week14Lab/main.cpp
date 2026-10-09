/*
 Program Name: Week14Lab.cpp
 Programmer: Kevin Fischer
 Date: 5-23-26
 Version: 1.0
 The goal of this program is to write an
 insert function where the user is able to insert
 values into a heap tree and for each new
 value that is added the order changes depending
 on the properties of Max Heap
 */

#include <iostream>
using namespace std;

class HeapTree
{
    private:
        int size;
        int count = 0;
        int *array;
    
    public:
        
        HeapTree(int s, int a[])
        {
            size = s;
            array = a;
        }
    
        int leftChild(int k)
        {
            return (2*k)+1;
        }
    
        int rightChild(int k)
        {
            return (2*k)+2;
        }
    
        int parent(int k)
        {
            return (k-1)/2;
        }
    
        void insert(int n, int index)
        {
            array[index] = n;
            
            // while the current value isnt at the root and while the parent value is smaller
            // you swap the parent value and the inserted value in the tree then you
            // set the index to the parent to reiterate through the array to reorder it
            while (index > 0 && array[parent(index)] < array[index])
            {
                swap(array[parent(index)], array[index]);
                index = parent(index);
            }
            
            count ++;
        }
    
        void display()
        {
            cout << "Heap Tree: ";
            for (int i = 0; i < count; i++)
                cout << array[i] << " ";
            cout << endl;
        }
};


int main()
{
    int size, val;
    
    cout << "Enter the size of the tree: ";
    cin >> size;
    
    int tree[size];
    
    HeapTree user = HeapTree(size, tree);
    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a value: ";
        cin >> val;
        
        user.insert(val, i);
        user.display();
    }
    
    return 0;
}
