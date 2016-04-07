#include <iostream>
#include <time.h>
#define DICE 3
using namespace std;

struct stoat
{
	int dice[3];
	int total()
	{
		return dice[0] + dice[1] + dice[2];
	}
};
void rollstat(struct stoat*);
void swapints(int*, int*);
int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	srand(time(NULL));
	struct stoat rollem[3];
	for (int i = 0; i < 2; i++)
	{
		rollstat(rollem + i);
		for (int j = 0; j < 3; j++)
			cout << rollem[i].dice[j] << " ";
		cout << "\ttotal: " << rollem[i].total();
		cout << endl;
	}

	cout << "now kith" << endl;
	for (int i = 0; i < 3; i++)
	{
		switch (rand() % 3)
		{
			case 0:
				rollem[3].dice[i] = min(rollem[0].dice[i], rollem[1].dice[i]);
				break;
			case 1:
				rollem[3].dice[i] = (rollem[0].dice[i] + rollem[1].dice[i]) / 2;
				break;
			case 2:
				rollem[3].dice[i] = rollem[0].dice[i] + rollem[1].dice[i] - min(rollem[0].dice[i], rollem[1].dice[i]);
		}
	}
	for (int j = 0; j < 3; j++)
	{
		rollem[3].dice[j] += rand() % 3 - 1;
		cout << rollem[3].dice[j] << " ";
	}
	cout << "\ttotal: " << rollem[3].total();
	cout << endl;

	return 0;
}

void rollstat(struct stoat* myarray)
{
	int stats[4] = { 0 };
	for (int i = 0; i < DICE; i++)
		stats[i] = rand() % 6 + 1;
	for (int i = 0; i < 3; i++)
	{
		if (stats[i] < stats[i+1])
		{
			swapints(stats + i, stats + i + 1);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		swapints(stats + i, stats + i + rand() % (3 - i));
	}
	for (int i = 0; i < 3; i++)
		myarray->dice[i] = stats[i];
}

void swapints(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}