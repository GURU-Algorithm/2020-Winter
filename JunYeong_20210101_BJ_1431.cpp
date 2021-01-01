// Bubble Sort
#include <iostream>
#include <string>
using namespace std;

string S[1001];
int main() {
	int n, i, j, l;
	string tmp;

	cin >> n;
	for (i = 1; i <= n; i++) cin >> S[i];

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++) {

			// 1. size 비교
			if (S[j].size() > S[j + 1].size()) {
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}

			else if (S[j].size() == S[j + 1].size()) {

				// 2. 숫자 합 비교
				int sum1 = 0, sum2 = 0;
				for (l = 0; l < S[j].size(); l++) {
					if (S[j][l] - '0' >= 0 && S[j][l] - '0' <= 9) sum1 += (S[j][l] - '0');
					if (S[j + 1][l] - '0' >= 0 && S[j + 1][l] - '0' <= 9) sum2 += (S[j + 1][l] - '0');
				}

				if (sum1 > sum2) {
					tmp = S[j];
					S[j] = S[j + 1];
					S[j + 1] = tmp;
				}

				else if (sum1 == sum2) {

					// 3. 사전 순 정렬
					for (l = 0; l < S[j].size(); l++) {
						int tmp1, tmp2;
						if (S[j][l] - '0' >= 0 && S[j][l] - '0' <= 9) tmp1 = (S[j][l] - '0');
						else tmp1 = S[j][l];
						if (S[j + 1][l] - '0' >= 0 && S[j + 1][l] - '0' <= 9) tmp2 = (S[j + 1][l] - '0');
						else tmp2 = S[j + 1][l];

						if (tmp1 > tmp2) {
							tmp = S[j];
							S[j] = S[j + 1];
							S[j + 1] = tmp;
							break;
						}

						else if (tmp1 < tmp2) 
							break;
					}
				}
			}
		}
	}


	for (i = 1; i <= n; i++) {
		cout << S[i] << endl;
	}
	return 0;
}
