//테스트케이스는 돌아가는데 틀렸어요 ㅠㅠ
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> map(m,vector<int>(n,0));

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n ; j++){
      cin >> map[i][j];
    }
  }

  int dxy[3][2]={{-1,1},{0,1},{1,1}};//오른쪽방향 세칸만 비교
  int cnt = 0;
  vector<int> none;

  for(int i = 0; i < m ; i++){
    int flag = 0;

    for(int j = 0; j < n ; j++){
      if(map[i][j]==1){ //1일때 세칸확인

        for(int k = 0; k <3; k++){
          if(i+dxy[k][0] > 0 && i+dxy[k][0] < m && j+dxy[k][1]>0 && j+dxy[k][1]<n){
            if(map[i+dxy[k][0]][j+dxy[k][1]] == 1) flag = 1; 
          }
        }
      }
    }

    if(flag == 0){
    //옆칸으로 이어지는게 없다는 말임.
    none.push_back(i);
    }
  }

  for(int i = 0; i < none.size(); i++){
    if(none[i]-none[i+1] < -1) cnt++;
  }

  cout << cnt;
}