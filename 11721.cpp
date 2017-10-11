#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int n = str.size() / 10;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++) printf("%c", str[i * 10 + j]);
		puts("");
	}
	for(int i = 0; i < str.size()%10; i++) printf("%c", str[n*10+i]);
	puts("");
}