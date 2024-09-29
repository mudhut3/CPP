#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

void openInputFile(ifstream& inStream) 
{
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;
    
    inStream.open(filename);
    if (!inStream) 
    {
        cout << "File not found! Exiting the program." << endl;
        exit(1);
    }
}

int countCapitals(istream& input) 
{
    int count = 0;
    char capCheck;
    while (input.get(capCheck) && capCheck != '\n') 
    {
        if (isupper(capCheck)) 
        {
            count++;
        }
    }
    return count;
}

int countCapitals(string& inputSentence) 
{
    int count = 0;
    for (int i = 0; i < inputSentence.size(); i++)
        if (isupper(inputSentence[i]))
        {
            count++;
        }
    return count;
}


int main() 
{
    char choice;
    cout << "Are you using a file for input? (Y/N): ";
    cin >> choice;
    while (choice != 'Y' && choice != 'N' && choice != 'n' && choice != 'y')
    {
        cout << "Invalid input - try again.\n ";
        cout << "Are you using a file for input? (Y/N): ";
        cin >> choice;
    }
    
    if (choice == 'Y' || choice == 'y')
    {
        ifstream fileName;
        openInputFile(fileName);
        
        if (fileName.is_open())
        {
            int fileCaps = countCapitals(fileName);
            cout << "Number of capital letters: " << fileCaps << endl;
        }
        
    }
    else if ( choice == 'N' || choice == 'n')
    {
        string userInput;
        cout << "Enter your string. Press Enter/Return to end:" << endl;
        cin >> userInput;
        int capitalCount = countCapitals(userInput);
        cout << "Number of capital letters: " << capitalCount << endl;
    }
return 0;
}