
#include <iostream>
using namespace std;

double calcInflationRate(float cpi1, float cpi2);
void getCPIValues(float &cpi1, float &cpi2);
void sortSwap(double arr[], int arrSize);
void swapElements(double &i, double &j);
double findMedianRate(double arr[],int arrSize);

int main()   
{
    const int MAX_RATES = 20; // global index for arr
    double inflation_rates [MAX_RATES];
    float cpi1;
    float cpi2;
    char yesNo;
    double iTotal = 0; // inflation added total for calculating avg
    int computedCount = 0; // counts how many inflation rate operations have been conducted. (Y) input +1
    double inflationRate = 0;

    do
    {
        getCPIValues(cpi1, cpi2);
        inflationRate = calcInflationRate(cpi1, cpi2);
        iTotal += inflationRate;
        inflation_rates[computedCount] = inflationRate; // stores current indexed value into array
        cout << "Inflation rate is " << inflationRate << endl;
        computedCount++;

        cout << "Try again? (Y or N): " ;
        cin >> yesNo;
    } 
    while((yesNo == 'Y' || yesNo == 'y') && computedCount < MAX_RATES); // loops while user inputs y and the amount of inflation calcs fit into arr 

    if(computedCount > 0)
    {
        sortSwap(inflation_rates, computedCount); // sorts and swaps from min to max inflation rates in arr

        double avgTotal = iTotal / computedCount;
        cout << "Average rate is: " << avgTotal << endl;

        double medianRate = findMedianRate(inflation_rates, computedCount);
        cout << "Median rate is: " << medianRate;
    }
    else
    {
        cout << "invalid" << endl;
    }
   return 0;
}

double calcInflationRate(float cpi1, float cpi2)
{
    double cpiTotal = ((cpi2 - cpi1) / cpi1) * 100;
    
    return cpiTotal;
}

void getCPIValues(float &cpi1, float &cpi2)
{
    do
    {
        cout << "Enter the old and new consumer price indices: " << endl;
        cin >> cpi1;
        cin >> cpi2;
        if(cpi1 <= 0 || cpi2 <= 0)
        {
            cout << "Error: CPI values must be greater than 0." << endl;
        }
    }
    while (cpi1 <= 0 || cpi2 <= 0);
}

void sortSwap(double arr[], int arrSize)
{
    for(int i = 0; i < arrSize - 1; i++) // arrSize -1 to account for index of arr starting at 0
    {
        int minIndex = i;
        for(int j = i + 1; j < arrSize; j++) // j = i + 1 -> j is always the index following i in arr
        {
            if(arr[j] < arr[minIndex])  // checks if j is less than i
            {
                minIndex = j;
            }
        }
        if(minIndex != i) // if minIndex isnt equal to i than j is less than i so they must be swapped 
        {
            swapElements(arr[i], arr[minIndex]);
        }
    }
}

void swapElements(double &i, double &j)
{
    double temp = i;
    i = j;
    j = temp;
}

double findMedianRate(double arr[],int arrSize) // arr must be sorted for this to work, implement sortSwap() if not
{
    if(arrSize % 2 == 0)
    {
        return (arr[arrSize / 2 - 1] + arr[arrSize / 2]) / 2.0;
    }
    else 
    {
        return arr[arrSize / 2];
    }
}