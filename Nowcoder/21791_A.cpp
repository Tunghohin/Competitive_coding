#include <iostream>

using namespace std;

long long pow_2[100];

int main()
{
	int n;
	cin >> n;

	long long res = 0;
	pow_2[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		pow_2[i] = pow_2[i - 1] * 2;
		res += pow_2[i];
	}

	cout << res << '\n';
}