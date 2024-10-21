/* Include Header Comment Here
 */

#include <iostream>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/
void createArrays(IntPtr labs[], int labSizes[]);

/* 
freeArrays:
Releases memory we allocated with "new".
*/
void freeArrays(IntPtr labs[]);


/*
showLabs:
Displays the status of all labs (who is logged into which computer).
*/
void showLabs(IntPtr labs[], int labSizes[]);


// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(IntPtr labs[], int labSizes[]);


// ======================
// logout:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logout(IntPtr labs[], int labSizes[]);


// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(IntPtr labs[], int labSizes[]);


// ======================
//     main function
// ======================
int main()
{
	IntPtr labs[NUMLABS]; 	// store the pointers to the dynamic array for each lab
	int labSizes[NUMLABS];	// Number of computers in each lab
	int choice = -1;
	
	cout <<"Welcome to the LabMonitorProgram!\n";

	// Prompt the user to enter labsizes 
	cout <<"Please enter the number of computer stations in each lab\n"; 
	for (int i=0; i< NUMLABS; i++)
	{
		do
		{
			cout <<"How many computers in Lab "<< i+1<<"?: ";
			cin >> labSizes[i]; 
		} while (labSizes[i]<0); 
	}

	// Create ragged array structure
	createArrays(labs, labSizes);

	// Main Menu
	while (choice != 0)
	{
		cout << "MAIN MENU" << endl;
		cout << "0) Quit" << endl;
		cout << "1) Simulate login" << endl;
		cout << "2) Simulate logout" << endl;
		cout << "3) Search" << endl;
		cin >> choice;
		if (choice == 1)
		{
			login(labs, labSizes);
			showLabs(labs, labSizes);
		}
		else if (choice == 2)
		{
			logout(labs, labSizes);
			showLabs(labs, labSizes);
		}
		else if (choice == 3)
		{
			search(labs, labSizes);
		}
	}
	freeArrays(labs);		// Free memory before exiting
	cout << "Bye!\n";
	return 0;
}

void createArrays(IntPtr labs[], int labSizes[])
{
    for(int i = 0; i < NUMLABS; i++)
    {
        labs[i] = new int [labSizes[i]];
        for(int j = 0; j < labSizes[i]; j++)
        {
            labs[i][j] = -1; // initializes each computer not in use to -1
        }
    }
  //Implement the Code!
  //Hint: for each of the 4 labs, dynamically allocate an int array of size given by the number of computers in the lab. 
}

void freeArrays(IntPtr labs[])
{
    for(int i = 0; i < NUMLABS; i++)
    {
        delete[] labs[i]; // frees memory of labs array at each NUMLABS element
    }
	//Implement the Code!
}

/* showLabs:
   Displays the status of all labs (who is logged into which computer).
   Precondition: labs[] is a multidimension array of labs with computers
                 labsizes[i] contains the size of the array in labs[i]
 
 */
void showLabs(IntPtr labs[], int labSizes[])
{
	int i;
	int j;

	cout << "LAB STATUS" << endl;
	cout << "Lab #     Computer Stations" << endl;
	for (i=0; i < NUMLABS; i++)
	{
		cout << i+1 << "         ";
		for (j = 0; j < labSizes[i]; j++)
		{
			cout << (j+1) << ": ";
			if (labs[i][j] == -1)
			{
				cout << "empty ";
			}
			else
			{
				cout << labs[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void login(IntPtr labs[], int labSizes[])
{
	int labNum;
	int userID;
	int compNum;
	bool found = false; // check if user is already logged in, true if logged in
	bool fullCheck = false; // check for labs element being used, true if in use -> exits while loop
	do
	{
		cout << "Enter the 5 digit ID number of the user logging in: ";
		cin >> userID;

		for(int i = 0; i < NUMLABS; i++) // iterates through labs[] to check if user is logged in, exits function if they are
		{
			for(int j = 0; j < labSizes[i]; j++)
			{
				if(labs[i][j] == userID)
				{
					found = true;
					cout << "User logged in already, logout first!" << endl;
					return;	
				}
			}
		}
		
		cout << "Enter the lab number the user is logging in from (1-4): ";

		cin >> labNum;

		labNum--; // fixes 0 based index

		cout << "Enter computer station number the user is logging in to (1-" << labSizes[labNum] << "): ";
		cin >> compNum;
		compNum--; // fixes 0 based index
		
		if(labs[labNum][compNum] == -1)
		{
			labs[labNum][compNum] = userID;
			fullCheck = false;
		}
		else
		{
			cout << "This computer is already occupied, try again \n";
			fullCheck = true;
		}
	}
	while(fullCheck);
    labs[labNum][compNum] = userID; // logs in user
}

void logout(IntPtr labs[], int labSizes[])
{
	int userID;
	bool found = false; // if userID is found

    cout << "Enter the user ID to log out: ";
    cin >> userID;

	for(int i = 0; i < NUMLABS; i++)
	{
		for(int j = 0; j < labSizes[i]; j++)
		{
			if(labs[i][j] == userID)
			{
				cout << "Logout user " << userID << " in lab " << i + 1 << " at computer " << j + 1 << endl;
				labs[i][j] = -1;
				found = true;	
			}
		}
	}
    if(!found) // notifies user that input id is not logged in
	{
		cout << "User not logged in.\n";
	}
}

void search(IntPtr labs[], int labsizes[])
{
	int userID;
    cout << "Enter the user ID to search for: ";
    cin >> userID;

    for (int i = 0; i < NUMLABS; i++) {
        for (int j = 0; j < labsizes[i]; j++) {
            if (labs[i][j] == userID) {
                cout << "User " << userID << " is logged in at Lab " << (i+1) << ", Computer " << (j+1) << endl; // +1 for 0 index array of labs[]
                return;
            }
        }
    }
	cout << "User not logged in"<< endl; // if array iterates through entirly, no user is logged in
}