#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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

int multAndSum(ifstream& inStream) 
{
    int total = 0;
    int num1, num2, num3;
    
    while (inStream >> num1 >> num2 >> num3) 
    {
        int result = num1 * num2 * num3;
        cout << "Current Row: " << setw(10) << result << endl;
        total += result;
    }
    return total;
}

int main() 
{
    ifstream inputFile;
    openInputFile(inputFile);
    
    int totalSum = multAndSum(inputFile);
    
    cout << "Final result: " << setw(9) << totalSum << endl;

    inputFile.close();
    return 0;
}


   