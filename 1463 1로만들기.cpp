#include<iostream>
using namespace std;


int min2(int a, int b)
{
	if (a < b)return a;
	else return b;
}

int* d;
int go(int num)
{
	if (d[num] != -1) return d[num];
	if (num % 3 == 0) {
		if (num % 2 == 0)
		{
			d[num] = min2(go(num / 3), go(num / 2)) + 1;
		}
		d[num] = min2(go(num / 3),go(num-1)) + 1;
	}
	else if(num%2 == 0){
		d[num] = min2(go(num / 2), go(num - 1)) + 1;
	}
	else {
		d[num] = go(num - 1) + 1;
	}
	return d[num];
}



int main(void)
{
	while (1) {
		int num;
		cin >> num;
		d = new int[num + 1];
		fill_n(d, num + 1, -1);
		d[0] = 0;
		d[1] = 0;
		d[2] = 1;
		d[3] = 1;
		int ans = go(num);
		cout << ans << endl;
		delete []d;
	}
	return 0;
}

