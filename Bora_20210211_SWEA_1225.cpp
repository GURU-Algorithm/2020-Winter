#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		queue<int> myQ;
		int tmp;
		cin >> tmp;
		for (int i = 0; i < 8; i++) {
			cin >> tmp;
			myQ.push(tmp);
		}

		int cur = 1;
		while (true)
		{
			tmp = myQ.front();
			myQ.pop();
			tmp -= cur;
			if (tmp <= 0) {
				myQ.push(0);
				break;
			}
			myQ.push(tmp);
			cur++;
			if (cur == 6) cur = 1;
		}

		cout << "#" << test_case << " ";
		while (!myQ.empty())
		{
			cout << myQ.front() << " ";
			myQ.pop();
		}
		cout << endl;
	}
	return 0;
}
