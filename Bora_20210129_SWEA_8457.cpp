#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, b, e;
		cin >> n >> b >> e;
		int result = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			int xdot = b % x;
			if (xdot <= e || x - xdot <= e)
				result++;
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
