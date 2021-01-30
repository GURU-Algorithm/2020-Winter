#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		int answer = 0;
		int stick = 0;
		string input;
		cin >> input;


		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == ')')
			{
				if (input[i - 1] == '(')
				{
					stick--;	// 앞에 있던 '('는 stick이 아니고 레이저니까
								// 하나 뺴주고
					answer += stick; // stick 갯수 만큼 더해줌
				}
				else
				{
					stick--;	// stick 중 하나를 빼주고
					answer += 1; // 조각으로 하나 더해줌
				}
			}
			else {			// '('가 나오면
				stick++;	// 막대기 갯수 ++
			}
		}

		cout << '#' << test_case << " " << answer << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}