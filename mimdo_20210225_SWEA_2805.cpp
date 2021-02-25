
#include <iostream>
using namespace std;

int N;
int sum = 0;
int map[50][50];

void upperDFS(int row, int cnt);
void downDFS(int row, int cnt);

int main()
{	
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}

		

		int row = N/2;
		int upcnt = 0;
		int downcnt = 0;

		upperDFS(row, 0);
		downDFS(row+1, 1);


		cout << "#" << i+1 << " " << sum << endl;
		
	}


	return 0;

}

void upperDFS(int row, int cnt)
{
	// cout << "row : " << row << "   cnt : " << cnt;
	if (row < 0 || row >= N)	
		return;
	else 
	{
		for (int i = cnt; i < N - cnt; i++)
		{
			sum += map[row][i];
		}
		// cout << "   Sum : " << sum << endl;

		if (cnt > N / 2) cnt = 0;

		upperDFS(row - 1, cnt + 1);
		
	}
}

void downDFS(int row, int cnt)
{
	// cout << "row : " << row << "   cnt : " << cnt;
	if (row < 0 || row >= N)
		return;
	else
	{
		for (int i = cnt; i < N - cnt; i++)
		{
			sum += map[row][i];
		}
		// cout << "   Sum : " << sum << endl;

		if (cnt > N / 2) cnt = 0;

		downDFS(row + 1, cnt + 1);

	}
	
}
