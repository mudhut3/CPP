/*
Harrison Groves
Comp Sci 1 
Swap and mult project
- gets 2 ints from user and swaps them, swaps again and multiplys by another user input int
*/



#include <iostream>
using namespace std;

// function tht gets 2 ints from user
void get2Ints(int &num1, int &num2);
void swap(int &a, int &b);
void swapAndMult(int &a, int &b, int multiplier);
void print2Ints (int num1, int num2);

int main() 
{
    int num1, num2, multiplier;
    
    get2Ints(num1, num2);

    swap(num1, num2);

    cout << "After swap: " << endl;
    cout << num1 << " " << num2 << endl;

    cout << "Enter the multiplier: ";

    swapAndMult(num1, num2, multiplier);

    print2Ints(num1, num2);

    return 0;
}

void get2Ints(int &num1, int &num2) 
{
    cout << "Input 2 numbers: ";
    cin >> num1 >> num2;
    ;
}

// function to swap 2 ints
void swap(int &a, int &b) 
{
    int fill = a;
    a = b;
    b = fill;
}

// Function to swap 2 integers and multiply the result with a multiplier
void swapAndMult(int &a, int &b, int multiplier) 
{
    int fill = a;
    a = b;
    b = fill;
    cin >> multiplier;
    a *= multiplier;
    b *= multiplier;
}

void print2Ints (int a, int b)
{
    cout << "After swap and mult: " << a << " " << b << endl;
}