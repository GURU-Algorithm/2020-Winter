#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
									// ��������
	priority_queue<int, vector<int>, less<int>> smaller;	// �ִ񰪿� �ٷ� ����... ���غ��� ���� �ֵ�
	priority_queue<int, vector<int>, greater<int>> bigger;	// �ּڰ��� �ٷ� ����... ���غ��� ū �ֵ�
									// ��������

	int num;
	cin >> num;

	int input;	// ù��° ����
	cin >> input;
	cout << input;
	smaller.push(input);

	// �ι�° ��������
	for (int i = 0; i < num-1; i++)
	{
		cin >> input;
		if (input < smaller.top())	// input�� ���غ��� ���� ���
			smaller.push(input);	// smaller�� input�� ����

		else						// input�� ���غ��� ũ�ų� ���� ���
			bigger.push(input);		// bigger�� input�� ����


		//  smaller�� ũ��� bigger�� ũ�Ⱑ ���ų�, smaller�� ũ�Ⱑ �ϳ� �� ũ�� �����ǵ��� �����͸� �ű��.
		if (smaller.size() < bigger.size())	// bigger.size�� �� ũ��
		{
			smaller.push(bigger.top());		// bigger�� top(���������̹Ƿ� ���� ���� ����)�� ���ذ����� �ְ�
			bigger.pop();					// pop ���ش�
		}

		else if (smaller.size() > bigger.size() + 1) // ����ġ�� �����ؼ� smaller size�� �� ũ��
		{
			bigger.push(smaller.top());
			smaller.pop();
		}

		cout <<smaller.top() << endl;
	}

	return 0;
}