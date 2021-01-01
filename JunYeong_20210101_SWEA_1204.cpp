#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int i, m, score, scores[101];
		for(i=0; i<=100; i++) {
			scores[i]=0;	
		}
		
		scanf("%d", &m);
		for(i=1; i<=1000; i++) {
			scanf("%d", &score);
			scores[score]++;
		}
		
		int max=0, idx;
		for(i=0; i<=100; i++) {
			if(scores[i] >= max) {
				max = scores[i];
				idx = i;
			}
		}
		
		printf("#%d %d\n", test_case, idx);
	}

	return 0;// 
}
