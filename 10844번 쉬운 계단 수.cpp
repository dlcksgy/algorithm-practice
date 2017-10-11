#include <iostream>
using namespace std;
int main(void)
{
	int* memo;
	int n;
	cin >> n;
	memo = new int[n];
	memo[0] = 0;
	memo[1] = 9;
	memo[2] = 17;
	for (int i = 2; i <= n; i++)
	{
		memo[i] = (2 * memo[i - 1] - 1)% 1000000000;
	}
	cout << memo[n] << endl;
}