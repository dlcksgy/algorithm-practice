#include <iostream>
using namespace std;

int selfNum(int a)
{
	int ret = a;
	while (1)
	{
		ret += a % 10;
		a /= 10;
		if (a == 0) break;
	}
	return ret;
}

int main()
{
	int a[10000];
	for (int i = 0; i < 10000; i++)
		a[i] = i;
	for (int i = 0; i < 10000; i++)
	{
		if (selfNum(i) >= 10000) continue;
		a[selfNum(i)] = -1;
	}
	for (int i = 0; i < 10000; i++)
		if (a[i] != -1) printf("%d\n", a[i]);
}