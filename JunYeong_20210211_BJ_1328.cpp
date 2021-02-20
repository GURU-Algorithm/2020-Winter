#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long building[101][101][101] = { 0 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, lt, rt, i, j, k;
    cin >> n >> lt >> rt;

    building[1][1][1] = 1;
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= lt; j++) {
            for (k = 1; k <= rt; k++) {
                building[i][j][k] = building[i - 1][j - 1][k] + building[i - 1][j][k - 1] + building[i - 1][j][k] * (i - 2);
                building[i][j][k] %= 1000000007;
            }
        }
    }
    
    printf("%lld\n", building[n][lt][rt]);
    return 0;
}
