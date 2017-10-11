#include <iostream>
using namespace std;

//전기가 통한 곳은 2로바꿈.

bool search(int** map, int m, int n);

void run(int** map, int m, int n);


int main(void)
{
	freopen("test.txt", "r", stdin);
	int m, n;
	cin >> m >> n;  //맵 크기를 입력
	int** map = new int*[m];  // 맵의 줄 만큼 동적할당
	for (int i = 0; i < m; i++)
	{
		map[i] = new int[n];   //각 줄에 동적할당
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> map[i][j];  //맵 내부 입력
		}
	}
	if (search(map, m, n))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

}

bool search(int** map, int m, int n)
{
	bool ans = false;
	
	for (int i = 0; i < n; i++)
	{
		run(map, m, i);  //모든 첫줄에대하여 재귀함수를 실행.
	}


	for (int i = 0; i < n; i++)  //마지막줄에 2가 있는지 검사한다.
	{
		if (map[m - 1][i] == 2) ans = true;  //있으면 ans가 true가됨.
	}
	return ans;
	
}

void run(int** map, int m, int n)  //1로 전류를 보내는 재귀함수
{
	if (map[m][n] == 2) return;
	else if (map[m][n] == 1)
	{
		map[m][n] = 2;
		run(map, m, n + 1);
		run(map, m, n - 1);
		run(map, m + 1, n);
	}
	else return;
}