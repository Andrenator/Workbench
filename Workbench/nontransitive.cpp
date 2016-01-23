#include <iostream>
#include <time.h>
using namespace std;

bool verifydice(int* a, int* b)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (a[i] == b[j])
				return false;
		}
	}

	int counter = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (a[i] > b[j])
				counter++;
		}
	}
	if (counter == 18)
		return true;
	else
		return false;
}

int main()
{
	int one[] = { 1,10,14,23,27,36 };
	int two[] = { 2,9,15,22,28,35 };

	cout << verifydice(one, two);

	return 0;
}