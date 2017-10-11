#include <iostream>
using namespace std;
void seven(int a)
{
	int num = a % 7;
	if (num == 0) puts("SUN");
	if (num == 1) puts("MON");
	if (num == 2) puts("TUE");
	if (num == 3) puts("WED");
	if (num == 4) puts("THU");
	if (num == 5) puts("FRI");
	if (num == 6) puts("SAT");
}
int main()
{
	int x, y;
	cin >> x >> y;
	int num = y;
	for (int i = 1; i < x; i++)
	{
		if (i == 1) num += 31;
		if (i == 2) num += 28;
		if (i == 3) num += 31;
		if (i == 4) num += 30;
		if (i == 5) num += 31;
		if (i == 6) num += 30;
		if (i == 7) num += 31;
		if (i == 8) num += 31;
		if (i == 9) num += 30;
		if (i == 10) num += 31;
		if (i == 11) num += 30;
		if (i == 12) num += 31;
	}
	seven(num);

}