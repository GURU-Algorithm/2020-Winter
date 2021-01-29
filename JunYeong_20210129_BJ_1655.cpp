#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, i, j, a;
	scanf("%d", &n);

	priority_queue<int, vector<int>, greater<int>> pq_min;
	priority_queue<int, vector<int>, less<int>> pq_max;
	for (i = 0; i < n; i++) {
        scanf("%d", &a);
		if (pq_max.size() == 0) pq_max.push(a);

		else {
			if (pq_min.size() == pq_max.size())	pq_max.push(a);
			else pq_min.push(a);

			if (pq_min.top() < pq_max.top()) {
				pq_max.push(pq_min.top());
				pq_min.pop();
				pq_min.push(pq_max.top());
				pq_max.pop();
			}
		}

		printf("%d\n", pq_max.top());
	}
	return 0;
}
