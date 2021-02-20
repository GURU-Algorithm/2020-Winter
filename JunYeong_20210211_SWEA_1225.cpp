#include <queue>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
		for(int test_case=1; test_case<=10; ++test_case) {

				// test case, 암호화할 데이터 입력받기
				int n, i, a, temp;
        cin >> n;
        queue<int> encryption;
        for (i = 1; i <= 8; ++i) {
            cin >> a;
            encryption.push(a);
        }

				// 암호화 - 마지막 데이터가 0이되면 break하고 빠져나옴
        bool flag = true;
        while (flag) {
            for (i = 1; i <= 5; ++i) {
                temp = encryption.front();
                encryption.pop();

                if (temp - i <= 0) {
                    encryption.push(0);
                    flag = false;
                    break;
                }
                
                encryption.push(temp - i);
            }
        }

        cout << "#" << test_case << " ";
        for (i = 1; i <= 8; ++i) {
            cout << encryption.front() << " ";
            encryption.pop();
        }
        cout << endl;
		}
		return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
