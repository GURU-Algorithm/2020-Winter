#include <iostream>
using namespace std;

int main()
{
	int T;
	int h, w, n;
	int floor, number;

	cin >> T;

	for(int i = 0; i < T; i++)
	{
		cin >> h;
		cin >> w;
		cin >> n;

		floor = n % h;
		number = n / h + 1;

		if (floor == 0) {
			floor = h;
			number -= 1;
		}

		cout << floor * 100 + number << endl;
	}

	return 0;
}
