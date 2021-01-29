#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		int totalStickCnt = 0;
		int curStickCnt = 0;
		int result = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') { // stick이나 레이저의 시작
				curStickCnt++;
				totalStickCnt++;
			}
			else if (str[i] == ')') { // stick이나 레이저의 종료
				curStickCnt--;
				if (str[i - 1] == '(') { // 레이저로 자르기
					totalStickCnt--;
					result += curStickCnt;
				}
			}
		}
		result += totalStickCnt;
		cout << '#' << test_case << ' ' << result << endl;
	}
	return 0;
}
