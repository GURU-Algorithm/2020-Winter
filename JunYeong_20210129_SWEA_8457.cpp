#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int test_case, T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int N, B, E, clock, i;
		int res = 0;
		scanf("%d %d %d", &N, &B, &E);
		for (i = 0; i < N; i++) {
			scanf("%d", &clock);

			// 1. 모래시계로 계산한 시간이 오차범위 내에 있을 경우
			int time = (B / clock) * clock;
			// 2. 예외 케이스 : 구하려는 시간보다 모래시계로 잴 수 있는 시간의 범위가 클 때
			// 2-1. 모래시계로 구할 수 있는 시간이 오차범위 내에 있을 경우
			if (B - E <= time && time <= B + E || time + clock <= B + E)
				res++;
		}
		printf("#%d %d\n", test_case, res);
	}
	return 0;
}
