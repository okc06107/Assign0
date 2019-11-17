#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int hundred = n / 100;
	int ten = (n % 100) / 10;
	int one = n % 10;
	int num[3] = { hundred, ten , one };
	int i;
	string res = "";


	for (i = 0; i < 3; i++)
	{
		int k = num[i];

		if (i == 0)
		{
			if (k == 1)
			{
				res += "one ";
				res += "hundred ";
			}
			else if (k == 2)
			{
				res += "two ";
				res += "hundred ";
			}
			else if (k == 3)
			{
				res += "three ";
				res += "hundred ";
			}
			else if (k == 4)
			{
				res += "four ";
				res += "hundred ";
			}
			else if (k == 5)
			{
				res += "five ";
				res += "hundred ";
			}
			else if (k == 6)
			{
				res += "six ";
				res += "hundred ";
			}
			else if (k == 7)
			{
				res += "seven ";
				res += "hundred ";
			}
			else if (k == 8)
			{
				res += "eight ";
				res += "hundred ";
			}
			else if (k == 9)
			{
				res += "nine ";
				res += "hundred ";
			}

		}


		if (i == 1)
		{
			if (k == 2)
				res += "twenty ";
			else if (k == 3)
				res += "thirty ";
			else if (k == 4)
				res += "fourty ";
			else if (k == 5)
				res += "fifty ";
			else if (k == 6)
				res += "sixty ";
			else if (k == 7)
				res += "seventy ";
			else if (k == 8)
				res += "eighty ";
			else if (k == 9)
				res += "ninety ";
			else if (k == 1)
			{
				if (num[2] == 0)
					res += "ten";

				else if (num[2] == 1)
					res += "eleven";

				else if (num[2] == 2)
					res += "twelve";

				else if (num[2] == 3)
					res += "thirteen";

				else if (num[2] == 4)
					res += "fourteen";

				else if (num[2] == 5)
					res += "fifteen";

				else if (num[2] == 6)
					res += "sixteen";

				else if (num[2] == 7)
					res += "seventeen";

				else if (num[2] == 8)
					res += "eighteen";

				else if (num[2] == 9)
					res += "nineteen";

			}

		}

		if (i == 2)
		{
			if (num[1] == 1)
				cout << res;
			else
			{
				if (num[2] == 1)
					res += "one";
				else if (num[2] == 2)
					res += "two";
				else if (num[2] == 3)
					res += "three";
				else if (num[2] == 4)
					res += "four";
				else if (num[2] == 5)
					res += "five";
				else if (num[2] == 6)
					res += "six";
				else if (num[2] == 7)
					res += "seven";
				else if (num[2] == 8)
					res += "eight";
				else if (num[2] == 9)
					res += "nine";

			}

		}

	}
	if (num[1] == 0 && num[2] == 0 && num[0] == 0)
	{
		res += "zero";
	}
	cout << res;
	return 0;
}