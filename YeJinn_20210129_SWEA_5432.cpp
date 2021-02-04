#include<iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
  int cnt=0;
  string mystr;
  cin >> mystr;

  stack<int> S;

  for(int i = 0; i < mystr.size(); i++){
    string tmp, ttmp;
    tmp = mystr[i];
    ttmp = mystr[i-1];
    
    if(tmp == "("){
      S.push(i); // 막대기의 시작 위치를 저장
    }
    else {
      if(ttmp == "(" ){  // () 연결된거는 자르는 부분임.
        S.pop(); // ( 를 빼냈음. == 레이저 끊어냈음.
        cnt += S.size(); //막대기 갯수만큼 더함.
      }
      else{ //막대기 부분임.
        S.pop(); //막대기 꺼냈고,
        cnt++; //맨끝조각 더함.
      }
    }
  }

cout << "#" << test_case << " "<<  cnt << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}