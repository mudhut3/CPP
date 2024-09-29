#include <iostream>
#include <string>

using namespace std;

void inputItems(string names[], int amounts[], double prices[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << "Enter information for item # " << i + 1 << " \nName: ";
        cin >> names[i];
        cout << "How much of that item? ";
        cin >> amounts[i];
        cout << "Price per item? ";
        cin >> prices[i];
    }
}

double calcTotal(const int amounts[], double prices[], int size) 
{
    double totalCost = 0.0;
    for (int i = 0; i < size; ++i) 
    {
        totalCost += amounts[i] * prices[i];
    }
    return totalCost;
}

void printList(const string names[], int amounts[], double prices[], int size) 
{
    cout << "\nThis week's shopping list: \n";
    for (int i = 0; i < size; ++i) 
    {
        cout << names[i] << "\nQuantity: " << amounts[i] << "\nPrice: $" << prices[i] << endl;
    }
    cout << "Total Cost: $" << calcTotal(amounts, prices, size) << endl;
}

int main() 
{
    const int size = 5; 
    string names[size];
    int amounts[size];
    double prices[size];

    inputItems(names, amounts, prices, size);
    printList(names, amounts, prices, size);

    return 0;
}
