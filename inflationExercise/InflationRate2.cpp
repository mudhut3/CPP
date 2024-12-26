
#include <iostream>
using namespace std;

double calcInflationRate(double old_cpi, double new_cpi);

int main()   
{
    float cpi1 = 0;
    float cpi2 = 0;
    char yesNo;
    float iTotal = 0;
    int count = 0;
    double inflationRate;
    cout << "Enter the old and new consumer price indices: " << endl;
    cin >> cpi1;
    cin >> cpi2;

    
        if(cpi1 <= 0 || cpi2 <= 0)
    {
        inflationRate = 0;
    }
    else
    {
        inflationRate = calcInflationRate(cpi1, cpi2);
    }

    cout << "Inflation rate is " << inflationRate << endl;
    iTotal += inflationRate;
    count++;

    cout << "Try again? (Y or N): " ;
    cin >> yesNo;

    while(yesNo == 'Y' || yesNo == 'y')
    {   
        cout << "Enter the old and new consumer price indices: " << endl;
        cin >> cpi1;
        cin >> cpi2;
        
          if(cpi1 <= 0 || cpi2 <= 0)
        {
            inflationRate = 0;
        }
        else
        {
            inflationRate = calcInflationRate(cpi1, cpi2);
        }

        cout << "Inflation rate is " << inflationRate << endl;
        iTotal += inflationRate;
        count++;
        cout << "Try again? (Y or N): " ;
        cin >> yesNo;
    }      
    float avgTotal = iTotal / count;
    cout << "Average rate is: " << avgTotal;

   return 0;
}

double calcInflationRate(double old_cpi, double new_cpi)
{
    double cpiTotal = ((new_cpi - old_cpi) / old_cpi) * 100;
    return cpiTotal;
}
