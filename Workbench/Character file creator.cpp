#include <iostream>
#include <string>
#include <time.h>

using namespace std;

string randoName();


int main()
{	
	srand(time(NULL));
	string firstName = randoName();
	string lastName = randoName();
	
	cout << firstName << " " << lastName << ":" << endl;
	cout << "Strength:     " << rand() % 6 + rand() % 6 + rand() % 6 + 3 << endl;
	cout << "Dexterity:    " << rand() % 6 + rand() % 6 + rand() % 6 + 3 << endl;
	cout << "Constitution: " << rand() % 6 + rand() % 6 + rand() % 6 + 3 << endl;
	cout << "Intelligence: " << rand() % 6 + rand() % 6 + rand() % 6 + 3 << endl;
	cout << "Wisdom:       " << rand() % 6 + rand() % 6 + rand() % 6 + 3 << endl;
	cout << "Charisma:     " << rand() % 6 + rand() % 6 + rand() % 6 + 3 << endl;

	return 0;
}

string randoName()
{
	string s = "";
	int counter = 0;

	while (rand() % 9 + 3 >= counter)
	{
		s += (char)(rand() % 26 + 97);
		counter++;
	}

	return s;
}