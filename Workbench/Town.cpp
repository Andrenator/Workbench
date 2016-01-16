#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
#define census 200

struct person
{
	string name;
	int stats[6];
	string job;
};
vector<string> consonants = { "ch", "t", "p", "h", "k" };
vector<string> vowels = {"a", "e", "i", "o", "u"};
string randname();
int statroll();

int main()
{
	person population[census];
	vector<int> normalizer;
	bool flag;
	person extra;

	for (int i = 0; i < census; i++)
	{
		population[i].name = randname();
		for (int counter = 0; counter < 6; counter++)
		{
			normalizer.clear();
			for (int counter2 = 0; counter2 < 3; counter2++)
				normalizer.push_back(statroll());
			sort(normalizer.begin(), normalizer.end());
			population[i].stats[counter] = normalizer[1];
		}
	}

	do
	{
		flag = false;
		for (int i = 0; i < census - 1; i++)
		{
			if (population[i].stats[0] + population[i].stats[1] + population[i].stats[2]
				+ population[i].stats[3] + population[i].stats[4] + population[i].stats[5] <
				population[i + 1].stats[0] + population[i + 1].stats[1] + population[i + 1].stats[2]
				+ population[i + 1].stats[3] + population[i + 1].stats[4] + population[i + 1].stats[5])
			{
				extra.name = population[i].name;
				population[i].name = population[i + 1].name;
				population[i + 1].name = extra.name;
				for (int counter = 0; counter < 6; counter++)
				{
					extra.stats[counter] = population[i].stats[counter];
					population[i].stats[counter] = population[i + 1].stats[counter];
					population[i + 1].stats[counter] = extra.stats[counter];
				}
				flag = true;
				break;
			}
		}

	} while (flag);

	for (int i = 0; i < census; i++)
	{
		cout << population[i].name;
		cout << "\tStr: " << population[i].stats[0];
		cout << "\tCon: " << population[i].stats[1];
		cout << "\tDex: " << population[i].stats[2];
		cout << "\tInt: " << population[i].stats[3];
		cout << "\tWis: " << population[i].stats[4];
		cout << "\tCha: " << population[i].stats[5];
		cout << endl;
	}

	return 0;
}

string randname()
{
	string result = "";
	bool needvowel;
	if (rand() % 3 == 0)
		needvowel = true;
	else
		needvowel = false;
	for (int i = 0; i < rand() % 3 + 3; i++)
	{
		if (needvowel)
		{
			result += vowels.at(rand() % vowels.size());
			needvowel = false;
		}
		else
		{
			result += consonants.at(rand() % vowels.size());
			needvowel = true;
		}
	}

	result[0] -= 32;
	return result;
}

int statroll()
{
	vector<int> rolls(3);
	for (int i = 0; i < rolls.size(); i++)
		rolls[i] = rand() % 6 + 1;
	sort(rolls.begin(), rolls.end());
	return rolls[0] + rolls[1] + rolls[2];
}