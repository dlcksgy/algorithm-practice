#include <iostream>  //Ʋ��
using namespace std;

int burn(int** box, int n, int m)  //[n][m]���� ĭ �丶�信 ���� �����ϰ� �ٲ�������� 0, ������ -1 ����.
{
	int changed = -1;  //��ȭ�� �ִ��� ������ üũ�ϴ� ����
	if (box[n][m] == -1)      //��ĭ�̶�� �ƹ��͵� ���� �ʴ´�.
		return changed;
	else if (box[n][m] == 2)  //��������Ÿ� ��������.
		return changed;
	else if (box[n][m] == 0)  //�������Ÿ� ��������.
		return changed;
	else if (box[n][m] == 1)  //���� �丶���� �����¿츦 2�� �ٲ۴�.
	{
		if (box[n - 1][m] == 0)
		{
			box[n - 1][m] = 2; 
			changed = 0;
		}
		if (box[n + 1][m] == 0)
		{
			box[n + 1][m] = 2;
			changed = 0;
		}
		if (box[n][m - 1] == 0)
		{
			box[n][m - 1] = 2;
			changed = 0;
		}
		if (box[n][m + 1] == 0)
		{
			box[n][m + 1] = 2;
			changed = 0;
		}
	}
	return changed;
}

void burned(int** box, int n, int m)  //������� �丶��(2)�� 1�� �ٲ���.
{
	if (box[n][m] == 2)
		box[n][m] = 1;
}

int count(int** box, int n, int m)
{
	int ret = 0;
	
	while (1)
	{

		bool changed = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (burn(box, i, j) == 0)
					changed += true;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				burned(box, i, j);
		if (!changed) break;
		ret++;

	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(box[i][j] != 1)
				ret = -1;
	return ret;


}



int main()
{
	freopen("1.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int** tomatoes;
	tomatoes = new int*[n+2];
	for (int i = 0; i < n+2; i++)
		tomatoes[i] = new int[m+2];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> tomatoes[i][j];  //��������� �丶�� �Է�
	for (int i = 0; i < m + 2; i++)
	{
		tomatoes[0][i] = -1;
		tomatoes[n + 1][i] = -1;
	}
	
	for (int i = 1; i <= n + 1; i++)
	{
		tomatoes[i][0] = -1;
		tomatoes[i][m+1] = -1;
	}                                 //��������� ���Է�

	cout << count(tomatoes, n, m) << endl;


}