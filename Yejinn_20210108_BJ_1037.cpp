#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int num;
  cin>> num;

  vector<int> nums;
  for(int i = 0; i < num; i++){
    int tmp;
    cin>>tmp;
    nums.push_back(tmp);
  }

  sort(nums.begin(), nums.end());

  int ans = nums[0] * nums[num-1];

  cout << ans;
}