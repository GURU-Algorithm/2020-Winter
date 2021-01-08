// 괄호의 결합관계로 묶여 있는 수식을 길게 풀어서 생각하는 것이 관건.
// ex) (() [[]]) ([]) = 2*(2 + 3*3) + 2*3 = 2*2 + 2*3*3 + 2*3
// 1-1. stack에 (를 추가해야 하는 경우, tmp에 2를 곱함
// 1-2. stack에 [를 추가해야 하는 경우, tmp에 3을 곱함

// 2. stack에서 빼와야 하는 경우 (닫힌 괄호)
// 2-1. stack에 남은게 없으면 error
// 2-2. ()로 matching되는 경우, tmp로 쌓아올린 값을 res에 모두 더한다.
// 2-2-1. 괄호가 바로 matching 되었기 때문에 이후 들어오는 값은 matching된 괄호와 따로 생각해야 한다.
// 2-2-2. '('괄호가 들어오면서 2를 곱했기 때문에, matching된 이후에는 2로 나눠준다.
// 2-3. 2-2와 동일하다. []로 matching되는 경우, res에 모두 더한다.
// 2-3-1. 다만 []로 matching되지 않고 ]]이거나 )]인 경우, 결과값을 모두 더한 상태이므로 3으로 나눠주기만 한다.
// 2-4. 괄호가 matching 되지 않으면 error

// 3. stack이 비어있으면 완성된 괄호이므로 결과값을 출력한다.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

char a[31];
int main() {
	stack<char> s;
	scanf("%s", &a);
	int res = 0, i, tmp = 1;

	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == '(') {
			tmp *= 2;
			s.push(a[i]);
		}
		else if (a[i] == '[') {
			tmp *= 3;
			s.push(a[i]);
		}

		
		else {
			if (s.empty()) {
				printf("0");
				return 0;
			}

			if (s.top() == '(' && a[i] == ')') {
				if (a[i - 1] == '(') res += tmp;
				tmp /= 2;
				s.pop();
			}

			else if (s.top() == '[' && a[i] == ']') {
				if (a[i - 1] == '[') res += tmp;
				tmp /= 3;
				s.pop();
			}

			else {
				printf("0");
				return 0;
			}
		}
	}
	
	if(!s.empty()) printf("0");
	else printf("%d", res);
	return 0;
}
