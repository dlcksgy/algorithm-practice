#include <iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int cycle = 0;
	int buf = num;
	while (1)
	{
		cycle++;
		buf = (buf % 10) * 10 + ((buf / 10) + (buf % 10))%10;
		if (buf == num) break;
	}
	cout << cycle << endl;

}