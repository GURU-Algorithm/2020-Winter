#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
									// 오름차순
	priority_queue<int, vector<int>, less<int>> smaller;	// 최댓값에 바로 접근... 기준보다 작은 애들
	priority_queue<int, vector<int>, greater<int>> bigger;	// 최솟값에 바로 접근... 기준보다 큰 애들
									// 내림차순

	int num;
	cin >> num;

	int input;	// 첫번째 정수
	cin >> input;
	cout << input;
	smaller.push(input);

	// 두번째 정수부터
	for (int i = 0; i < num-1; i++)
	{
		cin >> input;
		if (input < smaller.top())	// input이 기준보다 작은 경우
			smaller.push(input);	// smaller에 input을 넣음

		else						// input이 기준보다 크거나 같은 경우
			bigger.push(input);		// bigger에 input을 넣음


		//  smaller의 크기와 bigger의 크기가 같거나, smaller의 크기가 하나 더 크게 유지되도록 데이터를 옮긴다.
		if (smaller.size() < bigger.size())	// bigger.size가 더 크면
		{
			smaller.push(bigger.top());		// bigger의 top(내림차순이므로 가장 작은 값임)을 기준값으로 넣고
			bigger.pop();					// pop 해준다
		}

		else if (smaller.size() > bigger.size() + 1) // 기준치를 포함해서 smaller size가 더 크면
		{
			bigger.push(smaller.top());
			smaller.pop();
		}

		cout <<smaller.top() << endl;
	}

	return 0;
}