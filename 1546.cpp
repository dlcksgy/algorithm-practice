#include <iostream>
using namespace std;
int main()
{
	int n;
	int input;
	cin >> n;
	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input > max) max = input;
		sum += input;
	}
	double ans = (((double)sum / max)*100.)/(double)n;
	printf("%.2f\n",ans);


}