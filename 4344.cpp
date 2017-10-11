#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++)
	{
		int N;
		cin >> N;
		int* stu;
		int sum = 0;
		stu = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> stu[i];
			sum += stu[i];
		}
		double avr = sum / (double)N;
		int over = 0;
		for (int i = 0; i < N; i++)
		{
			if (stu[i] > avr) over++;
		}
		printf("%.3f%\n", (over / (double)N)*100.);

	}
}