#include <iostream>
#include <vector>

using namespace std;

int const cols = 3;

int** p = new int* [cols];

for(int i = 0; i < cols; i++)
{
    p[i] = new int [4];
}

