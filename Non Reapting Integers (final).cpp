#include<iostream>
#include<math.h>

using namespace std;


int factorial(int num, int len)
{
	int a = num;
	for (int i = num; i > (num- len); i--)
	{
		a = a * i;
	}
	return a/num;
}

int main()
{
	int radix;
	int summation =0;
	cin >> radix;

	for (int i = radix; i > 0; i--)
	{
		summation += (radix - 1) * factorial(radix - 1, i - 1);
	}

	cout << summation;

}