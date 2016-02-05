//Rules:
//	a beats b beats c beats a
//	no dice may tie with each other (self is ok)
#include <iostream>
#define SIDES 12
using namespace std;

bool dicetie(int* first, int* second)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (first[i] == second[j])
				return true;
		}
	}
	return false;
}
int wins(int* first, int* second)
{
	int tugowar = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (first[i] > second[j])
				tugowar--;
			else
				tugowar++;
		}
	}
	return tugowar;
}

int main()
{
	int myarray[18];
	int* a = myarray;
	int* b = myarray + 6;
	int* c = myarray + 12;
	bool flag;

	for (int i = 0; i < 18; i++)
		myarray[i] = 1;
	myarray[17] = 0;

	do
	{
		do
		{
			myarray[17]++;
			flag = false;
			for (int i = 17; i > 0; i--)
			{
				if (myarray[i] > SIDES)
				{
					if (myarray[i - 1] < SIDES)
						myarray[i] = myarray[i - 1];
					else
						myarray[i] = 1;
					myarray[i - 1]++;
				}
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (myarray[i * 6 + j] > myarray[i * 6 + j + 1])
						myarray[i * 6 + j + 1] = myarray[i * 6 + j];
				}
			}
			if (dicetie(a, b) || dicetie(b, c) || dicetie(a, c))
			{
				flag = true;
				continue;
			}
			if (wins(a, b) <= 0 || wins(b, c) <= 0 || wins(c, a) <= 0)
			{
				flag = true;
				continue;
			}
			if (wins(a, b) != wins(b, c) || wins(b,c) != wins(c, a))
			{
				flag = true;
				continue;
			}
			if (*b > *c || *c > *a)
			{
				flag = true;
				continue;
			}
		} while (flag && myarray[0] <= SIDES);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
				cout << myarray[i * 6 + j] << " ";
			cout << "    ";
		}
		cout << wins(a,b) << " " << wins(b,c) << " " << wins(c, a) << endl;
	} while (myarray[0] <= SIDES);
	system("pause");
	return 0;
}