#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct cmp {
	bool is_int(char a) {
		int code = (int)a;
		return a >= 48 && a <= 57; // 아스키코드
	}

	// true면 a와b가 위치를 swap
	bool operator()(string a, string b) {
		if (a.length() != b.length()) // 길이가 다르면 짧은 것이 먼저온다.
			return a.length() > b.length();

		// 길이가 같다면
		int sumA = 0, sumB = 0;
		for (int i = 0; i < a.length(); i++){
			if (is_int(a[i])) sumA += (a[i] - '0');
			if (is_int(b[i])) sumB += (b[i] - '0');
		}
		if (sumA != sumB)
			return sumA > sumB; // 각 자리수의 숫자의 합이 작은 것이 먼저온다

		// 숫자의 합이 같다면 사전순
		for (int i = 0; i < a.length(); i++) {
			return (int)a[i] > (int)b[i];
		}

		return true;
	}
};

int main()
{
	int n; cin >> n;
	string* a = new string[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	priority_queue<string, vector<string>, cmp> myQ;
	for (int i = 0; i < n; i++)
		myQ.push(a[i]);

	while (!myQ.empty())
	{
		cout << myQ.top() << endl;
		myQ.pop();
	}
}
