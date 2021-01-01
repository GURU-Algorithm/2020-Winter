#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int waste;
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> waste;
		vector<int> score(101); // 0점~100점
		int temp = 0;
		for (int i = 0; i < 1000; i++) {
			cin >> temp;
			score[temp]++;
		}

		int max = 0;
		for (int i = 1; i < score.size(); i++) {
			if (score[i] >= score[max])
				max = i;
		}

		cout << "# " << waste<< " " << max << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
