#include <iostream>
using namespace std;
int main(void)
{
	int len;
	cin >> len;
	int* memo;
	memo = new int[len + 1];
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 3;
	for (int i = 3; i <= len; i++)
	{
		memo[i] = (memo[i - 1] + (memo[i - 2] * 2)) % 10007; //�����÷ο� ����
	}
	cout << memo[len] << endl;
	return 0;
}