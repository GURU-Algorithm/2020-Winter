#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int str_int(string a){
  int ans = 0;
  for(int i = 0; i< a.size(); i++){
    if(isdigit(a[i])!=0){   
      //isdigit은 문자이면 0으로 출력된다.

      string tmp = a.substr(i,1);
      //숫자로 바꿔주는 과정에서, a[i]라고 하면 오류발생해서 tmp만듬.

      ans += atoi(tmp.c_str());
      //str을 숫자로 바꿔서 더해줌.
    }
  }
  return ans;
}

bool asc(string a, string b){
  if(a.size() < b.size()) return 1;
  else if ( a.size() > b.size()) return 0;

  //길이가 같으면 각자리 수의 합을 더해줘야 함.
  else{
    if(str_int(a) < str_int(b)) return 1;
    else if(str_int(a) > str_int(b)) return 0;
    else return a < b;
  }
}

int main() {
  int num;
  cin >> num;

  vector<string> mystring(num);

  for(int i = 0; i < num; i++){
    cin >> mystring[i];
  }
  
  sort(mystring.begin(), mystring.end(), asc);

  for(int i = 0; i <  num; i++){
    cout << mystring[i] << endl;
  }

}