#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, center, sum=0;
		cin >> n;
		center = n / 2;

		string temp;
		int i, j = 0, k;
		for (i = 0; i < n; ++i) {
			cin >> temp;

			if (i < center) {
				for (k = 0; k < n; ++k) {
					if (center - j <= k && k <= center + j)
						sum += temp[k] - '0';
				}
				++j;
			}

			else {
				for (k = 0; k < n; ++k) {
					if (center - j <= k && k <= center + j)
						sum += temp[k] - '0';
				}
				--j;
			}
		}

		printf("#%d %d", test_case, sum);
	}

	return 0;
}
