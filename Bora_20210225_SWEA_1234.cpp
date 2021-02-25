#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int n; cin >> n;
		string tmp; cin >> tmp;
		vector<char> password;
		for (int i = 0; i < n; i++) {
			if (password.size() > 0 && tmp[i] == password[password.size() - 1]) password.pop_back();
			else password.push_back(tmp[i]);
		}
		cout << "#" << test_case << " ";
		for (char elem : password)
			cout << elem;
		cout << endl;
	}
	return 0;
}
