#include <iostream>
using namespace std;

int map[250][250], n, m;
void solution(int x, int y) {
	int i, j, rx, ry;
	
	// 현재 위치가 글자 부분인 경우
	if(map[x][y] == 1) {
		map[x][y] = 0; // 해당 부분을 지우고
		for(i=0; i<3; i++) { // x, y를 center로 두고 8방향 숫자들을 확인
			for(j=0; j<3; j++) {
				rx = x + i -1;
				ry = y + j -1;
				
				// 배열의 범위를 넘어서면 pass
				if(rx < 0 || ry < 0 || rx >= n || ry >= m) continue;
				// 범위를 넘어서지 않으면 해당 위치를 center로 두고 다시 확인
				solution(rx, ry);
			}	
		}
	}
}

int main() {
	int i, j, res=0;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(map[i][j] == 1) {
				res++;
				solution(i, j);		
			}
		}
	}
	
	printf("%d", res);
	return 0;
}
