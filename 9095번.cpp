#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		int* memo;
		memo = new int[n + 1];
		memo[0] = 1;
		memo[1] = 1;
		memo[2] = 2;
		memo[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
		}
		cout << memo[n] << endl;
		delete [] memo;
	}
}