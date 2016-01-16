#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string>
using namespace std;

bool enterstats = true;

struct archetype
{
	string name;
	int weights[6];
	void initialize (string title, int str, int dex, int con, int intelligence, int wis, int charisma)
	{
		name = title;
		weights[0] = str;
		weights[1] = dex;
		weights[2] = con;
		weights[3] = intelligence;
		weights[4] = wis;
		weights[5] = charisma;
	}
	int total(int* myarray)
	{
		int total = 0;
		for (int i = 0; i < 6; i++)
		{
			total += weights[i] * myarray[i];
		}
		return total;
	}
};
int statroll()
{
	vector<int> stats(4);
	for (int i = 0; i < 4; i++)
	{
		stats[i] = rand() % 6 + 1;
	}
	
	sort (stats.begin(), stats.end());
	return stats[1] + stats[2] + stats[3];
}
string statrate(int x)
{
	if (x < 60)
		return "*";
	else if (x < 65)
		return "**";
	else if (x < 70)
		return "***";
	else if (x < 75)
		return "*****";
	else if (x < 80)
		return "******";
	else if (x < 85)
		return "*******";
	else if (x < 90)
		return "********";
	else if (x < 95)
		return "*********";
	else
		return "**********";
		
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

int main()
{
	srand(time(NULL));
	int stat[6];
	bool flag;
	int total = 0;
	archetype classes[12];

	classes[0].initialize("barbarian ", 4, 0, 1, 0, 1, 0);
	classes[1].initialize("bard      ", 0, 2, 0, 1, 0, 3);
	classes[2].initialize("cleric    ", 1, 0, 1, 0, 4, 0);
	classes[3].initialize("druid     ", 0, 0, 2, 0, 4, 0);
	classes[4].initialize("fighter   ", 3, 1, 1, 1, 0, 0);
	classes[5].initialize("monk      ", 0, 3, 1, 0, 2, 0);
	classes[6].initialize("paladin   ", 3, 0, 1, 0, 0, 2);
	classes[7].initialize("ranger    ", 1, 3, 0, 0, 2, 0);
	classes[8].initialize("rogue     ", 0, 4, 0, 2, 0, 0);
	classes[9].initialize("sorcerer  ", 0, 0, 2, 0, 0, 4);
	classes[10].initialize("warlock   ", 0, 0, 1, 1, 0, 4);
	classes[11].initialize("wizard    ", 0, 0, 2, 4, 0, 0);

	if (enterstats == false)
	{
		do
		{
			for (int i = 0; i < 6; i++)
			{
				stat[i] = statroll();
			}
		} while (stddev(stat, 6) < 2.5 || !comparefloats(avg(stat, 6), 10.5));

		cout << "Strength:     " << stat[0] << endl;
		cout << "Dexterity:    " << stat[1] << endl;
		cout << "Constitution: " << stat[2] << endl;
		cout << "Intelligence: " << stat[3] << endl;
		cout << "Wisdom:       " << stat[4] << endl;
		cout << "Charisma:     " << stat[5] << endl;
	}
	else
	{
		cout << "Strength:     ";
		cin >> stat[0];
		cout << "Dexterity:    ";
		cin >> stat[1];
		cout << "Constitution: ";
		cin >> stat[2];
		cout << "Intelligence: ";
		cin >> stat[3];
		cout << "Wisdom:       ";
		cin >> stat[4];
		cout << "Charisma:     ";
		cin >> stat[5];
	}
	cout << endl << "average: " << avg(stat, 6) << endl;
	cout << "standard deviation: " << stddev(stat, 6) << endl << endl;

	for (int i = 0; i < 12; i++)
		cout << classes[i].name << classes[i].total(stat) << "\t" << statrate(classes[i].total(stat)) << endl;

	for (int i = 0; i < 6; i++)
		total += stat[i];
	cout << endl << "overall\t" << total << "\t" << statrate(total) << endl << endl;

	system("pause");
	return 0;
}