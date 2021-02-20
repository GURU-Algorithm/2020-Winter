#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;

map<string, vector<string>> cmds;
set<string> results;

void Search(string key) {
	if (cmds.find(key) == cmds.end()) return;
	string value;
	for (int i = 0; i < cmds[key].size(); i++) {
		value = cmds[key][i];
		if (results.find(value) != results.end()) continue;
		results.insert(value);
		cout << value << endl;
		Search(value);
	}
}


int main() 
{
	int n; // 전체 명령의 수
	cin >> n;

	string p, is, q;
	for (int i = 0; i < n; i++) {
		cin >> p >> is >> q;
		if (cmds.find(p) == cmds.end()) cmds[p] = vector<string>();
		cmds[p].push_back(q);
	}

	Search("Baba");

	return 0;
}
