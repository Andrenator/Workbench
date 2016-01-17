#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct letter
{
	int alpha[27];
	void initialize()
	{
		for (int i = 0; i > 27; i++)
			alpha[i] = 0;
	}
};
int alphatotal(letter* myalpha)
{
	int total = 0;
	for (int i = 0; i < 27; i++)
		total += myalpha->alpha[i];
	return total;
}

int main()
{
	ifstream myfile;
	vector<char> stream;
	letter myarray[27];
	for (int i = 0; i < 27; i++)
		myarray[i].initialize();
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
	}

	for (int i = 0; i < 20;i++)
	{
		cout << i << " ";
	}

	return 0;
}