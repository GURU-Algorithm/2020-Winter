#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
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
					stick--;	// �տ� �ִ� '('�� stick�� �ƴϰ� �������ϱ�
								// �ϳ� ���ְ�
					answer += stick; // stick ���� ��ŭ ������
				}
				else
				{
					stick--;	// stick �� �ϳ��� ���ְ�
					answer += 1; // �������� �ϳ� ������
				}
			}
			else {			// '('�� ������
				stick++;	// ����� ���� ++
			}
		}

		cout << '#' << test_case << " " << answer << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}