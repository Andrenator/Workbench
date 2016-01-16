#include <iostream>
#include <time.h>
#include <iomanip>
#define PLAYERS 100
using namespace std;

struct dice
{
	int sides[6], score;
	void initialize()
	{
		for (int i = 0; i < 6; i++)
		{
			sides[i] = rand() % 111 - 10;
		}
		if (!validate())
			initialize();
		sort();
		score = 0;
	}
	bool validate()
	{
		if (sides[0] + sides[1] + sides[2] + sides[3] + sides[4] + sides[5] != 60)
			return false;
		return true;
	}
	void display()
	{
		for (int i = 0; i < 6; i++)
			cout << setw(3) << sides[i];
	}
	void sort()
	{
		bool flag;
		int temp;
		do
		{
			flag = false;
			for (int i = 0; i < 5; i++)
			{
				if (sides[i] > sides[i + 1])
				{
					temp = sides[i];
					sides[i] = sides[i + 1];
					sides[i + 1] = temp;
					flag = true;
				}
			}
		} while (flag);
	}
};

int absoluteval(int x)
{
	if (x >= 0)
		return x;
	else
		return -x;
}
int battle(dice* a, dice* b)
{
	if (a->sides[0] == a->sides[5] && b->sides[0] == b->sides[0])
		return 1;
	int totala = 0, totalb = 0, result;
	while (totala < 100 && totalb < 100)
	{
		result = a->sides[rand() % 6] - b->sides[rand() % 6];
		if (result > 0)
			totala += absoluteval(result);
		else
			totalb += absoluteval(result);
	}
	if (totala > 100)
		return 1;
	else
		return 2;
}

int main()
{
	srand(time(NULL));
	dice players[PLAYERS];
	for (int i = 0; i < 100; i++)
	{
		players[i].initialize();
	}

	for (int i = 0; i < PLAYERS; i++)
	{
		cout << i / 10 << "% complete" << endl;
		for (int j = i + 1; j < PLAYERS; j++)
		{
			if (battle(players + i, players + j) == 1)
				(players + i)->score++;
			else
				(players + j)->score++;
		}
	}

	for (int i = 0; i < PLAYERS; i++)
	{
		if (players[i].score > 100)
		{
			cout << "dice " << i + 1 << ": " << players[i].score << " with ";
			players[i].display();
			cout << endl;
		}
	}

	system("pause");
	return 0;
}