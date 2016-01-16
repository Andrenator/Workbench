#include <iostream>
#include <string>
#include <fstream>
#define population 5163
using namespace std;

struct statsheet
{
	int letter[27];
	void initialize()
	{
		for (int counter = 0; counter < 27; counter++)
			letter[counter] = 0;
	}
	int total()
	{
		int result = 0;
		for (int counter = 0; counter < 27; counter++)
		{
			result += letter[counter];
		}
		return result;
	}
};

int main()
{
	ifstream myfile;
	string names[population];
	names[0] = "";
	statsheet probs[26];
	int counter = 0;
	myfile.open("..\\euler.txt");
	char c;
	bool flag;

	while (!myfile.eof())
	{
		myfile.get(c);
		if (c == '\"')
			continue;
		if (c == ',')
		{
			names[counter] += '\n';
			counter++;
			names[counter] = "";
			continue;
		}
		names[counter] += c;
	}

	for (int counter = 0; counter < 26; counter++)
		probs[counter].initialize();

	for (int y = 0; y < population; y++)
	{

	}

	/*do
	{
		flag = false;
		for (int i = 0; i < population - 1; i++)
		{
			if (names[i].compare(names[i + 1]) > 0)
			{
				names[i].swap(names[i + 1]);
				flag = true;
				if (i > 0)
				{
					i--;
					continue;
				}
				break;
			}
		}
	} while (flag);*/

	/*for (int i = 0; i < population; i++)
	{
		cout << names[i] << "\t";
	}*/

	myfile.close();
	return 0;
}