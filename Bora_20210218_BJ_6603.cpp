#include<iostream>
#include<vector>
using namespace std;

void Combination(vector<int> arr, vector<int> comb, int index, int depth)
{
    if (depth == comb.size())
    {
        for (int i = 0; i < comb.size(); i++)
            cout << comb[i] << " ";
        cout << endl;

        return;
    }
    else
    {
        for (int i = index; i < arr.size(); i++)
        {
            comb[depth] = arr[i];
            Combination(arr, comb, i + 1, depth + 1);
        }
    }
}


int main() 
{
    int k;
    vector<int> comb(6);
	while (true)
	{
		cin >> k;
		if (k == 0) break;
        vector<int> nums(k);
        for (int i = 0; i < k; i++) cin >> nums[i];
        Combination(nums, comb, 0, 0);
        cout << endl;
	}
}
