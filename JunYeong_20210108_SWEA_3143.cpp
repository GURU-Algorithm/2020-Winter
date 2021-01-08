#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string A, B;
    cin >> A >> B;
    int i=0, res=0;
    int size_A = A.length();
    int size_B = B.length();
    
    while(1) {
    	int exist = A.find(B, i);
    	if(exist != string::npos) {
    		++res;
    		i = exist + size_B - 1;
			}
			else break;
		}
		res = size_A - res * size_B + res;
        printf("#%d %d\n", test_case, res);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
