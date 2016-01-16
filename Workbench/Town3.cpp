#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;
#define population 20

struct person
{
	string name;
	int stats[6][3];
	string job;

public:
	int stat(int x)	{
		return stats[x][0] + stats[x][1] + stats[x][2];
	}
	int total() {
		return stat(0) + stat(1) + stat(2) + stat(3) + stat(4) + stat(5);
	}
};

void outputperson(person*);
int coinflip(int, int);

int main()
{
	srand(time(NULL));
	person ppl[population];
	person temp;

	for (int i = 0; i < population; i++)
	{
		ppl[i].name = to_string(i);
		for (int counter = 0; counter < 6; counter++)
		{
			for (int counter2 = 0; counter2 < 3; counter2++)
				ppl[i].stats[counter][counter2] = rand() % 6 + 1;
		}
		ppl[i].job = "";
	}

	outputperson(ppl);
	cout << "had a baby with" << endl;
	outputperson(ppl + 1);
	cout << "and the baby was" << endl;
	temp.name = "B";
	for (int i = 0; i < 6; i++)
	{
		for (int counter = 0; counter < 3; counter++)
			temp.stats[i][counter] = coinflip(ppl[0].stats[i][counter], ppl[1].stats[i][counter]);
	}
	outputperson(&temp);

	return 0;
}

int coinflip(int a, int b)
{
	if (rand() % 2 == 0)
		return a;
	else
		return b;
}

void outputperson(person* guy)
{
	cout << guy->name << "\t";
	for (int counter = 0; counter < 6; counter++)
	{
		cout << "(";
		for (int counter2 = 0; counter2 < 3; counter2++)
			cout << guy->stats[counter][counter2] << " ";
		cout << (char)8 << ")";
		cout << guy->stat(counter) << " ";
	}
	cout << endl;
}