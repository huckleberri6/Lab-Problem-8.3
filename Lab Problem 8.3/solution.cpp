
#include <iostream>
#include <string>
using namespace std;

int convertRomanToInt(string str);
int value(string str);

int main()
{
	string s = "MDCCCLXXXVIII";
	int val = convertRomanToInt(s);
	cout << val;
}

int value(string str)
{
	if (str == "I")
		return 1;
	else if (str == "V")
		return 5;
	else if (str == "X")
		return 10;
	else if (str == "L")
		return 50;
	else if (str == "C")
		return 100;
	else if (str == "D")
		return 500;
	else if (str == "M")
		return 1000;
}

int convertRomanToInt(string str)
{
	int total = 0;
	for (int i = 0; i < str.length(); i++)
	{
		//cout << "(i, 1): " << value(str.substr(i, 1)) << endl;
		//cout << "(i + 1, 1): " << value(str.substr(i + 1, 1)) << endl;
		if (i == str.length() - 1 || value(str.substr(i, 1)) >= value(str.substr(i + 1, 1)))
		{
			total += value(str.substr(i,1));
		}
		else
		{
			int val = value(str.substr(i + 1, 1)) - value(str.substr(i, 1));
			total += val;
			i++;
		}
		//cout << "total: " << total << endl;

	}
	return total;
}