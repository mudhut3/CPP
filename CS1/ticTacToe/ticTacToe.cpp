/*
Harrison Groves 
Computer Science I - Dakota Hernandez 
Tic-Tac-Toe Final project
Wednesday May 8, 2024
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 3;
const int COLS = 3;
char board[ROWS][COLS]; // 3x3 board for game 

void greetUser()
{
    cout << "Welcome to Tic-Tac-Toe!\n";
}

char playerOrder() 
{
    if (rand() % 2 == 0) 
    {
        return 'X';
    } 
    else 
    {
        return 'O';
    }
}

void initBoard() // sets/initializes every value of array board with an underscore 
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = '_';
        }
    }
}

void drawBoard() //draws the multi-dimensional array using for loop nested in a for loop 
{
    cout << "+---+---+---+\n";

    for (int i = 0; i < ROWS; i++)
    {
        cout << "| ";
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j] << " | ";
        } 
        cout << "\n+---+---+---+\n";
    }
}


bool moveCheck(int row, int col) // checks is space is an underscore
{
    if (board[row][col] == '_' && row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        return true;
    }
    else 
    {
        cout << "Invalid entry, try again\n";
        return false;
    }
}

void userMove(char userMoving) 
{
    int row, col;
    do 
    {
        cout << "Player " << userMoving << "'s turn, input row then column number (1-3): ";
        cin >> row >> col;
    } 
    while (row != 1 && row != 2 && row != 3 && col != 1 && col != 2 && col != 3);
    
    row--; 
    col--; 

    while (!moveCheck(row, col)) 
    {
        cout << "Invalid move. Please try again.\n";
        cout << "Player " << userMoving << "'s turn, input row then column number (1-3): ";
        cin >> row >> col;
        row--; 
        col--;
    }

    board[row][col] = userMoving; // assigns player symbol to input row and space index # after checking if valid move and if a value 1 - 3 was input
    drawBoard();
}

bool rowCheck(char userMoving)// iterates through rows with i value to check for 3 repeat player symbols (X or O)
{
    for (int i = 0; i < ROWS; i++)
    {
        if(board[i][0] == userMoving && board[i][1] == userMoving && board[i][2] == userMoving)
        {
            return true;
        }
    }
        return false;
}

bool colCheck(char userMoving)// iterates through columns with i value to check for 3 repeat player symbols (X or O)
{
    for (int i = 0; i < COLS; i++)
    {
        if(board[0][i] == userMoving && board[1][i] == userMoving && board[2][i] == userMoving)
        {
            return true;
        }
    }
        return false;       
}

bool diagonalCheck(char userMoving)// iterates through diagonals with i value to check for 3 repeat player symbols (X or O)
{
    if((board[2][0] == userMoving && board[1][1] == userMoving && board[0][2] == userMoving) || (board[0][0] == userMoving && board[1][1] == userMoving && board[2][2] == userMoving))
    {
        return true;
    }
    return false;
}

bool winCheck(char userMoving)//condenses previous functions
{
    if (rowCheck(userMoving) || colCheck(userMoving) || diagonalCheck(userMoving))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool boardFullCheck() // checks if board is full using the same logic to check for underscores _
{
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            if (board[i][j] == '_')
                return false;
        }
    }
    return true;
}

char playAgainCheck()
{
    char playAgain;
    do 
    {
        cout << "would you like to play again (Y/N)?: ";
        cin >> playAgain;

    }
    while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n');
    return playAgain;
}

int main()
{
    char playerX = 'X';
    char playerO = 'O';
    int turns = 1; // is increased by 1 at the end of each turn to prevent extra loops/ turns
    int xWins = 0;
    int oWins = 0;
    char playAgain; // input for playAgainCheck()

    greetUser();
    srand(time(0));
    char currentPlayer = playerOrder(); //initialize random player order
    

    do //loop to resart game if users chooses to with playAgianCheck()
    {   
        char firstLastGame = currentPlayer;
        initBoard();
        drawBoard();
        
        cout << "Player " << currentPlayer << " will go first\n";
        
        for (int i = 0; i < turns; i++) // user move and game state check loop, also switch
        {
            if(boardFullCheck())
            {
                cout << "It's a tie!\n";
                if (firstLastGame == playerX)
                {
                    currentPlayer = playerO;
                }
                else
                {
                    currentPlayer = playerX;
                }
                break;
            }

            userMove(currentPlayer);

            if (winCheck(currentPlayer)) // counts player wins
            {
                cout << "Player " << currentPlayer << " wins! ";
                if (currentPlayer == playerX)
                {
                    xWins++;
                }
                else if (currentPlayer == playerO)
                {
                    oWins++;
                }
                if (firstLastGame == playerX)
                {
                    currentPlayer = playerO;
                }
                else
                {
                    currentPlayer = playerX;
                }
                break;
            }
            if (currentPlayer == playerX) // switches control between players
            {
                currentPlayer = playerO;
            }
            else
            {
                currentPlayer = playerX;
            }
            turns++;
        }
        playAgain = playAgainCheck(); // initializes user playAgain choice
    }
    while (playAgain == 'Y' || playAgain == 'y');
    
    cout << "Score:\n";
    cout << "X's had " << xWins << " wins\n";
    cout << "O's had " << oWins << " wins\n";
    cout << "Thanks For Playing!";

    return 0;
}
