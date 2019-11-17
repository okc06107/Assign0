#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<stack>

using namespace std;

/*oper ����ü���� ��� �켱���� pr�� �� ��� shp�� ����Ǿ��ִ�.*/
struct oper
{
	int pr;
	string shp;
};

/*���� ������ �����Ѵ�*/
stack<int> num;
stack<oper> op;

/*stack�� ����ϴ� �Լ�*/

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
	num.push(c); //�ٽ� ���ÿ� �ִ´�.
}

bool formula(string str)
{
	/*��� ������ �����Ѵ�*/
	int len;
	int i = 0;
	int count = 0;
	int first, second, third;
	str.append("k");
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
	len = str.length(); //len�� ���ڿ��� �����̴�.

	for (int l = 0; l < len; l++)
	{
		string equal = "=";
		if (equal == str.substr(l, 1))
			count++;
	}

	/*���� ���ڿ��� substr�� �ϳ��� �߶� push�� ��*/
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



		/*��ȣ�� ������ ��� �켱����*/
		/*�켱������ ����: ���� Ŭ���� ���� ����Ѵ�.*/
		/*
			"*,/": 3 
			"+,-":2
			"()": 1
		*/
		if (temp == "(")
		{
			op.push({ 1,"(" });
		}

		/*���� )�� ���̸� ���� �� ����Ѵ�.*/
		else if (temp == ")")
		{
			while (op.top().shp != "(")
				calc();

			op.pop();
		}

		/*a�� 4���� �˰� �ִ�.*/
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

		/*=�� ���̸� Ż��...!*/
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
	
	/*num�� op�� �����!*/
	while(!num.empty())
	num.pop();

	while (!op.empty())
		op.pop();

	/*�� = ���� Ż���ϸ� �ȵ��ݾ�...*/
	i++;

	/*�ι�° ���*/
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


		/*��ȣ�� ������ ��� �켱����*/
		/*�켱������ ����: ���� Ŭ���� ���� ����Ѵ�.*/
		if (temp == "(")
		{
			op.push({ 1,"(" });
		}

		/*���� )�� ���̸� ���� �� ����Ѵ�.*/
		else if (temp == ")")
		{
			while (op.top().shp != "(")
				calc();

			op.pop();
		}

		/*a�� 4���� �˰� �ִ�.*/
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

		/*=�� ���̸� Ż��...!*/
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

	/*��ȣ�� 1����� �ٷ� ������!*/
	if (count == 1)
	{
		if (first == second)
			return true;

		else
			return false;
	}


	/*��ȣ�� 2�����..*/
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

			/*��ȣ�� ������ ��� �켱����*/
			/*�켱������ ����: ���� Ŭ���� ���� ����Ѵ�.*/
			/*
				"*,/": 3
				"+,-":2
				"()": 1
			*/
			if (temp == "(")
			{
				op.push({ 1,"(" });
			}

			/*���� )�� ���̸� ���� �� ����Ѵ�.*/
			else if (temp == ")")
			{
				while (op.top().shp != "(")
					calc();

				op.pop();
			}

			/*a�� 4���� �˰� �ִ�.*/
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

			/*=�� ���̸� Ż��...!*/
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


/*�Է°��� �ް� ���� ����ϴ� main*/
int main()
{
	string str;
	bool a;
	getline(cin, str);
	a=formula(str);
	cout << a;
}