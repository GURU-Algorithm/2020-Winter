#include <iostream>
#include <vector>
using namespace std;

int map[9][9];
vector<pair<int, int>> zero;
bool row[9][10] = { false };
bool col[9][10] = { false };
bool cell[9][10] = { false };

void DFS(int idx) {
	if (idx == zero.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << " ";
			cout << endl;
		}
		exit(0);
	}

	else {
		pair<int, int> front = zero[idx];
		int i = front.first, j = front.second;
		for (int k = 1; k <= 9; k++) {
			if (row[i][k] || col[j][k] || cell[(i / 3) * 3 + j / 3][k]) continue;
			map[i][j] = k;
			row[i][k] = col[j][k] = cell[(i / 3) * 3 + j / 3][k] = true;
			DFS(idx+1);
			row[i][k] = col[j][k] = cell[(i / 3) * 3 + j / 3][k] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 0) zero.push_back(make_pair(i, j));
			else row[i][tmp] = col[j][tmp] = cell[(i / 3) * 3 + j / 3][tmp] = true;
		}
	}
	DFS(0);
	return 0;
}
