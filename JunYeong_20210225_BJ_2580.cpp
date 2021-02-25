#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct Point {
	int x, y;
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

int sudoku[9][9];
vector<Point> zeroLoc;

int rowCheck(int x) {
	int cnt[10] = { 0 };
	for (int i = 0; i < 9; ++i) {
		if (sudoku[x][i] != 0) cnt[sudoku[x][i]]++;
		if (cnt[sudoku[x][i]] >= 2) return 0;
			
	}	
	return 1;
}

int columnCheck(int y) {
	int cnt[10] = { 0 };
	for (int i = 0; i < 9; ++i) {
		if (sudoku[i][y] != 0) cnt[sudoku[i][y]]++;
		if (cnt[sudoku[i][y]] >= 2) return 0;
	}
	return 1;
}

int squareCheck(int x, int y) {
	int cnt[10] = { 0 };
	int rowRange = (x / 3) * 3;
	int columnRange = (y / 3) * 3;

	for (int i = rowRange; i < rowRange + 3; ++i) {
		for (int j = columnRange; j < columnRange + 3; ++j) {
			if (sudoku[i][j] != 0) cnt[sudoku[i][j]]++;
			if (cnt[sudoku[i][j]] >= 2) return 0;
		}
	}
	return 1;
}

void solution(int size) {
	// 기저 사례
	if (size == zeroLoc.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	// 일반 사례
  Point zero = zeroLoc.at(size);
  for (int j = 1; j <= 9; j++) {
      sudoku[zero.x][zero.y] = j;
      if (rowCheck(zero.x) && columnCheck(zero.y) && squareCheck(zero.x, zero.y)) {	
          solution(size + 1);
      }
      sudoku[zero.x][zero.y] = 0;
  }
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int i, j;
	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) zeroLoc.push_back(Point(i, j));
		}
	}

	solution(0);
	return 0;
}
