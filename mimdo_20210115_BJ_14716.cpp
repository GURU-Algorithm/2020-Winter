#include <iostream>
#include <vector>
using namespace std;

// 행, 열, 현수막 정보, 글자갯수  
int col, row, val, cnt = 0;

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // y축(col) 변화량
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; // x축(row) 변화량

int flag[255][255] = { 0, };

void DFS(int fcol, int frow);

int main()
{
/* 입력값 넣기 */
	cin >> col;
	cin >> row;

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> val;
			flag[i][j] = val;
		}
	}
/***********************************/

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (flag[i][j] == 1)
			{
				DFS(i, j);
				cnt++;

			}
		}
	}
	cout << cnt;
}

void DFS(int fcol, int frow)
{
	flag[fcol][frow] = 0;

	for (int i = 0; i < 8; i++)
	{
		int ncol = fcol + dy[i];
		int nrow = frow + dx[i];

		if (ncol >= 0 && nrow >= 0 && ncol < col && nrow < row && flag[ncol][nrow]==1)
			DFS(ncol, nrow);
	}

}
