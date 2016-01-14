#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int letterlength(string);

int main()
{
	unsigned long long int num = 0;
	int a, b, c, d;
	string str;

	for (int i = 1; i <= 1000; i++)
	{
		a = i / 1000;
		b = i / 100 % 10;
		c = i / 10 % 10;
		d = i % 10;
		
		str = "";

		if (a == 1)
			str = "one thousand";
		else
		{
			switch (b)
			{
				case 9:
					str += "nine";
					break;
				case 8:
					str += "eight";
					break;
				case 7:
					str += "seven";
					break;
				case 6:
					str += "six";
					break;
				case 5:
					str += "five";
					break;
				case 4:
					str += "four";
					break;
				case 3:
					str += "three";
					break;
				case 2:
					str += "two";
					break;
				case 1:
					str += "one";
					break;
				case 0:
				default:
					break;
			}

			if (b > 0)
				str += " hundred";
			if (c + d > 0 && a + b > 0)
				str += " and ";
			
			switch (c)
			{
				case 9:
					str += "ninety";
					break;
				case 8:
					str += "eighty";
					break;
				case 7:
					str += "seventy";
					break;
				case 6:
					str += "sixty";
					break;
				case 5:
					str += "fifty";
					break;
				case 4:
					str += "forty";
					break;
				case 3:
					str += "thirty";
					break;
				case 2:
					str += "twenty";
					break;
				default:
					break;
			}

			if (c > 1 && d > 0)
				str += "-";

			if (c == 1)
			{
				d += 10;
				c = 0;
			}

			switch (d)
			{
				case 19:
					str += "nineteen";
					break;
				case 18:
					str += "eighteen";
					break;
				case 17:
					str += "seventeen";
					break;
				case 16:
					str += "sixteen";
					break;
				case 15:
					str += "fifteen";
					break;
				case 14:
					str += "fourteen";
					break;
				case 13:
					str += "thirteen";
					break;
				case 12:
					str += "twelve";
					break;
				case 11:
					str += "eleven";
					break;
				case 10:
					str += "ten";
					break;
				case 9:
					str += "nine";
					break;
				case 8:
					str += "eight";
					break;
				case 7:
					str += "seven";
					break;
				case 6:
					str += "six";
					break;
				case 5:
					str += "five";
					break;
				case 4:
					str += "four";
					break;
				case 3:
					str += "three";
					break;
				case 2:
					str += "two";
					break;
				case 1:
					str += "one";
					break;
				default:
					break;
			}
			
		}

		cout << i << " is " <<  str << " and total is " << letterlength(str) << endl;
		num += letterlength(str);
	}

	cout << endl << "total is " << num << endl;

	return 0;
}

int letterlength(string mystring)
{
	int total = 0;

	for (int i = 0; i < mystring.length(); i++)
	{
		if (mystring[i] != ' ' && mystring[i] != '-')
			total++;
	}

	return total;
}