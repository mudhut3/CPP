/*Cisc 1610: Computer Science I
Lab 03A: Campus travel game

game where you start at 14 miles away from campus and have 4 turns to get there, with 3 different methods of travel, each moving a different amount of miles per turn.

Harrison Groves
Last editied Jan 30, 2024
*/

#include <iostream>
using namespace std;

int main() 
{
//declaring variables for main scope
    int total;
    int travel;
    int choice;
    int tMethod;
    int turn;
//main loop
    for (total = 14, turn = 4; turn >= 0 ; total = total - tMethod, turn--)
    {
//win or lose check
        if (total == 0)
        {
            cout << "You Win!";
            return 0;
        }
        else if (turn < 1)
        {
            cout << "You Lose!";
            return 0;
        }
        else if (total < 0)
        {
            cout << "You Lose!";
            return 0;
        }
        else 
        {
            cout << "You are " << total << " mile(s) away from campus\n";
            cout << "\tHow do you wish to travel? (1 bus, 2 subway, 3 jetpack): \n";
            cin >> choice;
//check safe for correct CHOICE input value 1-3
            while (choice < 1 || choice > 3 || !cin.good())
            {
// not sure exactly what this code is doing but it stops it from loop lock when a char is input to above cin
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Invalid choice, try again!: ";
                cin >> choice;  
            }
//sets user input to value of tMethod or travel method
            if (choice == 1) 
            {
                tMethod = 2;
            }
            else if (choice == 2)
            {
            tMethod = 5;
            }
            else if (choice == 3)
            {
            tMethod = 10;
            }
            else 
            {
            return 0;
            }
        }
    }
    return 0; 
}