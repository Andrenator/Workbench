#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;

vector<string> consonants = { "st", "r", "w", "d", "h", "th", "fr", "p", "v", "t", "dr", "f", "m", "g" };
vector<string> vowels = { "a", "e", "i", "o", "u", "or" };

string randname();
int statroll();
int min(int, int, int, int, int);
int max(int, int, int, int, int);

int main()
{
	srand(time(NULL));
	ofstream myfile;
	string name;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << statroll() << "\t";
		cout << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		name = randname();
		myfile.open("H:\\Workbench\\workbench\\example\\" + name + ".txt");

		myfile << "Name: " << name << endl;
		myfile << "Str: " << statroll() << endl;
		myfile << "Dex: " << statroll() << endl;
		myfile << "Con: " << statroll() << endl;
		myfile << "Int: " << statroll() << endl;
		myfile << "Wis: " << statroll() << endl;
		myfile << "Cha: " << statroll() << endl;

		myfile.close();
	}

	return 0;
}

string randname()
{
	string name = "";
	bool needavowel;
	if (rand() % 3 == 0)
		needavowel = true;
	else
		needavowel = false;

	for (int i = 0; needavowel == true || i < rand() % 3 + 3; i++)
	{
		if (needavowel)
		{
			name += vowels.at(rand() % vowels.size());
			needavowel = false;
		}
		else
		{
			name += consonants.at(rand() % consonants.size());
			needavowel = true;
		}
	}

	name[0] -= 32;

	return name;
}

int statroll()
{
	int a, b, c, d, e;
	a = rand() % 6;
	b = rand() % 6;
	c = rand() % 6;
	d = rand() % 6;
	e = rand() % 6;

	return a + b + c + d + e - min(a,b,c,d,e) - max(a,b,c,d,e)+ 3;
}

int min(int a, int b, int c, int d, int e)
{
	int least = a;
	if (least > b)
		least = b;
	if (least > c)
		least = c;
	if (least > d)
		least = d;
	if (least > e)
		least = e;

	return least;
}

int max(int a, int b, int c, int d, int e)
{
	int most = a;
	if (most < b)
		most = b;
	if (most < c)
		most = c;
	if (most < d)
		most = d;
	if (most < e)
		most = e;

	return most;
}