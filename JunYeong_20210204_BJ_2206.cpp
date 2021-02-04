#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int n, m, i, j;
	scanf_s("%d %d", &n, &m);
	string temp;
	int map[1001][1001];
	for (i = 0; i < n; i++) {
		cin >> temp;
		for (j = 0; j < m; j++)
			map[i][j] = temp[j] - '0';
	}

	// 방문여부 배열 초기화 ([x][y][0]은 벽 안 부순 상태에서 방문, [x][y][1]은 벽을 부순 상태에서 방문)
	int check[1001][1001][2] = { 0 };  
	check[0][0][0] = 1;

	// ((x, y), (res, bw)) 상태로 전달 (★ 현재 상태에서 벽을 부쉈는지 여부를 전역변수로 초기화 한다면 관리가 어려워짐)
	queue<pair<pair<int, int>, pair<int, int>>> loc; 
	loc.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
	
	while (!loc.empty()) {
		int x = loc.front().first.first;
		int y = loc.front().first.second;
		int res = loc.front().second.first;
		int bw = loc.front().second.second;
		loc.pop();

		// 도착지점에 도달
		if (x == n - 1 && y == m - 1) {
			printf("%d", res);
			return 0;
		}

		// 사방진을 돌면서 너비우선탐색
		for (i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 배열의 범위를 벗어나면 pass
			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
			else {
				// 벽이 가로막고 있지만 한 번도 부순 적이 없는 경우, 그리고 한 번도 방문하지 않았을 때
				// 벽이 가로막고 있을 때 한 번 부순 적이 있으면 pass
				if (map[next_x][next_y] == 1 && bw == 0 && check[next_x][next_y][bw] == 0) {
					check[next_x][next_y][1] = 1; // 방문 체크
					loc.push(make_pair(make_pair(next_x, next_y), make_pair(res + 1, bw + 1)));
				}

				// 길인 경우, ★그리고 한 번도 방문하지 않은 경우
				if (map[next_x][next_y] == 0 && check[next_x][next_y][bw] == 0) {
					check[next_x][next_y][bw] = 1; // 방문 체크(0과 1 구분이 중요함)
					loc.push(make_pair(make_pair(next_x, next_y), make_pair(res + 1, bw)));
				}
			}
		}
	}

	// 큐가 완전히 비었는데도 목표지점에 도달하지 못했으면 -1
	printf("-1");
	return 0;
}
