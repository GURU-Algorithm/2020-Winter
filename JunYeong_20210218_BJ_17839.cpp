#include <iostream>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<string>> baba;
unordered_map<string, int> visit;
queue<string> word_queue;
set<string> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력받음
	int n, i;
	cin >> n;
	string p, is, q;
	for (i = 0; i < n; ++i) {
		cin >> p >> is >> q;
		baba[p].push_back(q);
	}

	// Baba 로부터 너비 우선 탐색
	word_queue.push("Baba");
	while (!word_queue.empty()) {
		string key = word_queue.front();
		word_queue.pop();

		// key word의 vector value 확인
		for (string word : baba[key]) {
			if (visit[word] != 0) continue; // vector value 속 단어를 한 번 이라도 방문했으면 pass -> 중복 검사 해결
			word_queue.push(word); 		     	// 한 번도 방문한 적이 없으면 word_queue에 추가해서 그 다음에 이어지는 값들 확인
      res.insert(word);               // result set에 단어 추가 (오름차순 정렬)
			visit[word]++;
		}
	}

	for (auto word : res) {
		cout << word << "\n";
	}
	
	return 0;
}
