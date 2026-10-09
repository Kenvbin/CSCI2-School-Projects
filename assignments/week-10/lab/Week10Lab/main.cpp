/*
 Program Name: Week10Lab.cpp
 Programmer: Kevin Fischer
 Date: 4-25-26
 Version: 1.0
 The purpose of this program is to be able to accept
 an array and calculate the average of all scores in the array
 if any value is greater than 100 or less than 0 it throws an error
 */

#include <iostream>
using namespace std;

class TestScores
{
    private:
        double* testScores;
        double total;
        int size;
    public:
        TestScores(int s, double scores[])
        {
            testScores = scores;
            size = s;
        }
        
        double scoresAverage()
        {
            total = 0.0;
            for (int i = 0; i < size; i++)
            {
                if (testScores[i] < 0 || testScores[i] > 100)
                    throw testScores[i];
                else
                {
                    total += testScores[i];
                }
            }
            return (total / size);
        }
    
}; // end of testscores class

int main()
{
    double s1[5] = {50, 30, 20, 70, 99};
    double s2[10] = {87, 66, 67, 78, 99, 100, 89, 22, 83, 0};
    double s3[4] = {100, -1, 200, 40};
    
    try {
        TestScores a1 = TestScores(5,s1);
        TestScores a2 = TestScores(10,s2);
        TestScores a3 = TestScores(4,s3);
        
        cout << a1.scoresAverage() << "\n" << a2.scoresAverage() << "\n" << a3.scoresAverage() << endl;
    } catch (...) {
        cout << "ERROR SCORE OUT OF BOUNDS\n";
    }
}
