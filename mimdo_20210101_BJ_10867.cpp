#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int num, input;
	vector<int> arr;
	set<int> answer;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> input;
		arr.push_back(input);
	}

	for (int i : arr)
	{
		answer.insert(i);
	}

	for (int i : answer)
	{
		cout << i << " ";
	}
	cout << endl;


	return 0;

}
