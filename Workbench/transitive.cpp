#include <iostream>
#include <time.h>
#define DICE 6
using namespace std;

void switchnums(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void sortdie(int* myarray)
{
	bool flag;
	do
	{
		flag = false;
		for (int i = 0; i < 5; i++)
		{
			if (myarray[i] > myarray[i + 1])
			{
				switchnums(myarray + i, myarray + i + 1);
				flag = true;
			}
		}
	} while (flag);
}

int main()
{
	srand(time(NULL));
	int sides[DICE * 3];
	int die[6];
	for (int i = 0; i < DICE * 3; i++)
		sides[i] = i + 1;
	for (int i = 0; i < DICE * 3; i++)
		switchnums(&(sides[i]), &(sides[i + rand() % (DICE * 3 - i)]));
	for (int i = 0; i < DICE; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			die[j] = sides[i * 3 + j];
			die[5 - j] = DICE * 6 - sides[i * 3 + j] + 1;
		}
		sortdie(die);
		for (int j = 0; j < 6; j++)
			cout << die[j] << " ";
		cout << endl;
	}

	return 0;
}