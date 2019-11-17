#include<iostream>
#include<string>

using namespace std;

int main()
{
	string digits;
	cin >> digits;
	string candidate = "";
	string result = "";

	candidate = digits.at(0);

	for (int i = 0; i < digits.length() - 1; i++)
	{
		string a = digits.substr(i + 1, 1);
		string b = digits.substr(i, 1);


		int oven = abs(stoi(a) - stoi(b)) % 2;

		if (oven == 1)
		{
			candidate += a;
		}

		else
		{
			candidate = digits.substr(i + 1,1);
		}


		int versus = candidate.length() - result.length();

		if (versus > 0)
		{
			result = candidate;
		}

	}
	cout << result;
}