#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a <= b && b <= c) cout << b;
	else if (a >= b && b >= c) cout << b;
	else if (b >= a && a >= c) cout << a;
	else if (b <= a && a <= c) cout << a;
	else if (b >= c && c >= a) cout << c;
	else if (b <= c && c <= a) cout << c;
}