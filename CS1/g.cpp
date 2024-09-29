#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
    srand(300);
    int i = rand() % 100;
    cout << i;
}