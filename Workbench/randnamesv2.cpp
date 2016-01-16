#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

string randname();
vector <string> labial = { "p", "b", "m", "f" };
vector <string> dental = { "t", "d", "th" };
vector <string> alveolar = { "sh", "n", "s", "z", "ch" };
vector <string> palatal = { "er", "a", "e", "i", "o", "u" };
vector <string> pharyngeal = { "g", "h", "k" };

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		cout << randname() << endl;
	}

	return 0;
}

string randname()
{
	string name = "";
	int next = rand() % 5;

	for (int i = 0; i < rand() % 3 + 3; i++)
	{
		switch (next)
		{
			case 0:
				name += labial.at(rand() % labial.size());
				next = 3;
				break;
			case 1:
				name += dental.at(rand() % dental.size());
				next = 3;
				break;
			case 2:
				name += alveolar.at(rand() % alveolar.size());
				next = (rand() % 2) * 2 + 1;
				break;
			case 3:
				name += palatal.at(rand() % palatal.size());
				next = rand() % 5;
				break;
			case 4:
				name += pharyngeal.at(rand() % pharyngeal.size());
				next = 3;
				break;
			default:
				cout << "error";
		}
	}

	name[0] -= 32;
	return name;
}