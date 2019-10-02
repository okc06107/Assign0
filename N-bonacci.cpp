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
	/*초기세팅*/
	long long int bonacci_arr[1000] = {0};
	long long int result;
	long long int N, k;
	long long int l;

	cin >> N;
	cin >> k;

	bonacci_arr[N - 1] = 1;

	for (l = 0; l < (k - N); l++)
	{
		calc_next_bonacci(N, bonacci_arr, l);
	}



	cout << bonacci_arr[k-1];
}