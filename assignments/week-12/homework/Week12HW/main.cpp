/*
 Program Name: Week12HW.cpp
 Programmer: Kevin Fischer
 Date: 5-15-26
 Version: 1.0
 The point of this program is to make
 a recursive program that counts the
 number of times a character appears in a string
 */

#include <iostream>
#include <string>
using namespace std;

class countChar
{
    private:
        char find;
    
    public:
        countChar(char ch)
        {
            find = ch;
        }
    
    
        int counting(string s)
        {
            if (s.length() == 0)
                return 0;
            
            else if (s[s.length() - 1] == find)
                return 1 + counting(s.substr(0, s.length() - 1));
            
            return counting(s.substr(0, s.length() - 1));
        }
    
};

int main()
{
    string phrase = "abcddddefdddd";
    countChar s1 = countChar('d');
    
    cout << s1.counting(phrase) << endl;
}
