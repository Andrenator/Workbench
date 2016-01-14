#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct player
{
	string name;
	int score;
};

int nomain()
{
	vector<player> playerList;
	string name;
	int x;

	do
	{
		cout << "Please enter player number " << playerList.size() + 1<< ": ";
		cin >> name;
		if (name == "")
			break;
		cout << "And score: ";
		cin >> x;
		playerList[playerList.size()].name.push_back(name);
		playerList.resize(playerList.size() + 1);
		playerList[playerList.size()].name = name;
		playerList[playerList.size()].score = x;

	} while (x != -1);

	for (int counter = 0; counter < playerList.size(); counter++)
	{
		cout << "Player " << playerList[counter].name << " with a score of " << playerList[counter].score << endl;
	}

	return 0;
}