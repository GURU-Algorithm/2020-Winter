#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main() {
  int Pnum, Snum;
  cin >> Pnum;
  cin >> Snum;

  vector<int> snackArr(Snum);

  for(int i = 0; i < Snum; i++){
    cin >> snackArr[i];
  }
  
  sort(snackArr.begin(), snackArr.end());
  
  int start = 0, end = Snum-1, mid;
  int ans, cnt;

  // cout << snackArr[Snum-1]<< endl;

  while(start <= end){
    mid = (start+end)/2;
    cnt = 0;
    for(int i = 0; i < Snum; i++){
      cnt += snackArr[i]/mid; 
      //해당 과자를 mid로 나눈후의 몫 (받을수 있는 사람수)
    }
    if(cnt > Pnum){ //사람수보다 나눠준 과자가 더 많음.
      start = mid +1; //더 긴 과자를 나눠줄수 있는지 확인.
      ans = mid; 
    }
    else { // 사람수보다 나눠준 과자가 적음.
      end = mid -1; //더 짧은 과자를 나눠줘야 함.
    }
  }
  cout<< ans << endl;

}