#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{

  int n, b, e, ans=0;
  cin>> n >> b>> e; //n개 모래시계, b-e ~ b+e 사이의 값을 측정해야 함.
  vector<int> vec;
  int cnt = 0; //범위벗어나는거 구하려고

  for(int i = 0; i < n; i++){
    int sec;
    cin >> sec;

    int k = 0;
    while(1){
      k++;
      int tmp = sec*k;

      if(tmp < b-e) continue;
      else if(tmp >= b-e  && tmp <= b+e){
        ans++;
        break;
      }
      else if(tmp > b+e){
        cnt++;
        break; //범위 초과했음.
      }
    }
  }

  if(cnt == n) { //모든수가 이미 초과했음.
    ans = 0;
  }

cout << "#" << test_case << " "<<  ans<< "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}