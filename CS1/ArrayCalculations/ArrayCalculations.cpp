/*
Harrison Groves
Computer Science I - Dakota Heranadez
Array Calculations assignment
April 30, 2024
*/
#include <iostream>

using namespace std;

int maxInput = 50;

// function for user to initialize array
int initializeArray(int arr[]) 
{
    int num;
    int count = 0;
    cout << "Enter up to " << maxInput << " non-negative whole numbers seperated by space, end input with a negative number:\n";
    while (count < maxInput) 
    {
        cin >> num;
        if (num < 0)
        {
            break;
        }
        arr[count++] = num; // goes up 1 in array and assigns that place an int num from user
    }
    return count;
}

void displayArray(const int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// check if number occurs in array
bool checkNumber(const int arr[], int size, int num) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

// counts how many times number occurs in array
int countOccurrences(const int arr[], int size, int num) 
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == num)
        {
            count++;
        }
    }
    return count;
}

// Function to calculate min, max, sum, and average of elements in the array
void calculateStats(const int arr[], int size, int& min, int& max, int& sum, double& avg) 
{
    min = max = arr[0];//initialize min and max with first element of arr 
    sum = 0;
   
    for (int i = 0; i < size; ++i)  // Calculate sum, min, and max
    {
        sum += arr[i];
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    avg = static_cast<double>(sum) / size;// Calculate average using static cast to convert int sum to double sum

    cout << "The minimum value in the array is " << min << endl;
    cout << "The maximum value in the array is " << max << endl;
    cout << "The sum of all the elements in the array is " << sum << endl;
    cout << "The average of all the elements in the array is " << avg << endl;
}

int main() 
{
    int searchValue;
    int freqSearchValue;
    int min, max, sum;
    double avg;
    int arr[maxInput]; //initialize arr with 50 elements
    int size = initializeArray(arr); // sets size to however many values user inputs to initializeArray function
    displayArray(arr, size);
    calculateStats(arr, size, min, max, sum, avg);

    cout << "Please enter the value you want to search in the array: ";
    cin >> searchValue;
    
    if (checkNumber(arr, size, searchValue))
    {
        cout << "Find your target " << searchValue << endl;
    }
    else
    {
        cout << "Could not find " << searchValue << endl;
    }

    cout << "Please enter the value you want to know the frequncy of: ";
    cin >> freqSearchValue;
    int freq = countOccurrences(arr, size, freqSearchValue);
    cout << "The number " << freqSearchValue << " has occured " << freq << " time(s) in the array";
    return 0;
}