#include<iostream>

using namespace std;

long long int calc_next_bonacci(long long int N, long long int* arr,long long int start)
{
	long long int result;
	long long int i = start;
	for (long long int j = 0; j < N; j++)
	{
		arr[start+N] += arr[start + j];
	}
	result = arr[start +N];
	return result;
}

int main()
{

}