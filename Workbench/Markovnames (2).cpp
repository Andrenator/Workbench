#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
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
	int choosenext()
	{
		int j = rand() % (total() + 1);
		for (int i = 0; i < 27; i++)
		{
			if (j < letter[i])
				return i;
			j -= letter[i];
			i++;
		}
	}
};

int main()
{
	ifstream myfile;
	string names[population];
	names[0] = "";
	struct statsheet probs[26];
	int counter = 0;
	myfile.open("C:\\\\Users\\Andre\\Desktop\\euler.txt");
	char a, b, c;
	bool flag;
	struct statsheet starter;
	starter.initialize();

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
	names[counter] += '\n';

	for (int counter = 0; counter < 26; counter++)
		probs[counter].initialize();

	for (int y = 0; y < population; y++)
	{
		starter.letter[y]++;
		for (int counter = 0;; counter++)
		{
			a = names[y][counter];
			b = names[y][counter + 1];
			if (b == '\n')
			{
				probs[int(a) - 65].letter[26]++;
				break;
			}
			probs[int(a) - 65].letter[int(b) - 65]++;

		}
	}

	for (int i = 0; i < 27; i++)
		cout << "start to " << char(i + 65) << ": " << starter.letter[i] << endl;

	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		a = starter.choosenext() + 65;
		do
		{
			cout << a;
			if (probs[(int)a - 65].choosenext() == 26)
				a = '\n';
			else
				a = probs[(int)a - 65].choosenext() + 65;
		} while (a != '\n');
		
		cout << endl;
	}


	myfile.close();
	return 0;
}