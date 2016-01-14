#include <iostream>
#include <string>
#include <fstream>
#define population 5163
using namespace std;

int main()
{
	ifstream myfile;
	string names[population];
	names[0] = "";
	int counter = 0;
	myfile.open("H:\\euler.txt");
	char c;
	bool flag;
	long long int result = 0;

	while (!myfile.eof())
	{
		myfile.get(c);
		if (c == '\"')
			continue;
		if (c == ',')
		{
			counter++;
			names[counter] = "";
			continue;
		}
		names[counter] += c;
	}

	do
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
	} while (flag);

	for (int i = 0; i < population; i++)
	{
		counter = 0;
		for (int counter2 = 0; names[i][counter2] != '\0'; counter2++)
		{ 
			counter += names[i][counter2] - 64;
		}
		result += counter * (i + 1);
	}

	cout << result;

	for (int i = 0; i < population; i++)
	{
		cout << names[i] << "\t";
	}

	myfile.close();
	return 0;
}