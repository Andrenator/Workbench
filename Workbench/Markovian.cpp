#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

struct letter
{
	int alpha[27];
};
int alphatotal(letter* myalpha)
{
	int total = 0;
	for (int i = 0; i < 27; i++)
		total += myalpha->alpha[i];
	return total;
}
char choosenext(letter* pointer)
{
	int i = rand() % alphatotal(pointer);
	for (int j = 0; j < 26; j++)
	{
		if (i < pointer->alpha[j])
			return j + 65;
		else
		{
			i -= pointer->alpha[j];
		}
	}
	return ' ';
}

int main()
{
	srand(time(NULL));
	ifstream myfile;
	vector<char> stream;
	letter myarray[27];
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 27; j++)
			myarray[i].alpha[j] = 0;
	}
	myfile.open("..//euler.txt");
	char c;

	while (!myfile.eof())
	{
		myfile.get(c);
		if (c >= 65 && c <= 90)
			stream.push_back(c);
		else if (stream.empty() || stream.back() != ' ')
			stream.push_back(' ');
	}

	for (int i = 0; i < stream.size(); i++)
	{
		if (i == 0)
		{
			myarray[26].alpha[(int)stream[i] - 65]++;
			continue;
		}
		if (stream[i - 1] == ' ')
			myarray[26].alpha[(int)stream[i] - 65]++;
		else if (stream[i - 1] >= 65 && stream[i - 1] <= 90)
			myarray[(int)stream[i - 1] - 65].alpha[(int)stream[i] - 65]++;
		else if (stream[i] == ' ')
			myarray[(int)stream[i - 1] - 65].alpha[26]++;
	}

	for (int i = 0; i < 27; i++)
		cout << myarray[26].alpha[i] << endl;

	for (int i = 0; i < 20;i++)
	{
		cout << choosenext(&myarray[26]) << " ";
	}

	return 0;
}