#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int i, n, N[51], res;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &N[i]);
	sort(N, N+n);
	printf("%d", N[1] * N[n]);
	return 0;
}
