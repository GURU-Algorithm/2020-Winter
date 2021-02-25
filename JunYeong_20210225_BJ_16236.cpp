#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[26][26];
int ch[26][26];

struct Fish {
	int x, y, dis;
	Fish(int _x, int _y, int _dis) {
		x = _x;
		y = _y;
		dis = _dis;
	}

	// Min Heap 
	bool operator < (const Fish& b) const {
		if (dis == b.dis) {
			if (x == b.x) return y > b.y;
			else return x > b.x;
		}
		else return dis > b.dis;
	}
};

struct BabyShark {
	int x, y, size=2, ate=0;
	void sizeUp() {
		ate = 0;
		size++;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int i, j, n, res;
	BabyShark babyshark;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				babyshark.x = i;
				babyshark.y = j;
				map[i][j] = 0;
			}
		}
	}

	priority_queue<Fish> pq;
	pq.push(Fish(babyshark.x, babyshark.y, 0));

	while (!pq.empty()) {
		Fish tmp = pq.top();
		int x = tmp.x;
		int y = tmp.y;
		int dis = tmp.dis;
		pq.pop();

		// 먹을 수 있는 물고기라면 
		if (map[x][y] != 0 && map[x][y] < babyshark.size) {
			babyshark.x = x;
			babyshark.y = y;
			babyshark.ate++;
			map[x][y] = 0;
			if (babyshark.ate == babyshark.size) {
				babyshark.sizeUp();
			}

			// 상태 초기화 
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					ch[i][j] = 0;
				}
			}
			while (!pq.empty()) pq.pop();

			// 시작점부터 해당 지점까지 움직인 거리 
			res = dis;
		}

		for (i = 0; i < 4; ++i) {
			int rx = x + dx[i];
			int ry = y + dy[i];
			if (x > 0 && y > 0 && x <= n && y <= n) {
				if (map[rx][ry] <= babyshark.size && ch[rx][ry] == 0) {
					pq.push(Fish(rx, ry, dis + 1));
					ch[rx][ry] = 1;
				}
			}
		}
	}

	printf("%d", res);
	return 0;
}
