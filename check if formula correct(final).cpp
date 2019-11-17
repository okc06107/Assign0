#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<stack>

using namespace std;

/*oper 구조체에는 계산 우선순위 pr과 그 모양 shp이 저장되어있다.*/
struct oper
{
	int pr;
	string shp;
};

/*각각 스택을 선언한다*/
stack<int> num;
stack<oper> op;

/*stack을 계산하는 함수*/

void calc()
{
	int a, b, c;
	string o;
	b = num.top();
	num.pop();
	a = num.top();
	num.pop();

	o = op.top().shp;

	if (o == "+")
		c = a + b;
	else if (o == "-")
		c = a - b;
	else if (o == "*")
		c = a * b;
	else if (o == "/")
		c = a / b;
	op.pop();
	num.push(c); //다시 스택에 넣는다.
}

bool formula(string str)
{
	/*모든 공백을 삭제한다*/
	int len;
	int i = 0;
	int count = 0;
	int first, second, third;
	str.append("k");
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
	len = str.length(); //len은 문자열의 길이이다.

	for (int l = 0; l < len; l++)
	{
		string equal = "=";
		if (equal == str.substr(l, 1))
			count++;
	}

	/*이제 문자열을 substr로 하나씩 잘라서 push할 것*/
	for (i; i < len; i++)
	{
		int k = 1;
		if ((str.substr(i, 1) == "0") || (str.substr(i, 1) == "1") || (str.substr(i, 1) == "2") || (str.substr(i, 1) == "3") || (str.substr(i, 1) == "4") || (str.substr(i, 1) == "5") || (str.substr(i, 1) == "6") || (str.substr(i, 1) == "7") || (str.substr(i, 1) == "8") || (str.substr(i, 1) == "9"))
		{
			int j = i + 1;
			while ((str.substr(j, 1) != "+") && (str.substr(j, 1) != "-") && (str.substr(j, 1) != "*") && (str.substr(j, 1) != "/") && (str.substr(j, 1) != "(") && (str.substr(j, 1) != ")") && (str.substr(j, 1) != "=") && (str.substr(j, 1) != " "))
			{
				k++;
				j++;
			}
		}
		string temp = str.substr(i, k);



		/*괄호는 무조건 계산 우선순위*/
		/*우선순위의 정리: 수가 클수록 먼저 계산한다.*/
		/*
			"*,/": 3 
			"+,-":2
			"()": 1
		*/
		if (temp == "(")
		{
			op.push({ 1,"(" });
		}

		/*이제 )가 보이면 앞을 쭉 계산한다.*/
		else if (temp == ")")
		{
			while (op.top().shp != "(")
				calc();

			op.pop();
		}

		/*a는 4임을 알고 있다.*/
		else if (temp == "a")
		{
			num.push(4);
		}

		else if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
		{
			int order = 0;

			if (temp == "+")
				order = 2;

			else if (temp == "-")
				order = 2;

			else if (temp == "*")
				order = 3;

			else if (temp == "/")
				order = 3;

			while (!op.empty() && order <= op.top().pr)
				calc();

			op.push({ order, temp });
		}

		/*=가 보이면 탈출...!*/
		else if (temp == "=")
			break;

		else if (temp == "k")
			break;

		else
			num.push(stoi(temp));

		i += (k - 1);
	}

	while (!op.empty())
		calc();

	first = num.top();
	
	/*num과 op를 비우자!*/
	while(!num.empty())
	num.pop();

	while (!op.empty())
		op.pop();

	/*또 = 보고 탈출하면 안되잖어...*/
	i++;

	/*두번째 계산*/
	for (i; i < len-1; i++)
	{
	
		int k = 1;
		if ((str.substr(i, 1) == "0") || (str.substr(i, 1) == "1") || (str.substr(i, 1) == "2") || (str.substr(i, 1) == "3") || (str.substr(i, 1) == "4") || (str.substr(i, 1) == "5") || (str.substr(i, 1) == "6") || (str.substr(i, 1) == "7") || (str.substr(i, 1) == "8") || (str.substr(i, 1) == "9"))
		{
			int j = i + 1;
			while ((str.substr(j, 1) != "+") && (str.substr(j, 1) != "-") && (str.substr(j, 1) != "*") && (str.substr(j, 1) != "/") && (str.substr(j, 1) != "(") && (str.substr(j, 1) != ")") && (str.substr(j, 1) != "=") && (str.substr(j, 1) != " ") && (str.substr(j,1))!= "k")
			{
				k++;
				j++;
			}
		}

		string temp = str.substr(i, k);


		/*괄호는 무조건 계산 우선순위*/
		/*우선순위의 정리: 수가 클수록 먼저 계산한다.*/
		if (temp == "(")
		{
			op.push({ 1,"(" });
		}

		/*이제 )가 보이면 앞을 쭉 계산한다.*/
		else if (temp == ")")
		{
			while (op.top().shp != "(")
				calc();

			op.pop();
		}

		/*a는 4임을 알고 있다.*/
		else if (temp == "a")
		{
			num.push(4);
		}

		else if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
		{
			int order;

			if (temp == "+")
				order = 2;

			else if (temp == "-")
				order = 2;

			else if (temp == "*")
				order = 3;

			else if (temp == "/")
				order = 3;

			while (!op.empty() && order <= op.top().pr)
				calc();

			op.push({ order, temp });
		}

		/*=가 보이면 탈출...!*/
		else if (temp == "=")
			break;

		else if (temp == "k")
			break;

		else
			num.push(stoi(temp));

		i += (k - 1);
	}

	while (!op.empty())
		calc();

	second = num.top();

	while (!num.empty())
		num.pop();

	/*등호가 1개라면 바로 비교하자!*/
	if (count == 1)
	{
		if (first == second)
			return true;

		else
			return false;
	}


	/*등호가 2개라면..*/
	if (count == 2)
	{
		i++;

		for (i; i < len; i++)
		{
			int k = 1;

			if ((str.substr(i, 1) == "0") || (str.substr(i, 1) == "1") || (str.substr(i, 1) == "2") || (str.substr(i, 1) == "3") || (str.substr(i, 1) == "4") || (str.substr(i, 1) == "5") || (str.substr(i, 1) == "6") || (str.substr(i, 1) == "7") || (str.substr(i, 1) == "8") || (str.substr(i, 1) == "9"))
			{
				int j = i + 1;
				while ((str.substr(j, 1) != "+") && (str.substr(j, 1) != "-") && (str.substr(j, 1) != "*") && (str.substr(j, 1) != "/") && (str.substr(j, 1) != "(") && (str.substr(j, 1) != ")") && (str.substr(j, 1) != "=") && (str.substr(j, 1) != " ") && ((str.substr(j, 1)) != "k"))
				{
					k++;
					j++;
				}
			}
			string temp = str.substr(i, k);

			/*괄호는 무조건 계산 우선순위*/
			/*우선순위의 정리: 수가 클수록 먼저 계산한다.*/
			/*
				"*,/": 3
				"+,-":2
				"()": 1
			*/
			if (temp == "(")
			{
				op.push({ 1,"(" });
			}

			/*이제 )가 보이면 앞을 쭉 계산한다.*/
			else if (temp == ")")
			{
				while (op.top().shp != "(")
					calc();

				op.pop();
			}

			/*a는 4임을 알고 있다.*/
			else if (temp == "a")
			{
				num.push(4);
			}

			else if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
			{
				int order;

				if (temp == "+")
					order = 2;

				else if (temp == "-")
					order = 2;

				else if (temp == "*")
					order = 3;

				else if (temp == "/")
					order = 3;

				while (!op.empty() && order <= op.top().pr)
					calc();

				op.push({ order, temp });
			}

			/*=가 보이면 탈출...!*/
			else if (temp == "=")
				break;

			else if (temp == "k")
				break;

			else
				num.push(stoi(temp));

			i += (k - 1);
		}

		while (!op.empty())
			calc();

		third = num.top();

		if (first == second)
		{
			if (second == third)
				return true;

			else
				return false;
		}

		else
			return false;
	}

	return false;
}


/*입력값을 받고 답을 출력하는 main*/
int main()
{
	string str;
	bool a;
	getline(cin, str);
	a=formula(str);
	cout << a;
}