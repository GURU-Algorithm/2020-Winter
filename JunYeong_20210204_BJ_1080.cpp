#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
	// 행렬 입력받기
	int n, m, i, j, p, q;
	scanf_s("%d %d", &n, &m);
	string temp;
	int before[51][51];
	int after[51][51];
	for (i = 0; i < n; i++) {
		cin >> temp;
		for (j = 0; j < m; j++)
			before[i][j] = temp[j] - '0';
	}
	for (i = 0; i < n; i++) {
		cin >> temp;
		for (j = 0; j < m; j++)
			after[i][j] = temp[j] - '0';
	}

	// 연산 -> 가지고 있는 행렬과 바꿔야하는 행렬을 비교했을 때
	int res = 0;
	for (i = 0; i < n-2; i++) {
		for (j = 0; j < m-2; j++) {
			// 중심점을 기준으로 좌상단 값이 다르다면 행렬 뒤집기
			if (before[i][j] != after[i][j]) {
				res++;
				for (p = 0; p < 3; p++) {
					for (q = 0; q < 3; q++) {
						before[i + p][j + q] = 1 - before[i + p][j + q];
					}
				}
			}
		}
	}

	// 모든 연산이 끝났을 때 before과 after이 일치하지 않으면 -1 출력
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (before[i][j] != after[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", res);
	return 0;
}
