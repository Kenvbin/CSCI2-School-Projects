/*
 Program Name: Week11Lab.cpp
 Programmer: Kevin Fischer
 Date: 5-2-26
 Version: 1.0
 The purpose of this program is to make an IceCreamCone
 class the user is prompted to enter a number of scoops from
 1-3 and the flavor either vanilla or chocolate if theres
 an invalid input then the program throws an error
 */

#include <iostream>
using namespace std;

class IceCreamCone
{
    private:
        int scoops;
        string flavor;
    
    public:
    
        class IceCreamConeScoops {};
        class IceCreamConeFlavor {};
    
        //constructor with 2 parameters
        IceCreamCone(int s, int f)
        {
            setScoops(s);
            setFlavor(f);
        }
    
        void setScoops(int s)
        {
            if (s > 3 || s < 1)
                throw IceCreamConeScoops();
            
            scoops = s;
        }
    
        void setFlavor(int f)
        {
            if (f > 2 || f < 1)
                throw IceCreamConeFlavor();
            else if (f == 2)
                flavor = "Chocolate";
            else
                flavor = "Vanilla";
            
        }
    
        void static getMessage(bool a)
        {
            if (a)
                cout << "Invalid Number of scoops entered" << endl;
            else
                cout << "Invalid Flavor entered" << endl;
        }
};

int main()
{
    int scoop, flavor;
    
    //get input from the user for scoops and flavor
    cout << "Enter how many scoops you want (1-3): ";
    cin >> scoop;
    
    cout << "Enter what flavor you want (1:Vanilla / 2:Chocolate): ";
    cin >> flavor;
    
    try
    {
        //create an object for the user and set the scoop and flavor
        IceCreamCone user = IceCreamCone(scoop, flavor);
    }
    catch (IceCreamCone::IceCreamConeScoops)
    {
        //cant use user object in the catch so i made the getMessage function static
        IceCreamCone::getMessage(true);
    }
    catch (IceCreamCone::IceCreamConeFlavor)
    {
        IceCreamCone::getMessage(false);
    }
}
