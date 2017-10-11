#include <iostream>
#include <string>
using namespace std;

int ctoi(char a)
{
	if (a == '0') return 0;
	if (a == '1') return 1;
	if (a == '2') return 2;
	if (a == '3') return 3;
	if (a == '4') return 4;
	if (a == '5') return 5;
	if (a == '6') return 6;
	if (a == '7') return 7;
	if (a == '8') return 8;
	if (a == '9') return 9;
	return -1;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int mul = a*b*c;
	string str(to_string(mul));
	int arr[10] = { 0, };
	for (int i = 0; i < str.size(); i++)
	{
		arr[ctoi(str[i])]++;
	}
	for (int i = 0; i < 10; i++) printf("%d\n", arr[i]);

}