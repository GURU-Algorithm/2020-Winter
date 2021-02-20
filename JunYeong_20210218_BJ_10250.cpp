#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int h, w, n;
		cin >> h >> w >> n;

		int floor = 0, room_num = 1;
		while (true) {
			if (n <= h) break;
			n -= h;
			room_num++;
		}
		floor += n;

		string res = to_string(floor);
		if (room_num >= 10) res += to_string(room_num);
		else res += ("0" + to_string(room_num));
		cout << res << "\n";
	}

	return 0;
}
