#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#define census 250

struct person
{
	string name;
	int stats[6];
	string job;

	public:
		float avg() { return (float)(stats[0] + stats[1] + stats[2] + stats[3] + stats[4] + stats[5]) / 6; }
		float stddev()
			{
				float result = 0;
				for (int i = 0; i < 6; i++)
					result += abs((float)stats[i] - avg());
				return result / 6;
			}
};
int rollstat();
int test(int, int);

int main()
{
	srand(time(NULL));
	vector <person> population(census);
	int temp;

	for (int counter = 0; counter < census; counter++)
	{
		population[counter].name = to_string(counter);
		for (int i = 0; i < 6; i++)
		{
			population[counter].stats[i] = rollstat();
		}
		population[counter].job = "";
	}
	
	temp = 0; 
	i = 0;
	do
	{
		if (test(population[i].stats[5], 4) + test(population[i].stats[4], 2) + test(population[i].stats[3], 2) > temp)
		{
			population[i].job = "candidate";
			temp = test(population[i].stats[5], 4) + test(population[i].stats[4], 2) + test(population[i].stats[3], 2);
			i = 0;
		}
		else
		{
			population[i].job = "";
			i++;
		}
	} while (i < census);

	for (int i = 0; i < census; i++)
	{
		cout << population[i].name << ":\t";
		for (int counter = 0; counter < 6; counter++)
			cout << setw(3) << population[i].stats[counter] ;
		cout << "\t" << population[i].job << endl;
	}

	return 0;
}

int rollstat()
{
	int a, b, c;
	a = rand() % 6 + 1;
	b = rand() % 6 + 1;
	c = rand() % 6 + 1;

	return a + b + c;
}

int test(int stat, int weight)
{
	return stat*weight;
}