/*
    Harrison Groves
    April 1, 2024
    Computer Science I
    Program that either prints sin values for a given max degree and incrementation, or graphs it given the same parameters
*/
#include <iostream>
#include <cmath>
using namespace std;

double Degrees2Radians(double degrees);
void DrawLine(char letter, int numRepetitions);
void doPrinting(double highestAngle, double angleIncrement, char characterToPrint, int numberOfCharsToPrint);
void doGraphing(double highestAngle, double angleIncrement);
int main() 
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint); 
    cout.precision(5);

    double highestA;
    cout << "Perform calculations from angle=0 to what value (in degrees)?: ";
    cin >> highestA;
    
    double angleInc;
    cout << "How often should the angle be incremented?: ";
    cin >> angleInc;

    char graphQ;
    cout << "Graph it?";
    cin >> graphQ;

    int lineTimes;
    char lineChar;

    while (graphQ != 'y' & graphQ != 'Y' & graphQ != 'n' & graphQ != 'N')
    {
        cin >> graphQ;
    }

    if (graphQ == 'y' || graphQ == 'Y')
    {
        doGraphing(highestA, angleInc);
    }
    else if (graphQ == 'n' || graphQ == 'N')
    {
        cout << "Make the line from what character?: ";
        cin >> lineChar;

        cout << "How many characters form a line?: ";
        cin >> lineTimes;
        doPrinting(highestA, angleInc, lineChar, lineTimes); 
    }
    
    return 0;
}

double Degrees2Radians(double degrees) 
{
    return degrees * (3.141592653589793238 / 180.0);
}

void DrawLine(char character, int numRepetitions)
{
   for (int i = 0; i < numRepetitions; ++i) 
    {
        cout << character;
    }
    cout << endl; 
}

void doPrinting(double highestAngle, double angleIncrement, char characterToPrint, int numberOfCharsToPrint) 
{
    for (int angle = 0; angle <= highestAngle; angle += angleIncrement) 
    {
        double inRadians = Degrees2Radians(angle);
        double ofSinRadians = sin(inRadians);

        cout << "sin(" << angle << ") = " << ofSinRadians << endl;
       
        if (angle % 90 == 0 && angle != 0)
        {
            DrawLine(characterToPrint, numberOfCharsToPrint);
        }
    }
}

void doGraphing(double highestAngle, double angleIncrement)
{
    char plotLetter = 'X';
    
    for (int angle = 0; angle <= highestAngle; angle += angleIncrement) 
    {   
        double inRadians = Degrees2Radians(angle);
        double ofSinRadians = sin(inRadians);
        double offset = 20 + (ofSinRadians * 20);
       for (double i = 0; i < offset; i++)
       {
            cout << " ";
       }
       cout << plotLetter << endl;
    }
}