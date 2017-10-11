#include <iostream>
using namespace std;

bool isHan(int a)
{
	if (a < 100) 
		return true;
	int dif;
	dif = (a % 10) - ((a / 10) % 10);
	int buf;
	while (1)
	{
		buf = a % 10;
		if (buf - ((a/10)%10) != dif)
			return false;
		a /= 10;
		if (a/10 == 0) break;
	}
	return true;
}

int main()
{
	int n;
	int num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		if (isHan(i)) 
			num++;
	printf("%d\n", num);
}