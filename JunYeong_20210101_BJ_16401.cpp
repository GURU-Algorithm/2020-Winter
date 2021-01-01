// Binary Search
#include<iostream>
using namespace std;

int main() {
	long long n, m;
	long long i, lt = 1, rt = 0, mid, cnt = 0, res = 0;
	scanf("%lld %lld", &n, &m);
	long long* N = new long long[m];
	
	// 가장 큰 수로 rt 초기화
	for (i = 0; i < m; i++) {
		scanf("%lld", &N[i]);
		if (rt <= N[i]) rt = N[i];
	}

	while (lt <= rt) {
		mid = (lt + rt) / 2;
		cnt = 0;
		
		// 나눠줄 수 있는 과자의 수
		for (i = 0; i < m; i++) {
			if (N[i] >= mid)
				cnt += N[i] / mid;
		}
		
		// 인원 수보다 많이 나눠 줄 수 있으면 정답으로 초기화 하고 lt를 1 증가시켜 확인
		if (cnt >= n) {
			res = mid;
			lt = mid + 1;
		}

		// 인원 수보다 적은 경우 과자를 더 작게 나눔
		else if (cnt < n) {
			rt = mid - 1;
		}
	}

	printf("%lld", res);
	delete[] N;
	return 0;
}
