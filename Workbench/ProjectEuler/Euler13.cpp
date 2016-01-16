#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	unsigned long long int num = 0;
	string buffer;
	fstream myfile;
	myfile.open("C:\\users\\andre\\desktop\\hooah.txt");

	while (!myfile.eof())
	{
		getline(myfile, buffer);
		for (int i = 0; i < 12; i++)
		{
			num += ((int)buffer[i] - '0')*(pow(10, 11 - i));
		}
	}

	cout << "hi i guess this worked " << num << endl;

	myfile.close();
	return 0;
}