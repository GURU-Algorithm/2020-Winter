#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ans, cnt = 0;
        string mystr, slicestr;
        cin >> mystr >> slicestr;

        int slicesize = slicestr.size();
        
        for(int k = 0; k < mystr.size(); k++){
            if(mystr.substr(k,slicesize) == slicestr) {
              cnt++;
              k+= (slicesize-1);
            }
		 		}
        ans = mystr.size() - (cnt*slicesize) + cnt;
        cout << "#" << test_case << " "<< ans << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}