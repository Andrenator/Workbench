#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
#define LOOPS 100000

int rollstat();
int explode();
void sortstats(int*);

int main()
{
	srand(time(NULL));
	float mean = 0, stddev = 0, oldmean = 0;
	int stats[6];
	float typical[6] = { 0 };

	for (int i = 0; i < LOOPS; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			stats[j] = rollstat();
			mean = oldmean + (stats[j] - oldmean) / (i + 1);
			stddev = stddev + (stats[j] - oldmean)*(stats[j] - mean);
			oldmean = mean;
		}
		sortstats(stats);
		for (int j = 0; j < 6; j++)
			typical[j] += (float)stats[j] / LOOPS;
		cout << endl;
	}

	for (int i = 0; i < 6; i++)
		cout << typical[i] << " ";
	cout << endl << "mean: " << mean << endl;
	cout << "standard deviation: " << pow(stddev/(LOOPS*6 - 1), .5);

	return 0;
}

int rollstat()
{
	return explode() + explode() + explode();
}

int explode()
{
	int total = rand()%6 + 1;
	while (total % 6 == 0)
	{
		total += rand() % 6 + 1;
	}
	return total;
}

void sortstats(int*myarray)
{
	bool flag;
	int temp;

	do
	{
		flag = false;
		for (int i = 0; i < 5; i++)
		{
			if (myarray[i] < myarray[i + 1])
			{
				temp = myarray[i];
				myarray[i] = myarray[i + 1];
				myarray[i + 1] = temp;
				flag = true;
			}
		}
	} while (flag);
}