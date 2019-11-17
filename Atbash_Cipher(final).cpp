#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str = "";
	char letter = '1';
	int i;
	getline(cin,str); //입력 방법 한번 정리하자 ㅠㅠ
	int len = str.length(); // string과 *char은 다르게 다뤄야 한다는거...

	for(i=0;i<len;i++)//==를 집어넣다니;;;
	{

		letter = str[i];

		if (letter == 'a')
		{
			str[i] = 'z';
		}

		else if (letter == 'b')
		{
			str[i] = 'y';
		}

		else if (letter == 'c')
		{
			str[i] = 'x';
		}

		else if (letter == 'd')
		{
			str[i] = 'w';
		}

		else if (letter == 'e')
		{
			str[i] = 'v';
		}

		else if (letter == 'f')
		{
			str[i] = 'u';
		}

		else if (letter == 'g')
		{
			str[i] = 't';
		}

		else if (letter == 'h')
		{
			str[i] = 's';
		}

		else if (letter == 'i')
		{
			str[i] = 'r';
		}

		else if (letter == 'j')
		{
			str[i] = 'q';
		}

		else if (letter == 'k')
		{
			str[i] = 'p';
		}

		else if (letter == 'l')
		{
			str[i] = 'o';
		}

		else if (letter == 'm')
		{
			str[i] = 'n';
		}

		else if (letter == 'n')
		{
			str[i] = 'm';
		}

		else if (letter == 'o')
		{
			str[i] = 'l';
		}

		else if (letter == 'p')
		{
			str[i] = 'k';
		}

		else if (letter == 'q')
		{
			str[i] = 'j';
		}

		else if (letter == 'r')
		{
			str[i] = 'i';
		}

		else if (letter == 's')
		{
			str[i] = 'h';
		}

		else if (letter == 't')
		{
			str[i] = 'g';
		}

		else if (letter == 'u')
		{
			str[i] = 'f';
		}

		else if (letter == 'v')
		{
		str[i] = 'e';
		}

		else if (letter == 'w')
		{
		str[i] = 'd';
		}

		else if (letter == 'x')
		{
		str[i] = 'c';
		}

		else if (letter == 'y')
		{
		str[i] = 'b';
		}

		else if (letter == 'z')
		{
		str[i] = 'a';
		}

		else if (letter == 'A')
		{
			str[i] = 'Z';
		}

		else if (letter == 'B')
		{
			str[i] = 'Y';
		}

		else if (letter == 'C')
		{
			str[i] = 'X';
		}

		else if (letter == 'D')
		{
			str[i] = 'W';
		}

		else if (letter == 'E')
		{
			str[i] = 'V';
		}

		else if (letter == 'F')
		{
			str[i] = 'U';
		}

		else if (letter == 'G')
		{
			str[i] = 'T';
		}

		else if (letter == 'H')
		{
			str[i] = 'S';
		}

		else if (letter == 'I')
		{
			str[i] = 'R';
		}

		else if (letter == 'J')
		{
			str[i] = 'Q';
		}

		else if (letter == 'K')
		{
			str[i] = 'P';
		}

		else if (letter == 'L')
		{
			str[i] = 'O';
		}

		else if (letter == 'M')
		{
			str[i] = 'N';
		}

		else if (letter == 'N')
		{
			str[i] = 'M';
		}

		else if (letter == 'O')
		{
			str[i] = 'L';
		}

		else if (letter == 'P')
		{
			str[i] = 'K';
		}

		else if (letter == 'Q')
		{
			str[i] = 'J';
		}

		else if (letter == 'R')
		{
			str[i] = 'I';
		}

		else if (letter == 'S')
		{
			str[i] = 'H';
		}

		else if (letter == 'T')
		{
			str[i] = 'G';
		}

		else if (letter == 'U')
		{
			str[i] = 'F';
		}

		else if (letter == 'V')
		{
			str[i] = 'E';
		}

		else if (letter == 'W')
		{
			str[i] = 'D';
		}

		else if (letter == 'X')
		{
			str[i] = 'C';
		}

		else if (letter == 'Y')
		{
			str[i] = 'B';
		}

		else if (letter == 'Z')
		{
			str[i] = 'A';
		}


	}
	cout << str;

}