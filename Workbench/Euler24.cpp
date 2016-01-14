#include <iostream>
#define limit 10
using namespace std;

bool checknum(int*);

int main()
{
	int numbers[limit], counter = 0;
	for (int i = 0; i < limit; i++)
		numbers[i] = i;

	do
	{		
		if (checknum(numbers))
		{
			if (++counter == 1000000)
				break;
			if (counter % 10000 == 0)
				cout << counter/10000 << "...";
		}
		numbers[limit - 1]++;

		for (int i = limit - 1; i > 0; i--)
		{
			if (numbers[i] > limit - 1)
			{
				numbers[i - 1]++;
				numbers[i] = 0;
			}
		}
	} while (numbers[0] <= limit - 1);

	cout << endl;
	for (int i = 0; i < limit; i++)
		cout << numbers[i];

	return 0;
}

bool checknum(int*a)
{
	for (int i = limit - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
				return false;
		}
	}

	//for (int i = 0; i < limit - 1; i++)
	//{
	//	for (int j = i + 1; j < limit; j++)
	//	{
	//		if (a[i] == a[j])
	//			return false;
	//	}
	//}

	return true;
}