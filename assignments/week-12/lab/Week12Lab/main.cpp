/*
 Program Name: Week12Lab.cpp
 Programmer: Kevin Fischer
 Date: 5-15-26
 Version: 1.0
 The point of this program is to make a function that
 takes an array and also the value for how long the array
 should be. then the program recursively adds all the
 values in the array and prints it.
 
 The point of this program is to make a function that gets
 an x value and a y value and then multiplies them by
 eachother by recursively adding them
 */

#include <iostream>
using namespace std;

class func1
{
    private:
        int *arr;
        int total = 0;
        int num;
    
    public:
        
        func1(int n, int array[])
        {
            arr = array;
            num = n;
        }
    
        int calcSum()
        {
            while (num > 0)
            {
                num--;
                return total + arr[num] + calcSum();
            }
            return 0;
        }
};


class func2
{
    public:
        int xtimesy(int x, int y)
        {
            while (y > 0)
                return x + xtimesy(x, y - 1);
            return 0;
        }
};


int main()
{
    int array[5] = {8, 3, 10, 9, 2};
    func1 t = func1(5, array);
    cout << t.calcSum() << endl;
    
    
    
    func2 test;
    cout << test.xtimesy(50, 8) << endl;
}
