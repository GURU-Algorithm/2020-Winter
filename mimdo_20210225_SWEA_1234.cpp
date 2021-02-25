#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int num;
 
    string password;
    int count;
    for (int test_case = 1;test_case <= 10;test_case++)
    {
        cin >> num >> password;
        count = 0;
 
        for (int i = 1; i < password.length(); i++)
        {
            while (password[i - 1] == password[i]) 
						{
                password.erase(i - 1, 2);
                i -= 1; // erase하면 length가 2 줄어드니까
												// i를 1 빼줌
            }
        }
         
         
        cout << "#" << test_case << " " << password << endl;
    }
    return 0;
}
