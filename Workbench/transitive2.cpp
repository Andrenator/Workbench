#include <iostream>
#define DICE 3
using namespace std;

bool descending(int* myarray)
{
	for (int i = 0; i < 5; i++)
	{
		if (myarray[i] <= myarray[i + 1])
			return false;
	}
	return true;
}
bool checkavg(int* myarray)
{
	if (myarray[0] + myarray[1] + myarray[2] + myarray[3] + myarray[4] + myarray[5] == 3 * (DICE * 6 + 1))
		return true;
	else
		return false;
}
bool fair(int *a, int *b)

int main()
{
	int a[] = { 1,1,1,1,1,1 };
	while (a[0] <= DICE * 6)
	{
		if (checkavg(a) && descending(a))
		{
			for (int i = 0; i < 6; i++)
				cout << a[i] << " ";
			cout << endl;
		}
		
		a[5]++;
		for (int i = 5; i > 0; i--)
		{
			if (a[i] > DICE * 6)
			{
				a[i - 1]++;
				a[i] = 1;
			}
		}
	}

	return 0;
}