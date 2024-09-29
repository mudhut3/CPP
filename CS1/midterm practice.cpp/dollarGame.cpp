#include <iostream>

int main()
{
    using namespace std;

    int p ;
    int n ;
    int d ;
    int q ;

    cout << "enter number of each coin to get total of $1.00\n";
    cout << "number of pennies?: ";
    cin >> p;
    cout << "number of nickels?: ";
    cin >> n;
    cout << "number of dimes?: ";
    cin >> d;
    cout << "number of quarters?: ";
    cin >> q;
    
    float pAmount = 0.01 * p;
    float nAmount = 0.05 * n; 
    float dAmount = 0.10 * d;
    float qAmount = 0.25 * q;
    float total = pAmount + nAmount + dAmount + qAmount ;

    if ( total == 1.00)
    {
        cout << "Youre total is $1 ...You Win!";
    }
    else 
    {
        cout << "Your total is $" << total << " You lose.";
    }


return 0;
}