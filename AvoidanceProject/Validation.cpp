#include "Validation.h"
#include <iostream>

using namespace std;


int Validation :: IntValidation(const char msg[32])
{
	int number;
	cout << msg;
	while (true)
	{
		if (cin >> number)
			break;
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << msg;
		}
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return number;
};

double Validation :: DoubleValidation(const char msg[32])
{
	double number;
	cout << msg;
	while (true)
	{
		if (cin >> number)
			break;
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << msg;
		}
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return number;
};



