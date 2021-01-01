#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, i;
	scanf("%d", &n);
	vector<int> N(2001);
	
	// 1. 입력 받으면 그 수에 1000을 더한 값에 해당하는 idx의 값을 1 증가
	for(i=1; i<=n; i++) {
		scanf("%d", &m);
		N[m + 1000]++;
	}
	
	// 2. 모든 index를 돌면서 값이 0이 아닌 index 출력
	// 2-1. 앞서 1000을 더한 값에 해당하는 index에 넣었으므로 1000을 빼준 값을 출력
	for(i = 0; i<=2000; i++) {
		if(N[i] != 0)
			printf("%d ", i - 1000);
	}
	
	return 0;
}
