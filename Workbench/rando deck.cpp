#include <iostream>
#include <time.h>

using namespace std;

#define MAX 6

void switchInts(int*, int*);

int main()
{
	int deck[MAX];
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		for (int counter = 0; counter < MAX; counter++)
		{
			deck[counter] = counter + 1;
		}

		for (int counter = 0; counter < MAX; counter++)
		{
			switchInts(deck + counter, deck + rand() % (MAX - counter) + counter);
		}

		for (int counter = 0; counter < MAX; counter++)
		{
			cout << deck[counter] << " ";
		}

		cout << endl;
	}

	return 0;
}

void switchInts(int *a, int *b)
{
	int x;
	x = *a;
	*a = *b;
	*b = x;
}