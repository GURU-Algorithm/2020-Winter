#include <iostream>

using namespace std;

bool recursion(int init_sand, int target, int mult_sand);

int main()
{
	int test_case;
	cin >> test_case;
	
	for (int tc = 1; tc <= test_case; tc++)
	{
		/***************/
		int sandNum = 0;		// 모래시계 갯수
		int b = 0;				// 정확한 값
		int e = 0;				// 오차
		cin >> sandNum >> b >> e;
		int cnt = 0;			// count
		int sand[100];			// 상점에 있는 모래시계 수
		for (int i = 0; i < sandNum; i++)
		{
			cin >> sand[i];
		}
		/***************/


		for (int i = 0; i < sandNum; i++)
		{
			int target = b - e;		// 오차 범위 내 수
			for (int j = 0; j < e * 2 + 1; j++)
			{	
				//	cout << "========================" << endl;
				//	cout << "target = " << target << endl;
				//	cout << "sand[" << i << "] = " << sand[i] << endl;
				//	cout << "========================" << endl;
				if (recursion(sand[i], target, sand[i]))
				{
					cnt++;
					break;
				}
				else
				{
					target++;
				}
			}
		}

		cout << '#' << tc <<" " <<  cnt << endl;
	}

	return 0;
}


bool recursion(int init_sand, int target, int mult_sand)
{
	if (mult_sand > target)
		return false;
	else if (mult_sand == target)
		return true;
	else
		recursion(init_sand, target, mult_sand + init_sand);
}