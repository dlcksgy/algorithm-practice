#include <iostream>
using namespace std;

//���Ⱑ ���� ���� 2�ιٲ�.

bool search(int** map, int m, int n);

void run(int** map, int m, int n);


int main(void)
{
	freopen("test.txt", "r", stdin);
	int m, n;
	cin >> m >> n;  //�� ũ�⸦ �Է�
	int** map = new int*[m];  // ���� �� ��ŭ �����Ҵ�
	for (int i = 0; i < m; i++)
	{
		map[i] = new int[n];   //�� �ٿ� �����Ҵ�
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> map[i][j];  //�� ���� �Է�
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
		run(map, m, i);  //��� ù�ٿ����Ͽ� ����Լ��� ����.
	}


	for (int i = 0; i < n; i++)  //�������ٿ� 2�� �ִ��� �˻��Ѵ�.
	{
		if (map[m - 1][i] == 2) ans = true;  //������ ans�� true����.
	}
	return ans;
	
}

void run(int** map, int m, int n)  //1�� ������ ������ ����Լ�
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