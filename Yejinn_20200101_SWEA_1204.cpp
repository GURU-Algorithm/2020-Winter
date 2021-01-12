#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

  int tn; //test number

	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> tn;

    int scores[101] = {0}; 
    //0으로 초기화한,  0~100점 까지의 점수배열 (각 점수마다 몇명인지 세려고)

    for(int i = 0; i < 1000; i++){ //1000명의 학생의 정보 입력할거임.
      int score;
      cin >> score;
      scores[score] += 1; //해당 점수의 인원수 증가
    }

    int tmp = 0, ans;

    //위에서 부터 내려오면서, 가장 큰 숫자의 위치를 출력해야 함.
    for(int i = 100; i >= 0 ; i--){
      if(scores[i] > tmp){
        tmp = scores[i];
        ans = i;
      }
    }
    cout << "#" << tn << " "<< ans << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}