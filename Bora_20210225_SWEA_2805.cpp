#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int result = 0;
		int mid = n / 2;  

		int cnt = 1;
		string tmp;
		for (int i = 0; i < n; i++) { 
			cin >> tmp;
			for (int j = 0; j < n; j++) {
				if (j > mid - cnt && j < mid + cnt)
					result += tmp[j] - '0';
			}
			if (i < mid) cnt++;
			else cnt--;
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
