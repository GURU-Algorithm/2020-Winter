#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int ans = 0;
	/* Get init value */
	int T;	cin >> T;

	int n;	cin >> n;

	int a[1000]; 
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int m;	cin >> m;

	int b[1000];
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	/* 각 배열의 부배열 합 구하기 */
	vector<int> sumA;
	vector<int> sumB;

	for (int i = 0; i < n; i++)
	{
		int sum = a[i];
		sumA.push_back(sum); // 원소 하나도 부배열의 합

		for (int j = i+1; j < n; j++)
		{
			sum += a[j];
			sumA.push_back(sum);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int sum = b[i];
		sumB.push_back(sum); // 원소 하나도 부배열의 합

		for (int j = i + 1; j < n; j++)
		{
			sum += a[j];
			sumB.push_back(sum);
		}
	}

	sort(sumB.begin(), sumB.end());

	/* 이분탐색 */
	for (int i = 0; i < sumA.size(); i++)
	{
		bool bfind = false;
		int find = T - sumA[i];
		int left = 0, right = m - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (b[mid] > find) right = mid - 1;
			else if (b[mid] < find) left = mid + 1;
			else
			{
				bfind = true;
				break;
			}
		}
		if (bfind == true) ans++;

	}
	
	cout << ans << endl;
	return 0;
}
