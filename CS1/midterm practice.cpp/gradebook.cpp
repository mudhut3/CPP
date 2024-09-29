#include <iostream>

int main()
{
    using namespace std;

    int students;
    int asmtNum;
    int i = 1;
    int t = 1;
    int x [40];

    cout << "How many students?: ";
    cin >> students;
    cout << "How many assignments?:  ";
    cin >> asmtNum;

    do 
    {
        cout << "Student #" << i;
        while (asmtNum >= t)
        {
            cout << "Enter grade for asmt #" << t << ": ";
            cin >> x;
            t++;
        }
        
    }
    while (students >= i)
    

return 0;
}