#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// 12시부터 시계방향
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main(int argc, char** argv) {
		int test_case, T;
		cin >> T;
	
		for (test_case = 1; test_case <= T; ++test_case) {
				int n, m, i, j, k, l, cn, cm, c, map[9][9] = { 0 };
				cin >> n >> m;
		
				// 기본 돌 배치
				map[n / 2][n / 2] = map[n / 2 + 1][n / 2 + 1] = 2;
				map[n / 2][n / 2 + 1] = map[n / 2 + 1][n / 2] = 1;
		
				for (i = 0; i < m; i++) {
						cin >> cn >> cm >> c;
						map[cn][cm] = c;
		
						for (j = 0; j < 8; j++) {
								for (k = 1; k < n; k++) {
										int rn = cn + dx[j] * k;
										int rm = cm + dy[j] * k;
					
										// 판을 넘어섬 or 돌이 안깔림
										if (rn <= 0 || rm <= 0 || rn > n || rm > n || map[rn][rm] == 0) break;
					
										// 바로 옆에 같은 색의 돌이 있음
										if (map[rn][rm] == c && k == 1) break;
					                    
										// 같은 색의 돌이 있음
										else if (map[rn][rm] == c && k != 1) {
												for (l = 1; l < k; l++) {
														map[cn + dx[j] * l][cm + dy[j] * l] = c;
												}
					            break;
										}
								}
						}
				}
		
				int black = 0, white = 0;
				for (j = 1; j <= n; j++) {
						for (k = 1; k <= n; k++) {
								if (map[j][k] == 1) ++black;
								else if (map[j][k] == 2)++white;
						}
				}
		
				printf("#%d %d %d\n", test_case, black, white);
		}
		return 0;
}
