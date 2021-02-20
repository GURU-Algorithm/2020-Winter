#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visited[14];
int comb[14];

void solution(int n, int s, int size) {
	if (size == 6) {
		for (int i = 0; i < n; ++i) {
			if (visited[i] == 1)
				cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}

	else {
		for (int i = s; i < n; ++i) {
			visited[i] = 1;
			solution(n, i + 1, size + 1);
			visited[i] = 0;
		}
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		int n, i;
		cin >> n;
		if (n == 0) break;

		for (i = 0; i < n; ++i) {
			cin >> comb[i];
			visited[i] = 0;
		}

		solution(n, 0, 0);
		cout << "\n";
	}

	return 0;
}
