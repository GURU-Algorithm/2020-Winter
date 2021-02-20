#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
				// map은 경로를 담은 배열, res는 최소 비용을 담은 배열
        int n, i, j, map[101][101], res[101][101];
        cin >> n;

        string temp;
        for (i = 0; i < n; i++) {
            cin >> temp;
            for (j = 0; j < n; j++) {
                map[i][j] = temp.at(j) - '0';
                res[i][j] = 2147000000;
            }
        }
        res[0][0] = 0;

				// BFS로 최소 비용 경로 찾기
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int x, y, rx, ry;

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (i = 0; i < 4; ++i) {
                rx = x + dx[i];
                ry = y + dy[i];

								// 배열을 벗어나면 out
                if (rx < 0 || ry < 0 || rx >= n || ry >= n) continue;
                else {
										 // rx, ry 까지 가는데 걸리는 비용 계산
                     int temp_dist = res[x][y] + map[rx][ry];
										 
										 // 기존의 비용과 현재 비용 비교해서 최소 비용으로 갱신
                     if (temp_dist < res[rx][ry]) {
                         q.push(make_pair(rx, ry));
                         res[rx][ry] = temp_dist;
                     }
                }
            }
        }

        printf("#%d %d\n", test_case, res[n-1][n-1]);
    }
    return 0;
}
