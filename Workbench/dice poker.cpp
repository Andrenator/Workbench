#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
#define DICENUM 6
#define TOTALCOMBOS pow(6,DICENUM)

struct numstring
{
	int value;
	string text;
	void input(int a, string b)
	{
		value = a;
		text = b;
	}
};
void sortdice(int* myarray, int length)
{
	int a;
	for (int i = 0; i < length; i++)
	{
		if (myarray[i] < myarray[i + 1])
		{
			a = myarray[i];
			myarray[i] = myarray[i + 1];
			myarray[i + 1] = a;
			i= i - 2;
			if (i < -1)
				i = -1;
		}
	}
};

int main()
{
	vector<numstring> mylist;
	numstring temp;
	int sixstraight = 0;
	int fivestraight = 0;
	int fourstraight = 0;
	int threestraight = 0;
	int twostraight = 0;

	int nomatches = 0;

	int sixofkind = 0;
	int fiveofkind = 0;
	int fourofkind = 0;
	int threeofkind = 0;
	int twoofkind = 0;

	int sixofkindex = 0;
	int fiveofkindex = 0;
	int fourofkindex = 0;
	int threeofkindex = 0;
	int twoofkindex = 0;

	int fivetwo = 0;
	int fivetwoflush = 0;
	int fourthree = 0;
	int fourthreeflush = 0;
	int fourtwo = 0;
	int fourtwoflush = 0;
	int threethree = 0;
	int threethreeflush = 0;
	int threetwotwo = 0;
	int threetwotwoflush = 0;
	int threetwo = 0;
	int threetwoflush = 0;
	int twotwotwo = 0;
	int twotwotwoflush = 0;
	int twotwo = 0;
	int twotwoflush = 0;

	int dice[DICENUM];
	for (int i = 0; i < DICENUM; i++)
		dice[i] = 1;

	int histogram[6];
	int histogramsorted[6];

	do {
		/*for (int i = 0; i < DICENUM; i++)
			cout << dice[i] << " ";
		cout << endl;*/

		for (int i = 0; i < 6; i++)
			histogram[i] = 0;
		for (int i = 0; i < DICENUM; i++)
			histogram[dice[i] - 1]++;
		for (int i = 0; i < 6; i++)
			histogramsorted[i] = histogram[i];

		if (histogram[0] * histogram[1] * histogram[2]
			* histogram[3] * histogram[4] * histogram[5] > 0)
			sixstraight++;
		for (int i = 0; i <= 6 - 5; i++)
		{
			if (histogram[i] * histogram[i + 1] * histogram[i + 2]
				* histogram[i + 3] * histogram[i + 4] > 0)
			{
				fivestraight++;
				break;
			}
		}
		for (int i = 0; i <= 6 - 4; i++)
		{
			if (histogram[i] * histogram[i + 1] * histogram[i + 2]
				* histogram[i + 3] > 0)
			{
				fourstraight++;
				break;
			}
		}
		for (int i = 0; i <= 6 - 3; i++)
		{
			if (histogram[i] * histogram[i + 1] * histogram[i + 2] > 0)
			{
				threestraight++;
				break;
			}
		}
		for (int i = 0; i <= 6 - 2; i++)
		{
			if (histogram[i] * histogram[i + 1] > 0)
			{
				twostraight++;
				break;
			}
		}
		
		sortdice(histogramsorted, 6);

		if (histogramsorted[0] == 1)
			nomatches++;

		if (histogramsorted[0] >= 6)
			sixofkind++;
		if (histogramsorted[0] >= 5)
			fiveofkind++;
		if (histogramsorted[0] >= 4)
			fourofkind++;
		if (histogramsorted[0] >= 3)
			threeofkind++;
		if (histogramsorted[0] >= 2)
			twoofkind++;
		
		if (histogramsorted[0] >= 6 && histogramsorted[1] == 1)
			sixofkindex++;
		if (histogramsorted[0] >= 5 && histogramsorted[1] == 1)
			fiveofkindex++;
		if (histogramsorted[0] >= 4 && histogramsorted[1] == 1)
			fourofkindex++;
		if (histogramsorted[0] >= 3 && histogramsorted[1] == 1)
			threeofkindex++;
		if (histogramsorted[0] >= 2 && histogramsorted[1] == 1)
			twoofkindex++;

		if (histogramsorted[0] == 5 && histogramsorted[1] == 2)
		{
			fivetwo++;
			if ((histogram[0] <= 1 && histogram[2] <= 1 && histogram[4] <= 1)
				|| (histogram[1] <= 1 && histogram[3] <= 1 && histogram[5] <= 1))
				fivetwoflush++;
		}
		if (histogramsorted[0] == 4 && histogramsorted[1] == 3)
		{
			fourthree++;
			if ((histogram[0] <= 1 && histogram[2] <= 1 && histogram[4] <= 1)
				|| (histogram[1] <= 1 && histogram[3] <= 1 && histogram[5] <= 1))
				fourthreeflush++;
		}
		if (histogramsorted[0] == 4 && histogramsorted[1] == 2)
		{
			fourtwo++;
			if ((histogram[0] <= 1 && histogram[2] <= 1 && histogram[4] <= 1)
				|| (histogram[1] <= 1 && histogram[3] <= 1 && histogram[5] <= 1))
				fourtwoflush++;
		}
		if (histogramsorted[0] == 3 && histogramsorted[1] == 3)
		{
			threethree++;
			if ((histogram[0] <= 1 && histogram[2] <= 1 && histogram[4] <= 1)
				|| (histogram[1] <= 1 && histogram[3] <= 1 && histogram[5] <= 1))
				threethreeflush++;
		}
		if (histogramsorted[0] == 3 && histogramsorted[1] == 2 && histogramsorted[2] == 2)
		{
			threetwotwo++;
			if ((histogram[0] <= 1 && histogram[2] <= 1 && histogram[4] <= 1)
				|| (histogram[1] <= 1 && histogram[3] <= 1 && histogram[5] <= 1))
				threetwotwoflush++;
		}
		if (histogramsorted[0] == 3 && histogramsorted[1] == 2)
		{
			threetwo++;
			if ((histogram[0] <= 1 && histogram[2] <= 1 && histogram[4] <= 1)
				|| (histogram[1] <= 1 && histogram[3] <= 1 && histogram[5] <= 1))  
				threetwoflush++;
		}
		if (histogramsorted[0] == 2 && histogramsorted[1] == 2 && histogramsorted[2] == 2)
		{
			twotwotwo++;
			if ((histogram[0] <= 1 && histogram[2] <= 1 && histogram[4] <= 1)
				|| (histogram[1] <= 1 && histogram[3] <= 1 && histogram[5] <= 1))
				twotwotwoflush++;
		}
		if (histogramsorted[0] == 2 && histogramsorted[1] == 2)
		{
			twotwo++;
			if ((histogram[0] <= 1 && histogram[2] <= 1 && histogram[4] <= 1)
				|| (histogram[1] <= 1 && histogram[3] <= 1 && histogram[5] <= 1))
				twotwoflush++;
		}

		dice[DICENUM - 1]++;
		for (int i = DICENUM - 1; i > 0; i--) 
		{
			if (dice[i] > 6)
			{
				dice[i - 1]++;
				dice[i] = 1;
			}
		}
	} while (dice[0] < 7);

	//if (sixstraight > 0)
	//{
	//	cout << sixstraight << " is a length 6 straight" << endl;
	//	temp.input(sixstraight, " is a length 6 straight");
	//	mylist.push_back(temp);
	//}
	if (fivestraight > 0)
	{
		cout << fivestraight << " is a length 5 straight" << endl;
		temp.input(fivestraight, " is a length 5 straight");
		mylist.push_back(temp);
	}
	/*if (fourstraight > 0)
	{
		cout << fourstraight << " is a length 4 straight" << endl;
		temp.input(fourstraight, " is a length 4 straight");
		mylist.push_back(temp);
	}
	if (threestraight > 0)
	{
		cout << threestraight << " is a length 3 straight" << endl;
		temp.input(threestraight, " is a length 3 straight");
		mylist.push_back(temp);
	}
	if (twostraight > 0)
	{
		cout << twostraight << " is a length 2 straight" << endl;
		temp.input(twostraight, " is a length 2 straight");
		mylist.push_back(temp);
	}*/

	/*if (nomatches > 0)
	{
		cout << nomatches << " had no matches.  Wow!" << endl;
		temp.input(nomatches, " had no matches.  Wow!");
		mylist.push_back(temp);
	}*/

	/*if (sixofkind > 0)
	{
		cout << sixofkind << " is 6 of a kind" << endl;
		temp.input(sixofkind, " is 6 of a kind");
		mylist.push_back(temp);
	}*/
	if (fiveofkind > 0)
	{
		cout << fiveofkind << " is 5 of a kind" << endl;
		temp.input(fiveofkind, " is 5 of a kind");
		mylist.push_back(temp);
	}
	if (fourofkind > 0)
	{
		cout << fourofkind << " is 4 of a kind" << endl;
		temp.input(fourofkind, " is 4 of a kind");
		mylist.push_back(temp);
	}
	if (threeofkind > 0)
	{
		cout << threeofkind << " is 3 of a kind" << endl;
		temp.input(threeofkind, " is 3 of a kind");
		mylist.push_back(temp);
	}
	if (twoofkind > 0)
	{
		cout << twoofkind << " is 2 of a kind" << endl;
		temp.input(twoofkind, " is 2 of a kind");
		mylist.push_back(temp);
	}

	/*if (sixofkindex > 0)
	{
		cout << sixofkindex << " is 6 of a kind, exclusive" << endl;
		temp.input(sixofkindex, " is 6 of a kind, exclusive");
		mylist.push_back(temp);
	}
	if (fiveofkindex > 0)
	{
		cout << fiveofkindex << " is 5 of a kind, exclusive" << endl;
		temp.input(fiveofkindex, " is 5 of a kind, exclusive");
		mylist.push_back(temp);
	}
	if (fourofkindex > 0)
	{
		cout << fourofkindex << " is 4 of a kind, exclusive" << endl;
		temp.input(fourofkindex, " is 4 of a kind, exclusive");
		mylist.push_back(temp);
	}
	if (threeofkindex > 0)
	{
		cout << threeofkindex << " is 3 of a kind, exclusive" << endl;
		temp.input(threeofkindex, " is 3 of a kind, exclusive");
		mylist.push_back(temp);
	}
	if (twoofkindex > 0)
	{
		cout << twoofkindex << " is 2 of a kind, exclusive" << endl;
		temp.input(twoofkindex, " is 2 of a kind, exclusive");
		mylist.push_back(temp);
	}*/

	//if (fivetwo > 0)
	//{
	//	cout << fivetwo << " is 5-2" << endl;
	//	temp.input(fivetwo, " is 5-2");
	//	mylist.push_back(temp);
	//}
	/*if (fivetwoflush > 0)
	{
		cout << fivetwoflush << " is 5-2 flush" << endl;
		temp.input(fivetwoflush, " is 5-2 flush");
		mylist.push_back(temp);
	}*/
	/*if (fourthree > 0)
	{
		cout << fourthree << " is 4-3" << endl;
		temp.input(fourthree, " is 4-3");
		mylist.push_back(temp);
	}*/
	/*if (fourthreeflush > 0)
	{
		cout << fourthreeflush << " is 4-3 flush" << endl;
		temp.input(fourthreeflush, " is 4-3 flush");
		mylist.push_back(temp);
	}*/
	/*if (fourtwo > 0)
	{
		cout << fourtwo << " is 4-2" << endl;
		temp.input(fourtwo, " is 4-2");
		mylist.push_back(temp);
	}
	if (fourtwoflush > 0)
	{
		cout << fourtwoflush << " is 4-2 flush" << endl;
		temp.input(fourtwoflush, " is 4-2 flush");
		mylist.push_back(temp);
	}
	if (threethree > 0)
	{
		cout << threethree << " is 3-3" << endl;
		temp.input(threethree, " is 3-3");
		mylist.push_back(temp);
	}
	if (threethreeflush > 0)
	{
		cout << threethreeflush << " is 3-3 flush" << endl;
		temp.input(threethreeflush, " is 3-3 flush");
		mylist.push_back(temp);
	}*/
	/*if (threetwotwo > 0)
	{
		cout << threetwotwo << " is 3-2-2" << endl;
		temp.input(threetwotwo, " is 3-2-2");
		mylist.push_back(temp);
	}
	if (threetwotwoflush > 0)
	{
		cout << threetwotwoflush << " is 3-2-2 flush" << endl;
		temp.input(threetwotwoflush, " is 3-2-2 flush");
		mylist.push_back(temp);
	}*/
	if (threetwo > 0)
	{
		cout << threetwo << " is 3-2" << endl;
		temp.input(threetwo, " is 3-2");
		mylist.push_back(temp);
	}
	if (threetwoflush > 0)
	{
		cout << threetwoflush << " is 3-2 flush" << endl;
		temp.input(threetwoflush, " is 3-2 flush");
		mylist.push_back(temp);
	}
	//if (twotwotwo > 0)
	//{
	//	cout << twotwotwo << " is 2-2-2" << endl;
	//	temp.input(twotwotwo, " is 2-2-2");
	//	mylist.push_back(temp);
	//}
	//if (twotwotwoflush > 0)
	//{
	//	cout << twotwotwoflush << " is 2-2-2 flush" << endl;
	//	temp.input(twotwotwoflush, " is 2-2-2 flush");
	//	mylist.push_back(temp);
	//}
	if (twotwo > 0)
	{
		cout << twotwo << " is 2-2" << endl;
		temp.input(twotwo, " is 2-2");
		mylist.push_back(temp);
	}
	if (twotwoflush > 0)
	{
		cout << twotwoflush << " is 2-2 flush" << endl;
		temp.input(twotwoflush, " is 2-2 flush");
		mylist.push_back(temp);
	}

	cout << endl << endl;

	numstring a;
	for (int i = 0; i < mylist.size() - 1; i++)
	{
		if (mylist[i].value > mylist[i + 1].value)
		{
			a.value = mylist[i].value;
			a.text = mylist[i].text;
			mylist[i].value = mylist[i + 1].value;
			mylist[i].text = mylist[i + 1].text;
			mylist[i + 1].value = a.value;
			mylist[i + 1].text = a.text;
			i = -1;
		}
	}
	for (int i = 0; i < mylist.size(); i++)
		cout << mylist[i].value << " (" << 100*mylist[i].value/TOTALCOMBOS << "%)" << mylist[i].text << endl;

	cout << endl << TOTALCOMBOS << " is total for " << DICENUM << " dice, weeehoooo" << endl;
	return 0;
}