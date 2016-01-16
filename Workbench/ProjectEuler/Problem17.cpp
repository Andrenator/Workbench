#include <iostream>
using namespace std;

int processnum(int);

int main()
{
	unsigned long long int num = 0;

	for (int i = 1; i <= 1000; i++)
	{
		num += processnum(i);
		cout << "total for " << i << " is " << processnum(i) << endl;
	}

	cout << "number is " << num << endl;

	return 0;
}

int processnum(int x)
{
	if (x == 1000)
		return 11;

	int total = 0;

	int ones, tens, hundreds;

	if (x % 100 < 20)
	{
		ones = x % 100;
		tens = 0;
	}
	else
	{
		ones = x % 10;
		tens = (x % 100) / 10;
	}

	hundreds = x / 100;

	switch (hundreds)
	{
		case 0:
			break;
		case 1:
			total += 3;
			break;
		case 2:
			total += 3;
			break;
		case 3:
			total += 5;
			break;
		case 4:
			total += 4;
			break;
		case 5:
			total += 4;
			break;
		case 6:
			total += 3;
			break;
		case 7:
			total += 5;
			break;
		case 8:
			total += 5;
			break;
		case 9:
			total += 4;
			break;
		default:
			cout << "Error in hundreds for " << x << endl;
	}

	if (hundreds > 0)
		total += 7;

	if (tens > 0 || ones > 0)
		total += 3;

	switch (tens)
	{
		case 0:
			break;
		case 1:
			total += 3;
			break;
		case 2:
			total += 6;
			break;
		case 3:
			total += 6;
			break;
		case 4:
			total += 5;
			break;
		case 5:
			total += 5;
			break;
		case 6:
			total += 5;
			break;
		case 7:
			total += 7;
			break;
		case 8:
			total += 6;
			break;
		case 9:
			total += 7;
			break;
		default:
			cout << "Error in tens of " << x << endl;
	}

	switch (ones)
	{
		case 0:
			break;
		case 1:
			total += 3;
			break;
		case 2:
			total += 3;
			break;
		case 3:
			total += 5;
			break;
		case 4:
			total += 4;
			break;
		case 5:
			total += 4;
			break;
		case 6:
			total += 3;
			break;
		case 7:
			total += 5;
			break;
		case 8:
			total += 5;
			break;
		case 9:
			total += 4;
			break;
		case 10:
			total += 3;
			break;
		case 11:
			total += 6;
			break;
		case 12:
			total += 6;
			break;
		case 13:
			total += 8;
			break;
		case 14:
			total += 8;
			break;
		case 15:
			total += 7;
			break;
		case 16:
			total += 7;
			break;
		case 17:
			total += 9;
			break;
		case 18:
			total += 8;
			break;
		case 19:
			total += 8;
			break;
		case 20:
			total += 6;
			break;
		default:
			cout << "Error in ones of " << x << endl;
	}

	cout << "(" << hundreds << " " << tens << " " << ones << ") ";
	return total;
}