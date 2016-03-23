//Rules:
//	a beats b beats c beats a
//	no dice may tie with each other (self is ok)
#include <iostream>
#include <ctime>
<<<<<<< HEAD
#define SIDES 6
=======
#define SIDES 10
>>>>>>> origin/master
using namespace std;

bool scan(int* a, int b)
{
	bool c = false;
	for (int i = 0; i > 18; i++)
	{
		if (a[i] == b)
			c = true;
	}
	return c;
}
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
	float time = clock();

	for (int i = 0; i < 18; i++)
		myarray[i] = 1;
	myarray[17] = 0;

	do
	{
		do
		{
			loop:
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
			/*if (!scan(myarray, SIDES))
			{
				flag = true;
				continue;
			}*/
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
<<<<<<< HEAD
			if (wins(a, b) <= 6)
=======
			if (wins(a, b) <= 4 || wins(b, c) <= 0 || wins(c, a) <= 0)
>>>>>>> origin/master
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
<<<<<<< HEAD
	cout << (clock() - time) / CLOCKS_PER_SEC << endl;
=======
	cout << (clock() - time) / (CLOCKS_PER_SEC) << endl;
>>>>>>> origin/master
	system("pause");
	return 0;
}