#include<iostream>
using namespace std;

int n, m;
int map[1001][1001];

bool trackedMap[1001][1001];
int moveCntMap[1001][1001];
int breakWallCntMap[1001][1001];

int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };
int minMoveCnt = 2147483647;

void DFS(int x, int y, int moveCnt, bool breakWall) {
   if (moveCnt >= minMoveCnt) return; // minMoveCnt 보다 많이 움직였을 경우, 더 탐색할 가치가 없음.

   if (x == n && y == m && minMoveCnt > moveCnt) { // [n, m] 좌표에 도착했을 때, minMoveCnt보다 현재 moveCnt가 더 작으면 저장.
      minMoveCnt = moveCnt;
      return;
   }

   trackedMap[x][y] = true; // 왔던 길 또 탐색하는 것 방지.
   if (breakWall)
      breakWallCntMap[x][y] = moveCnt; // 벽을 한 번 부순 상태에서 움직인 거리.
   else
      moveCntMap[x][y] = moveCnt; // 벽을 부수지 않은 상태에서 움직인 거리.

   for (int i = 0; i < 4; i++) {
      if (x + dx[i] > n || x + dx[i] <= 0 || y + dy[i] > m || y + dy[i] <= 0) continue; // dx, dy 이동이 map의 경계선을 넘으면 continue.
      if (trackedMap[x + dx[i]][y + dy[i]]) continue; // 이미 왔던 길이면 continue.

      if ((!breakWall && (moveCntMap[x + dx[i]][y + dy[i]] == -1 || moveCntMap[x + dx[i]][y + dy[i]] > moveCnt + 1)) || // 벽을 부수지 않았을 때는, 벽을 부수지 않은 상태끼리만 비교함.
         (breakWall && (breakWallCntMap[x + dx[i]][y + dy[i]] == -1 || breakWallCntMap[x + dx[i]][y + dy[i]] > moveCnt + 1))){ // 벽을 부쉈을 때는, 벽을 부순 상태끼리만 비교함.
                                                                                                // 그렇게 비교해서, 만약 dx, dy로 이동해도 이동 거리가 더 짧아지지 않으면, 다시 탐색할 필요가 없음을 구현.
         if (map[x + dx[i]][y + dy[i]] == 0)
            DFS(x + dx[i], y + dy[i], moveCnt + 1, breakWall); // 벽 안 부수고 이동하기.
         else if (!breakWall)
            DFS(x + dx[i], y + dy[i], moveCnt + 1, true); // 벽 부수고 이동하기. 벽을 부쉈단 의미로 breakWall을 true.
      }
   }

   trackedMap[x][y] = false; // 현재 좌표에서 이전 좌표로 되돌아가는 것이므로, false 해주어야 함.
}

int main() {
   cin >> n >> m;
   for (int i = 1; i <= n; i++) {
      string tmp;
      cin >> tmp;
      for (int j = 1; j <= m; j++) {
         map[i][j] = tmp[j - 1] - 48;
         moveCntMap[i][j] = breakWallCntMap[i][j] = -1;
      }
   }
   DFS(1, 1, 1, false);
   if (minMoveCnt != 2147483647)
      cout << minMoveCnt;
   else
      cout << -1;
}
