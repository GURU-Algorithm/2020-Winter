#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n, m, cnt = 0;
  cin>> n >> m ;
  
  vector<pair<int,int>> vec(m);
  set<int> finalfriend;
  vector<int> myfriend;

  for(int i = 0; i < m ; i++){
    cin >> vec[i].first>> vec[i].second ;

    if(vec[i].first == 1) {
      myfriend.push_back(vec[i].second); //상원이 친한친구목록 X
      finalfriend.insert(vec[i].second); //초대친구목록 X
    }
    else if(vec[i].second == 1) {
      myfriend.push_back(vec[i].first); //상원이 친한친구목록 X
      finalfriend.insert(vec[i].first); //초대친구목록 X
    }
  }

  if(myfriend.size() !=0 ){ //상원이가 초대장 줄 친구가 있음.
    for(int i = 0; i < myfriend.size(); i++){
      for(int j = 0; j < m; j++){
        if(myfriend[i] == vec[j].first && 1!=vec[j].second){
          finalfriend.insert(vec[j].second);
        }
        else if(myfriend[i]== vec[j].second && 1!=vec[j].first){
          finalfriend.insert(vec[j].first);
        }
      }
    }
    cnt = finalfriend.size();
  }

  cout << cnt << endl << endl;

    set<int>::iterator iter;
    for(iter = finalfriend.begin(); iter != finalfriend.end(); iter++){
        cout << *iter << " " ;
    }
    cout << endl;

}