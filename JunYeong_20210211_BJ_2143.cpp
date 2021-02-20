#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력 받기
    int T, n, m, i, j;
    scanf_s("%d", &T);
    scanf_s("%d", &n);
    vector<long long> a(n);
    for (i = 0; i < n; i++) scanf_s("%lld", &a[i]);
    scanf_s("%d", &m);
    vector<long long> b(m);
    for (i = 0; i < m; i++) scanf_s("%lld", &b[i]);

    // 누적합 계산
    for (i = 0; i < n; ++i) {
        long long sum = a[i];
        for (j = i + 1; j < n; ++j) {
            sum += a[j];
            a.push_back(sum);
        }
    }

    for (i = 0; i < m; ++i) {
        long long sum = b[i];
        for (j = i + 1; j < m; ++j) {
            sum += b[j];
            b.push_back(sum);
        }
    }

    // 부 배열 합 오름차순 정렬
    sort(b.begin(), b.end());

		// 이분 탐색
    long long res = 0;
    for (i = 0; i < a.size(); i++) {
        int lt = 0, rt = b.size() - 1, mid;
        int ub = -1, lb = -1, sum = a[i];

				// lower bound 계산
        while (lt <= rt) {
            mid = (lt + rt) / 2;
            if (sum + b[mid] >= T) {
                if (sum + b[mid] == T)
                    lb = mid;
                rt = mid - 1;
            }

            else if (sum + b[mid] < T) {
                lt = mid + 1;
            }
        }

				// upper bound 계산
        lt = 0, rt = b.size() - 1;
        while (lt <= rt) {
            mid = (lt + rt) / 2;
            if (sum + b[mid] > T) {
                rt = mid - 1;
            }

            else if (sum + b[mid] <= T) {
                if (sum + b[mid] == T)
                    ub = mid;
                lt = mid + 1;
            }
        }

        if (ub != -1 && lb != -1)
            res += (ub - lb + 1);
    }

    printf("%lld", res);
    return 0;
}

////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // 입력 받기
    int T, n, m, i, j;
    scanf("%d", &T);
    scanf("%d", &n);
    vector<long long> a(n);
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);
    scanf("%d", &m);
    vector<long long> b(m);
    for (i = 0; i < m; i++) scanf("%lld", &b[i]);

    // 누적합 계산
    for (i = 0; i < n; ++i) {
        long long sum = a[i];
        for (j = i + 1; j < n; ++j) {
            sum += a[j];
            a.push_back(sum);
        }
    }

    for (i = 0; i < m; ++i) {
        long long sum = b[i];
        for (j = i + 1; j < m; ++j) {
            sum += b[j];
            b.push_back(sum);
        }
    }

    // 부 배열 합 오름차순 정렬
    sort(b.begin(), b.end());

    long long res = 0;
    for (i = 0; i < a.size(); i++) {
        long long ub = upper_bound(b.begin(), b.end(), T - a[i]) - b.begin();
        long long lb = lower_bound(b.begin(), b.end(), T - a[i]) - b.begin();
        res += (ub - lb);
    }
    printf("%lld", res);
    return 0;
}
