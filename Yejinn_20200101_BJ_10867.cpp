#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  int num;
  cin >> num;

  vector<int> inputvec(num-1);

  for(int i  = 0; i < num; i++){
    cin >> inputvec[i];
  }

  sort(inputvec.begin(), inputvec.end());

  set<int> finalset;

  for(int i = 0; i < num; i++){
    finalset.insert(inputvec[i]);
  }

  set<int>::iterator iter;
  for(iter = finalset.begin(); iter != finalset.end(); iter++){
    cout << *iter << " " ;
  }    
  cout << endl;  

}