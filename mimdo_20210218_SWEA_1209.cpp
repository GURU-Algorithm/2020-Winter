#include <iostream>
#include <algorithm>
using namespace std;


int arr[100][100];

int main() {
    int test_case;
    int T;

    T = 10;

    for (test_case = 1; test_case <= T; test_case++) {

        int case_num;
        cin >> case_num;


        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }


        int ans = 0;

        int sumLDiag = 0, sumRDiag = 0;

        for (int i = 0; i < 100; i++) {

            int sumRow = 0, sumCol = 0;
            sumLDiag = arr[i][i];
            sumRDiag = arr[i][99 - i];

            for (int j = 0; j < 100; j++) {
                sumRow += arr[i][j];
                sumCol += arr[j][i];
            }

            ans = max(max(sumRow, sumCol), ans);
        }
        ans = max(max(sumLDiag, sumRDiag), ans);


        cout << "#" << case_num << " " << ans << "\n";
    }
}
