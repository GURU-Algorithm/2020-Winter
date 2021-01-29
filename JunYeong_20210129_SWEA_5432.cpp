#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		char input[100000];
		scanf("%s", &input);

		int res = 0, tmp = 0;
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] == '(') ++tmp;

			else {
				// 알고보니 레이저인 경우
				if (input[i - 1] == '(' && input[i] == ')') {
					--tmp;
					res += tmp;
				}

				// 쇠막대기 조각인 경우
				else {
					--tmp;
					++res;
				}
			}
		}

		printf("#%d %d\n", test_case, res);
	}
	return 0;
}
