#include <iostream>
#include <queue>
using namespace std;

int main() {

	for (int i = 0; i < 10; i++)
	{
		int now;
		cin >> now;

	int number[9];
	int cnt = 1;
	int value;

	queue<int> q;

	for (int i = 0; i < 8; i++)
	{
		cin >> value;
		q.push(value);
	}

	while (true)
	{
		if (cnt > 5)
		{
			cnt = 1;
		}

		int x = q.front();
		q.pop();

		x -= cnt;
		
	

		if (x <= 0)
		{
			x = 0;
			q.push(x);
			break;
		}

		else
		{
			q.push(x);
		}

		cnt++;


	}

	cout << "#" << now <<" ";
	while (!q.empty()) {

		int tmp = q.front();

		cout << tmp << " ";



		q.pop();

	}


	
	cout << endl;
	}

	return 0;

}
