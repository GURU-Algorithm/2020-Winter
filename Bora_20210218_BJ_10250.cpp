#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t; // 테스트 케이스
	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;
		int quo = n / h; // 몫
		int rem = n % h; // 나머지
		
		int floor = rem == 0 ? h: rem; // 층수
		int cell = rem == 0 ? quo : quo + 1; // 호수
		cout << floor * 100 + cell << endl;
	}
}
