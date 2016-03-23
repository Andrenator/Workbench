#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#define LOOPS 10000
#define DICE 3
using namespace std;

int rollstat();
void reverse(int*, int);
void swapint(int*, int*);

int main()
{
	float avg = 0, averages[6] = { 0 };
	vector<int> stats (6);
	srand(time(NULL));
	for (int i = 0; i < LOOPS; i++)
	{
		for (int j = 0; j < 6; j++)
			stats[j] = rollstat();
		sort(stats.begin(), stats.end());
		reverse(&stats[0], 6);
		avg += (float)(stats[0] + stats[1] + stats[2] + stats[3] + stats[4] + stats[5])/6 / LOOPS;
	}

	cout << "average: " << avg;

	return 0;
}

int rollstat()
{
	vector <int> rolls;
	for (int i = 0; i < DICE; i++)
		rolls.push_back(rand() % 6 + 1);
	sort(rolls.begin(), rolls.end());
	reverse(&rolls[0], DICE);
	return rolls[0] + rolls[1] + rolls[2];
}

void reverse(int* a, int b)
{
	for (int i = 0; 2 * i < b; i++)
		swapint(a + i, a + b - i - 1);
}

void swapint(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}