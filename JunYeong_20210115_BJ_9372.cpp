// 가중치가 1이기 때문에 크루스칼 알고리즘을 사용할 필요없이 간선의 개수만 구해주면 됨
// 상근이가 여행할 비행기의 "종류"만 구하는 것이기 때문
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int i, n, m, p, q;
		scanf("%d %d", &n, &m);
		for(i=0; i<m; i++) scanf("%d %d", &p, &q);
		printf("%d\n", n-1);
	}
	return 0;
}

/*************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union - Find (합집합 찾기) 
// https://blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221230967614&parentCategoryNo=128&categoryNo=&viewDate=&isShowPopularPosts=false&from=postList
// 부모 노드를 찾는 함수 
int getParent(int parent[], int x) {
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
} 

// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) return parent[b] = a;
	else return parent[a] = b;
} 

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a==b) return 1;
	else return 0;
} 

// 간선 클래스 선언 (정점 2개와 간선의 가중치 정보 포함)
class Edge {
	public:
		int node[2];
		int distance;
		Edge(int a, int b, int distance) {
			this->node[0] = a;
			this->node[1] = b;
			this->distance = distance;
		}
		
		bool operator <(Edge& edge) {
			return this->distance < edge.distance;
		}
};


int main() {
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int i, n, m, p, q;
		scanf("%d %d", &n, &m);
		
		vector<Edge> v;
		v.clear();
		
		// 간선 입력 받고 정렬 
		for(i=0; i<m; i++) {
			scanf("%d %d", &p, &q);
			v.push_back(Edge(p, q, 1));
		}
		
		// 간선 비용을 기준으로 오름차순 정렬
		// sort(v.begin(), v.end());
		// 문제 상 가중치가 모두 1이기 때문에 오름차순으로 정렬할 필요가 없음 
		
		// 각 정점이 포함된 그래프가 어디인지 저장
		int parent[n];
		for(i=0; i<n; i++) {
			parent[i] = i; 	// 기본적으로 모든 정점은 자기 자신을 가리킴 
		}
		
		int sum=0; 
		for(int i=0; i<v.size(); i++) {
			// 싸이클이 발생하지 않는 경우 그래프에 포함시킴함 
			// 두 노드가 서로 연결되어 있지 않은 경우 
			if(!findParent(parent, v[i].node[0]-1, v[i].node[1] - 1)) {
				sum += v[i].distance;
				// 두 노드를 합치면서 가중치 더함
				unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
			}
		}
		
		printf("%d\n", sum);
	}
	return 0;
}
