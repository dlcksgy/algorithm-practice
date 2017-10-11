#include <iostream>
#include <string>
using namespace std;
int main()
{
	bool blank = false;
	int num = 0;
	string str;
	getline(cin, str);
	if (str[0] == ' ')	blank = true;
	else num++;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			blank = true;
		}
		else
		{
			if(blank == true)num++;
			blank = false;

		}
	}
	cout << num << endl;
}