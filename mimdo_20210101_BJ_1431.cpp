#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;


int main()
{
	int num, idx;
	string input, tmp;
	vector<string> vec;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> input;
		vec.push_back(input);
	}


	// 1. 사이즈 별로 정렬 : A, B 의 길이가 다르면 짧은 것이 먼저 온다.
	for (int i = 0; i < num - 1; i++)
	{
		idx = i;
		for (int j = i + 1; j < num; j++)
		{
			if (vec[j].size() < vec[idx].size()) idx = j;
		}
		tmp = vec[i];
		vec[i] = vec[idx];
		vec[idx] = tmp;
	}

	cout << "--------------------------------------" << endl;
	for (string i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	// 2. 사이즈가 같다면 - A의 모든 자리수 합과 B의 모든 자리수 합을 비교해서
	//	  작은 합을 가지는 것이 먼저 온다. (숫자인 것만 더한다)
	for (int i = 0; i < num - 1; i++)
	{
		int sum1 = 0, sum2 = 0;
		if (vec[i].size() == vec[i + 1].size())
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				
				if (isdigit(vec[i][j]))
				{
					//cout << "sum1 : " << sum1 << endl;
					//cout << "vec[i][j] : " << vec[i][j] << endl;
					sum1 += vec[i][j] % 48;
					//cout << "sum1 : " << sum1<<endl;
					
				}
				
				
			}
			for (int j = 0; j < vec[i+1].size(); j++)
			{
				if (isdigit(vec[i+1][j]))
				{
					//cout << "vec[i+1][j] : " << vec[i+1][j] << endl;
					sum2 += vec[i + 1][j] % 48;
				}
				
			}

			cout << vec[i] << " = " << sum1<<endl;
			cout << vec[i+1] << " = " << sum2<<endl;
			
			if (sum1 > sum2)
			{
				swap(vec[i], vec[i + 1]);
			}
			// 3. 만약 1, 2 번 조건으로도 비교할 수 없으면, 사전 순 정렬
			else if (sum1 == sum2)
			{
				if (vec[i] > vec[i + 1])	 swap(vec[i], vec[i + 1]);
			}

			
		}
	}







	cout << "--------------------------------------" << endl;
	for (string i : vec)
	{
		cout << i << " ";
	}
	cout << endl;


	return 0;
	
}

// 고쳐야해요ㅠㅠ
