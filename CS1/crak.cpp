#include <iostream>
using namespace std;

int main() 
{
      int num, sum;

    sum = 0;

    cout << "Enter a positive integer: ";

    cin >> num;

    for (int count = 1; count <= num; ++count) {

        sum += count;

    }

    cout << "Sum = " << sum << endl;

    return 0;
}