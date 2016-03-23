#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <math.h>
#define LOOPS 100000
#define DICE 2
#define SIDES 20
#define IGNORE 0
using namespace std;

int rollstat();
void reverse(int*, int);
void swapint(int*, int*);
int main()
{
	float avg = 0, newavg = 0, variance = 0, averages[6] = { 0 };
	vector<int> stats(6);
	srand(time(NULL));
	for (int i = 0; i < LOOPS; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			stats[j] = rollstat();
			newavg += (stats[j] - avg)/(i*6+j+1);
			variance += (stats[j] - avg)*(stats[j] - newavg);
			//cout << stats[j] << "\t" << avg << "\t" << newavg << "\t" << variance << endl;
			avg = newavg;
		}
		sort(stats.begin(), stats.end());
		reverse(&stats[0], 6);
		for (int j = 0; j < 6; j++)
			averages[j] += (float)stats[j] / LOOPS;
	}

	for (int i = 0; i < 6; i++)
		cout << averages[i] << " ";
	cout << endl << "average: " << avg;
	cout << endl << "stddev:  " << sqrt(variance / (6*(LOOPS - 1)));

	return 0;
}

int rollstat()
{
	vector <int> rolls;
	int total = 0;
	for (int i = 0; i < DICE; i++)
		rolls.push_back(rand() % SIDES + 1);
	sort(rolls.begin(), rolls.end());
	reverse(&rolls[0], DICE);
	if (SIDES == 6)
	{
		for (int i = IGNORE; i < IGNORE + 3; i++)
			total += rolls[i];
	}
	else if (SIDES == 20)
	{
		return rolls[IGNORE];
	}
	return total;
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