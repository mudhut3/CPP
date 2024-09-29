/* 
 * Random number game
 * Computer Science I - Hernandez
 * Harrison Groves
 * Last Edited: March 12, 2024
 */
#include <iostream>
#include <cstdlib>
using namespace std;
bool runGame();

int main()
{
    int wins = 0;
    int losses = 0;
    char again = 'n';

    do
    {
        bool result = runGame();
        if (result == false)
        {
            losses++;
        }
        else if (result == true)
        {
            wins ++;
            
        }
        cout << "Would you like to play again? (Y/N): ";
        cin >> again;

        while (again != 'Y' && again != 'y' && again != 'N' && again != 'n')
        {
            cout << "Would you like to play again? (Y/N): ";
            cin >> again;
        } 
    } 
    while (again == 'y' || again == 'Y'); 

    if (again == 'n' || again == 'N')
    {
        cout << "Numbers of wins: " << wins << endl;
        cout << "Numbers of losses: " << losses << endl;
        cout << "Thanks for playing!";
        return 0;
    }
    return 0;
} 

bool runGame()
{
    srand(10);
    int num = rand() % 10 + 1;
    int userGuess;
    
    cout << "Can you guess the number I generated within three tries?\n ";

    for (int i = 3; i > -1; i--) //i is turns left to guess, 3 turns
    {
        cout << "Guess a number between 1-10: ";
        cin >> userGuess;
        while (userGuess > 10 || userGuess < 1)
        {
            cout << "Enter a number 1-10: ";
            cin >> userGuess;
        }
        if (i == 1)
        {
            cout << "You Lose!\n";
            return false;
        }
        else if (userGuess < num)
        {
            cout << "Go higher.\n";
            
        }
        else if (userGuess > num)
        {
            cout << "Go lower.\n";
            cout << "You have " << i - 1 << " guesses left\n";
        }
        else if (userGuess == num)
        {
            cout << "You Win!\n";
            return true;
        }
    }
    return 0;
}