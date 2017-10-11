#include <iostream>
#include <string>
using namespace std;
int main()
{
	int testcase;
	cin >> testcase;
	for (int T = 0; T < testcase; T++)
	{
		int score = 0;
		int buf = 1;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'X')	buf = 1;
			else
			{
				score += buf;
				buf++;
			}
		}
		printf("%d\n", score);
	}
}