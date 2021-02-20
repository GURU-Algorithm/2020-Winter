#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int n;
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> n;
		vector<int> sums(202); // 0~99 가로합 100~199 세로합 200 ↘ 201 ↙
		int tmp;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> tmp;
				sums[i] += tmp;
				sums[100+j] += tmp;
				if (i == j) sums[200] += tmp;
				if (i + j == 99) sums[201] += tmp;
			}
		}
		sort(sums.begin(), sums.end());
		cout << "#" << test_case << " " << sums[sums.size() - 1] << endl;
	}
	return 0;
}
