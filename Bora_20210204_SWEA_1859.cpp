#include<iostream>
using namespace std;

long long price[1000000];
int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
		long long result = 0;
		for (int i = 0; i < n; i++)
			cin >> price[i];
		int max = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (price[i] < max) result += max - price[i];
			else max = price[i];
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
