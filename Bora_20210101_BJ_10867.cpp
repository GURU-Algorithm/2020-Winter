#include <iostream>
#include <set>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	set<int> s; // 집합에 추가, 추가되면 자동 오름차순 정렬
	for(int i = 0; i < n; i++)
		s.insert(a[i]);
	for (auto i = s.begin(); i != s.end(); i++)
		cout << *i << " ";
}
