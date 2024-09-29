#include <iostream>
using namespace std;

int main()
{
	int season;
	cout << "enter number of a month 1-12: ";
	cin >> season;
	switch(season)
	{
		case 12:
		case 1:
		case 2:
			cout << "it is Winter" << endl;
			break;
		case 3:
		case 4:
		case 5:
			cout << "it is Spring" << endl;
			break;
		case 6:
		case 7:
		case 8:
			cout << "it is Summer" << endl;
			break;
		case 9:
		case 10:
		case 11:
			cout << "it is Fall" << endl;
			break;

		default:
			cout << "Invalid month. Enter number 1-12" << endl;
	}

	return 0;
}
