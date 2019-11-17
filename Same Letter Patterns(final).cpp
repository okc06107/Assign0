#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	string str1;
	string str2;
	int i,k;

	getline(cin, str1);
	cin.clear(); 
	getline(cin, str2);

	int len1 = str1.length();
	int len2 = str2.length();

	if (len1 != len2)
	{
		cout << "false";
		return 0;
	}

	char compare[2];

	for (i = 0; i < len1; i++)
	{
		compare[0] = str1[i];
		compare[1] = str2[i];

		for (k = 0; k < len1; k++)
		{
			if (compare[0] == str1[k])
			{
				if (compare[1] != str2[k])
				{
					cout << "false";
					return 0;
				}
			}
		}
	}


	cout << "true";



	

}