#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int> smaller; // 중간값보다 작은 숫자들 저장 , Max Heap
	priority_queue<int, vector<int>, greater<int>> bigger; // 중간값보다 큰 숫자들 저장 , Min Heap
    int number; 
    scanf("%d", &number);
    smaller.push(number);
    cout << number << endl;
	for (int i = 1; i < n; i++) {
        scanf("%d", &number);
        if (number < smaller.top()) smaller.push(number);
        else bigger.push(number);

        if (smaller.size() < bigger.size()) {
            smaller.push(bigger.top());
            bigger.pop();
        }
        else if (smaller.size() > bigger.size() + 1) {
            bigger.push(smaller.top());
            smaller.pop();
        }
        printf("%d\n", smaller.top());
	}
}
