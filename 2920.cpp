#include <iostream>
using namespace std;
int main()
{
	int a[8];
	for (int i = 0; i < 8; i++)
		cin >> a[i];
	bool ascending = true;
	bool descending = true;
	for (int i = 0; i < 8; i++)
	{
		if (a[i] == i+1) ascending *= true;
		else ascending *= false;
	}
	
	for (int i = 0; i < 8; i++)
	{
		if (a[7-i] == i+1) descending *= true;
		else descending *= false;
	}
	if (descending)
	{
		printf("descending\n");
		return 0;
	}
	if (ascending)
	{
		printf("ascending\n");
		return 0;
	}
	printf("mixed\n");
	return 0;
}