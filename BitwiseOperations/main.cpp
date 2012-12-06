//
//  main.cpp
//  BitwiseOperations
//
//  Created by Riddhiman Das 
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// takes an unsigned int and returns a binary string representation
string dec2bin(unsigned n)
{
    string res;
    
    while (n)
    {
        res.push_back((n & 1) + '0');
        n >>= 1;
    }
    
    if (res.empty())
        res = "0";
    else
        reverse(res.begin(), res.end());
    
    return res;
}

// Takes an bit string and converts it into an unsigned int
int bin2dec(const char * str)
{
    unsigned val = 0;
    
    while (*str != '\0')
        val = 2 * val + (*str++ - '0');
    return val;
}

int main(int argc, const char * argv[])
{
    cout << "Basics of Bitwise Operations:" << endl << "\t" <<
        "OR can be used to set a bit to one" << endl << "\t" <<
        "AND can be used to set a bit to zero" << endl << "\t" <<
        "XOR can be used to invert or toggle a bit" << endl << "\t" <<
        "AND together with zero-testing can be used to determine if a bit is set" << endl;
    
    int countRequired = 0;
    cout << "How many different values should the bit vector satisfy? ";
    cin >> countRequired;
    
    assert(countRequired <= 32);
    
    unsigned value = 1;
    vector<int> turnOnValues(countRequired);
    
    cout << "Count bits from left" << endl;
    for (unsigned i = 0; i < countRequired; i++)
    {
        cout << "To check if bit " << (i+1) << " is true, check against " << (value) << " e.g. isBit" << (i+1) << "Set= ((roles & " << value << ") != 0)\nbinary representation of " << value << " is " << dec2bin(value) << endl;
        turnOnValues.push_back(value);
        value = value << 1;
    }
    
    cout << endl << "Do you want to test for multiple bits being true in one statement (y/n): ";
    string strAns;
    cin >> strAns;
    if (strAns == "y")
    {
        int intAns = -1;
        vector<int> rolesToTurnOn;
        do
        {
            cout << "Enter role # or -1 to end: ";
            cin >> intAns;
            if (intAns >= 0 && intAns <= countRequired)
            {
                int value = pow(2, intAns-1);
                rolesToTurnOn.push_back(value);
                cout << "Will set " << value << "(" << dec2bin(value) << ") to true." << endl;
            }
        } while (intAns >= 0 && intAns <= countRequired);
        
        if (rolesToTurnOn.size() > 0) {
            sort (rolesToTurnOn.begin(), rolesToTurnOn.end());
            
            intAns = 0;
            for (std::vector<int>::iterator it = rolesToTurnOn.begin() ; it != rolesToTurnOn.end(); ++it)
            {
                intAns |= *it;
            }
            cout << "For these bits, XOR of the bitvector with " << intAns << " should be 0.\n" << intAns << "'s binary representation is: " << dec2bin(intAns) << endl;
            cout << "Example C++ usage will be : ((roles ^ " << intAns << ") == 0)" << endl;
            cout << "Confirmation Test: " << ((intAns ^ intAns) == 0) << endl;
        } else {
            cout << "No valid input detected." << endl;
        }
    }
    cout << "Bye";
    return 0;
}

