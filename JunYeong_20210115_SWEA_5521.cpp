// 플루이드 알고리즘 -> 시간 초과 발생 (시간복잡도 O(n^3))
#include <iostream>
using namespace std;

int main() {
	freopen("in1.txt", "rt", stdin);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int i, j, k, n, m, p, q, map[500][500]={0};
		scanf("%d %d", &n, &m);
		for(i=0; i<m; i++) {
			scanf("%d %d", &p, &q);
			map[p-1][q-1] = map[q-1][p-1] = 1;
		}
		
		for(k=0; k<n; k++) {
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
					if(i==j) continue;
					if(map[i][k] == 1 && map[k][j] == 1) {
						if(map[i][j] == 0)
							map[i][j] = map[j][i] = 2;
					}
				}
			}
		}
		
		int sum=0;
		for(i=0; i<n; i++) {
			if(map[0][i] != 0) sum++;
		}
		printf("#%d %d\n", test_case, sum);
	}
	return 0;
}


/**********************/
// 통과 -> 시간복잡도 O(n^2)
#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int i, j, k, n, m, p, q, map[500][500]={0};
		scanf("%d %d", &n, &m);
		for(i=0; i<m; i++) {
			scanf("%d %d", &p, &q);
			map[p-1][q-1] = map[q-1][p-1] = 1;
		}
		
		// DFS로 첫번째 사람과 두 번 연결되어 있는 경우의 수만 구함
		for(i=0; i<n; i++) {
			if(map[0][i]==1) {
				for(j=0; j<n; j++) {
					if(i==j || j==0) continue;
					else if(map[i][j]==1 && map[0][j]==0) {
						map[0][j] = 2;
					}
				}
			}
		}
		
		int sum=0;
		for(i=0; i<n; i++) {
			if(map[0][i] != 0) sum++;
		}
		printf("#%d %d\n", test_case, sum);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
