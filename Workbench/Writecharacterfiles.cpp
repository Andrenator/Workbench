// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;
string randomname();
bool isconsonant(char);
int statroll();
string consonants[] = { "st", "r", "f", "t", "m", "dr", "h", "g", "d"};
string vowels[] = { "a", "e", "i", "o", "u" };

int main() {
	srand(time(NULL));
	ofstream myfile;

	string name;

	for (int i = 0; i < 100; i++)
	{
		name = randomname();
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

string randomname()
{
	string s = "";
	char temp;
	int counter = 1;

	s += rand() % 26 + 97;

	for (counter; counter <= rand() % 6 + 3; counter++)
	{
		do {
			temp = rand() % 26 + 97;
		} while (isconsonant(temp) == isconsonant(s[counter - 1]));
		s += temp;
	}


	s[0] -= (97 - 65);

	return s;
}

bool isconsonant(char a)
{
	switch (a)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return false;
			break;
		default:
			return true;
	}

	cout << "error in isconsonant";
}

int statroll()
{
	int a, b, c;
	a = rand() % 6;
	b = rand() % 6;
	c = rand() % 6;

	return a + b + c + 3;
}