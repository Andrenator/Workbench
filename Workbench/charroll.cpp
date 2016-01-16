#include <iostream>
#include <time.h>
using namespace std;

int rollstat();
float avg(int*, int);
float absval(float);
float stddev(int*, int);
bool comparefloats(float, float);

int main()
{
	srand(time(NULL));
	int stat[6];

	do
	{
		cout << "try ";
		for (int i = 0; i < 6; i++)
		{
			stat[i] = rollstat();
		}
	} while (stddev(stat, 6) < 2.5 || !comparefloats(avg(stat, 6), 10.5));
	cout << endl;
	cout << "str: " << stat[0] << endl;
	cout << "dex: " << stat[1] << endl;
	cout << "con: " << stat[2] << endl;
	cout << "int: " << stat[3] << endl;
	cout << "wis: " << stat[4] << endl;
	cout << "cha: " << stat[5] << endl;
	cout << "standard deviation: " << stddev(stat, 6) << endl;

	system("pause");
	return 0;
}

int rollstat()
{
	int dice[4];
	int low = 6;
	for (int i = 0; i < 4; i++)
	{
		dice[i] = rand() % 6 + 1;
		if (dice[i] < low)
			low = dice[i];
	}

	return dice[0] + dice[1] + dice[2] + dice[3] - low;
}

float avg(int * mypointer, int elements)
{
	float total = 0;
	for (int i = 0; i < elements; i++)
		total += mypointer[i];
	return total / elements;
}

float absval(float x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

float stddev(int *mypointer, int elements)
{
	float total = 0;
	for (int i = 0; i < elements; i++)
		total += absval((float)mypointer[i] - avg(mypointer, elements));
	return total / elements;
}

bool comparefloats(float a, float b)
{
	if (a - b < .0001 && b - a < .0001)
		return true;
	else
		return false;
}