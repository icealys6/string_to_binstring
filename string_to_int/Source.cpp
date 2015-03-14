#include <iostream>
#include <math.h>
#include <string>
using namespace std;

char* intstring_to_binstring(string i, char *str)
{
	int pow10 = pow(10, i.length()-1);
	int result = 0;
	for (int idx = 0; pow10 != 0; ++idx, pow10 /= 10)
	{
		result += pow10 * (i.at(idx) - '0');
	}
	for (int idx = 0; idx < 32; ++idx)
	{
		str[idx] = '0' + !!(result & (1 << (31 - idx)));
	}
	str[32] = '\0';
	return str;
}

int main()
{
    string intstring;
	char binstr[33];
	bool checkdigit;

	
	do
	{
		getline(cin, intstring);
		checkdigit = 0;
		for (int i = 0; i < intstring.length(); i++)
		{
			if (!isdigit(intstring.at(i)))
				checkdigit = 1;
		}
	} while (checkdigit);

	intstring_to_binstring(intstring, binstr);

	cout << binstr << endl;

	system("pause");

	return 0;
}