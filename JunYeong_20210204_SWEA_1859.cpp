#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	int test_case, T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, a, i;
		vector<int> market;
		scanf_s("%d", &n);
		for (i = 0; i < n; i++) {
			scanf_s("%d", &a);
			market.push_back(a);
		}

		// 뒤에서부터 시장 가격 보기
		int market_price = *(market.end() - 1);
		long long res = 0;
		for (i = n - 2; i >= 0; --i) {
			
			// 이전의 시세가 오늘의 시세보다 적으면 그 날 물건을 사서 오늘 되팔기
			if (market_price > market[i]) {
				res += market_price - market[i];
			}

			// 이전의 시세가 같거나 더 비싸다면 시세 새롭게 초기화
			else {
				market_price = market[i];
			}
		}
		printf("#%d %lld\n", test_case, res);
	}

	return 0;
}
