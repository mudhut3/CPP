/*Cisc 1610: Computer Science I
Lab 03A: Season if

program that asks user to input number 1-12, then prints the corresponding season of that number of month

Harrison Groves
Last editied Jan 30, 2024
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    int monthIn;

    cout << "Enter a month (1-12): ";
    cin >> monthIn;
    
    if (monthIn == 12 || monthIn == 1 || monthIn == 2)  {
        cout << "it is Winter";
    }
    else if (monthIn == 3 || monthIn == 4 || monthIn == 5) {
        cout << "it is Spring";
    }
    else if (monthIn == 6 || monthIn == 7 || monthIn == 8) {
        cout << "it is Summer";
    }
    else if (monthIn == 9 || monthIn == 10 || monthIn == 11) {
        cout << "it is Winter";
    }
    else {
        cout << "Invalid month. Enter number 1-12";
    }

    return 0;
}