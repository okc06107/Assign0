#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string a = "1521512512512512515";
	string b = "898989898989988998899898";

	string result = "";


	int len1 = a.length();
	int len2 = b.length();
	int k =0;

	if (len1 != len2)
	{
		if (len1 > len2)
		{
			reverse(b.begin(),b.end());
			int plus = len1 - len2;
			b.append(plus, '0');
			reverse(b.begin(), b.end());
		}

		if (len1 < len2)
		{
			reverse(a.begin(), a.end());
			int plus = len2 - len1;
			a.append(plus, '0');
			reverse(a.begin(), a.end());
		}

		
	}

	len1 = a.length();
	len2 = b.length();

	for (int i = 0; i < len1; i++)
	{

		string c_1 = a.substr(len1-i-1,1);
		string c_2 = b.substr(len1-i-1,1);


		int small_calc = stoi(c_1) + stoi(c_2);

		if (k == 1)
		{
			small_calc++;
		}

		k = 0;

		if (small_calc / 10 == 0)
		{
			result += to_string(small_calc);
		}

		else//받아올림이 필요할 때
		{
			result += to_string(small_calc % 10);
			k = 1;
			if ((i + 1) == len1)
			{
				result += '1';
			}

		}


	
	}

	
	reverse(result.begin(), result.end());
	cout << result;

}