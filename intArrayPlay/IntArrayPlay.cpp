/* 
    Harrison Groves
    September 13, 2024
    CS2 - Hernandez
    IntArrayPlay - working with partially filled array
*/
#include <iostream>
using namespace std;

void fillArray(int arr[], int arrSize, int &arrFilled);
void displayArr(int arr[], int arrSize);
bool isArrSorted(int arr[], int arrFilled);
int searchElement(int arr[], int arrFilled, int element);
int findPosition(int arr[], int arrFilled, int insertValue);
bool removeElement(int arr[], int &arrFilled, int indexToDelete);
bool insertElement(int arr[], int &arrFilled, int numToInsert, int atIndex);

const int CAPACITY = 20;

int main()
{   
    int arr[CAPACITY];
    int arrFilled = 0;
    int searchValue = 0;
    int insertValue = 0;
// TODO 1 prompts user to input nums and displays them after
    cout << "Enter a list of up to 20 integers or -1 to end the list" << endl;
    fillArray(arr, CAPACITY, arrFilled);
    displayArr(arr, arrFilled);
    
// TODO 2 prompts user to insert a value to insert, insert then display the array

    cout << "Enter a value to insert: " << endl; 
    cin >> insertValue;

        if(arrFilled >= CAPACITY) // checks if array can input another value or is too full
    {
        cout << "ERROR: array is full!" << endl;
    }
    else
    {
        int insertPosition = findPosition(arr, arrFilled, insertValue); 
        insertElement(arr, arrFilled, insertValue ,insertPosition);
    }

    displayArr(arr, arrFilled);

// TODO 3 // displays if array is sorrted after user inserts a num
    if(isArrSorted(arr, arrFilled))
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is NOT sorted" << endl;
    }

// TODO 4 prompts user to insert a value to remove, searches for value, removes it then displays it
int removeThisValue = 0;
cout << "Enter a value to remove: " << endl;
cin >> removeThisValue;

int removeThisIndex = searchElement(arr, arrFilled, removeThisValue);

if(removeThisIndex != -1)  // in case searchElement ^ returns -1
{
removeElement(arr, arrFilled, removeThisIndex);
displayArr(arr, arrFilled);
}
else
{
    cout << "not found" << endl;
}

return 0;
}

void displayArr(int arr[], int arrSize) // displays user input array
{
    for(int i = 0; i < arrSize; i++)
    {
       cout << arr[i] << ' ';
    }
   cout << endl;
}


void fillArray(int arr[], int arrSize, int &arrFilled) // takes user input to fill array
{
    arrFilled = 0;

    for(int i = 0; i < arrSize; i++)
    {
        int temp = 0;
        cin >> temp;
        if(temp == -1)
        {
            break;
        }
        else
        {
            arr[i] = temp;
            arrFilled++;
        }
    }
}

int findPosition(int arr[], int arrFilled, int insertValue) // assumes sorted array
{
    for(int i = 0; i < arrFilled; i++)
    {
        if(insertValue < arr[i])
        { 
            return i;
        } 
    }
    return arrFilled; // for default
}

bool isArrSorted(int arr[], int arrFilled) // checks if arr is sorted in ascending order
{
    for(int i = 0; i < arrFilled - 1; i ++)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int searchElement(int arr[], int arrFilled, int element) // searches for int in array and returns its index or -1 if not found
{
    int notFound = -1;
    for(int i = 0; i < arrFilled; i++)
    {
        if(element == arr[i])
        {
            return i;
        }
    }
    return notFound;
}

bool removeElement(int arr[], int &arrFilled, int indexToDelete)
{
    if(indexToDelete >= arrFilled || indexToDelete < 0)
    {
        return false;
    }
    for(int i = indexToDelete; i < arrFilled - 1; i++) // loop that starts at index to delete then overwrites it and the rest of the array by setting each index equal to the following then reducing arrFilled to compensate
    {
        arr[i] = arr[i + 1];
    }
    arrFilled--;
    return true;
}

bool insertElement(int arr[], int &arrFilled, int insertValue, int insertPosition)
{   

    if(insertPosition < 0 || insertPosition > arrFilled) 
    {
        return false; // Invalid index
    }

    for(int i = arrFilled; i > insertPosition; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[insertPosition] = insertValue;

    arrFilled++;

    return true;
}
