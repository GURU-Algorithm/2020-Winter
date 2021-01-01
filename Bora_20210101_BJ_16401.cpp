#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m; cin >> m; // 조카수
	int n; cin >> n; // 과자수

	vector<int> snack(n); // 과자의 길이를 저장하는 벡터
	int max = 0; // 가장 긴 과자의 길이
	for (int i = 0; i < n; i++)
	{
		cin >> snack[i];
		if (snack[i] > max) max = snack[i];
	}

	int min = 1;
	int mid = 0;
	int optimal = 0;
	int temp = 0;
	while (min <= max)
	{
		mid = (min + max) / 2;
		temp = 0;

		for (int i = 0; i < n; i++)
			temp += snack[i] / mid;

		if (temp >= m) { // 과자수가 애들 수 보다 많으면
			optimal = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}

	cout << optimal;
}
