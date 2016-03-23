#include <iostream>
#include <math.h>
using namespace std;

void displaytime(float years)
{
	bool cut = false;

	do
	{
		if (years < 1.0 / (60 * 60 * 24 * 365))
		{
			cout << "less than a second";
			break;
		}
		if (years >= 1)
		{
			cout << years - fmod(years, 1) << " years ";
			years = fmod(years, 1);
			cut = true;
		}
		if (years >= 1.0 / 12)
		{
			cout << (years - fmod(years, 1.0 / 12)) * 12 << " months ";
			years = fmod(years, 1.0 / 12);
			if (cut)
				break;
			cut = true;
		}
		if (years >= 1.0 / 365)
		{
			cout << (years - fmod(years, 1.0 / 365)) * 365 << " days ";
			years = fmod(years, 1.0 / 365);
			if (cut)
				break;
			cut = true;
		}
		if (years >= 1.0 / (24 * 365))
		{
			cout << (years - fmod(years, 1.0 / (365 * 24))) * 365 * 24 << " hours ";
			years = fmod(years, 1.0 / (365 * 24));
			if (cut)
				break;
			cut = true;
		}
		if (years >= 1.0 / (60 * 24 * 365))
		{
			cout << (years - fmod(years, 1.0 / (365 * 24 * 60))) * 365 * 24 * 60 << " minutes ";
			years = fmod(years, 1.0 / (365 * 24 * 60));
			if (cut)
				break;
			cut = true;
		}
		if (years >= 1.0 / (60 * 60 * 24 * 365))
		{
			cout << (years - fmod(years, 1.0 / (365 * 24 * 60 * 60))) * 365 * 24 * 60 * 60 << " seconds ";
			years = fmod(years, 1.0 / (365 * 24 * 60 * 60));
			break;
		}
	} while (0);
	cout << endl;
}

int main()
{
	float speed;
	cout << "Speed in lightyears per year (multiple of c): ";
	cin >> speed;
	cout << "Distance to Alpha Centauri:   ";
	displaytime(4.367 / speed);
	cout << "Distance to Senate:           ";
	displaytime(10000 / speed);
	cout << "Distance across human domain: ";
	displaytime(22500 / speed);
	cout << "Distance traveled by probes:  ";
	displaytime(40000 / speed);
	cout << "Distance across Galaxy:       ";
	displaytime(100000 / speed);
	cout << "Distance to nearest Galaxy:   ";
	displaytime(2500000 / speed);

	return 0;
}