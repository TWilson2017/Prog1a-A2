//------------------------------------------------------------------
// File name:   p1.cpp
// Assign ID:   Project 1
// Due Date:    08/31/2018 at 10:20 pm
//
// Purpose:     C++ program to convert a number from any base to decimal
//       
// Author:      Tishauna Wilson
//------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
 
// Return value of a char
int returnVal(char character)
{
    if (character >= '0' && character <= '9')
        return (int)character - '0';
    else
        return (int)character - 'A' + 10;
}// returnVal
 
// Function to convert a number from given base 'B' to decimal integer
int convertToDeci(string str, int base)
{
	// Declare Variables
    int power = 1; // Power of base
    int num = 0;  // Result
    int i; // Loop Control Variable
 
    // Decimal equivalent is str[len-1]*1 + str[len-1]*base + str[len-1]*(base^2) + ...
    for (i = str.length() - 1; i >= 0; i--)
    {
        // Digit in input number must be
        // less than number's base
        if (returnVal(str[i]) >= base)
        {
           cout << endl << "Invalid Number" << endl;
           return -1;
        }
 
        num += returnVal(str[i]) * power;
        power = power * base;
    }
 
    return num;
}// convertToDeci

int main()
{
	// Declare Variables
	int baseB, positiveInteger;
	string convertInteger;

	// Print the copyright notice declaring authorship.
	cout << endl << "(c) 2018, Tishauna Wilson" << endl << endl; 
	
	// Get input and test
	cout << "Enter in [positive] integer: ";
	cin >> positiveInteger;
	
	cout << endl;
	
	cout << "Enter base B [B is between 2 and 10]: ";
	cin >> baseB;
	
	while(positiveInteger < 0)
	{
		cout << "Re-enter in [positive] integer: ";
		cin >> positiveInteger;
	}//while
	
	while(baseB < 2 || baseB > 10)
	{
		cout << "Re-enter base B [B is between 2 and 10]: ";
		cin >> baseB;
	}// while

	// Convert positiveInteger to string convertInteger
	stringstream conversion;
	conversion << positiveInteger;
	convertInteger = conversion.str();

	// Print Output
	cout << endl << "Decimal of " << positiveInteger << " is: " << convertToDeci(convertInteger, baseB) << endl;
	
	// Print the copyright notice declaring authorship again.
    cout << endl << "(c) 2018, Tishauna Wilson" << endl << endl; 
	
	return 0;
}// main