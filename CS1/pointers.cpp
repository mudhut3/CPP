#include <iostream>
#include <string>

using namespace std;

int main()
{
    string car = "toyota";
    string* newCar = &car;
    int input;
    cout << "1 for new car"
    cin >> input;
    cout << newCar;
    if(input == 1)
    {

    }

    return 0;
}
