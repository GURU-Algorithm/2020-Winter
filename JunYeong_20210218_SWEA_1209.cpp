#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	for (int test_case = 1; test_case <= 10; ++test_case) {
		cin >> n;

		vector<int> column(100);
		vector<int> row(100);
		vector<int> diagonal(2);

		int a;
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				cin >> a;
				row[i] += a;
				column[j] += a;

				if (i == j) diagonal[0] += a;
				if (i == 100 - j) diagonal[1] += a;
			}
		}

		sort(column.begin(), column.end());
		sort(row.begin(), row.end());
		sort(diagonal.begin(), diagonal.end());

		cout << "#" << test_case << " " << max(*(diagonal.end() - 1), max(*(column.end() - 1), *(row.end() - 1))) << endl;
	}

	return 0;
}
