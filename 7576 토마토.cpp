#include <iostream>  //틀림
using namespace std;

int burn(int** box, int n, int m)  //[n][m]번쨰 칸 토마토에 대해 수행하고 바뀐게있으면 0, 없으면 -1 리턴.
{
	int changed = -1;  //변화가 있는지 없는지 체크하는 변수
	if (box[n][m] == -1)      //빈칸이라면 아무것도 하지 않는다.
		return changed;
	else if (box[n][m] == 2)  //방금익은거면 지나간다.
		return changed;
	else if (box[n][m] == 0)  //안익은거면 지나간다.
		return changed;
	else if (box[n][m] == 1)  //익은 토마토라면 상하좌우를 2로 바꾼다.
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

void burned(int** box, int n, int m)  //방금익은 토마토(2)를 1로 바꿔줌.
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
			cin >> tomatoes[i][j];  //여기까지가 토마토 입력
	for (int i = 0; i < m + 2; i++)
	{
		tomatoes[0][i] = -1;
		tomatoes[n + 1][i] = -1;
	}
	
	for (int i = 1; i <= n + 1; i++)
	{
		tomatoes[i][0] = -1;
		tomatoes[i][m+1] = -1;
	}                                 //여기까지는 벽입력

	cout << count(tomatoes, n, m) << endl;


}