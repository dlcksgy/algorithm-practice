#include<iostream>
#include <string>
using namespace std;

int main(void)

{

	int T;



	cin >> T;//테스트케이스를 입력받는다.
	cin.ignore();
	for (int t = 0; t < T; t++)

	{

		int open = 0;
		string s;
		char* ch;
		getline(cin, s);
		int len = s.length();
		ch = (char*)s.c_str();
		for (int i = 0; i < len; i++)
		{
			if (ch[i] == '(')
			{
				open++;
			}
			else if (ch[i] == ')')
			{
				open--;
			}
			if (open < 0)
			{
				break;
			}
		}
		if (open == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
