#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main() {
  string mystr = "(()[[]])([])";

  int cnt1=0, cnt2=0, ans=0;

  char str1[] = "()";
  char str2[] = "[]";
  
  int tmp = 1;

  for(int i = 0; i < mystr.size(); i++){
    if(mystr[i]==str1[0]) {
      tmp = tmp*2;
      cnt1 ++;
    }
    else if(mystr[i]==str1[1]) {
      if(mystr[i-1] == str1[0]) ans += tmp; //제일 안쪽 괄호일때만 더해줌.
      cout << "()"<<ans << endl;
      tmp = tmp/2;
      cnt1--; //열린괄호 하나 닫았음.
    }
    else if(mystr[i]==str2[0]) {
      tmp = tmp*3;
      cnt2++;
    }
    else if(mystr[i]==str2[1]){
      if(mystr[i-1] == str2[0]) ans += tmp;
      cout << "[]"<<ans << endl;
      tmp = tmp/3;
      cnt2--;
    }
  }

  if((cnt1 == 0) &&(cnt2 == 0)) cout << ans;
  else cout << 0;
}