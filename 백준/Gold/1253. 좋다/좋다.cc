#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);  // 값의 범위가 크므로 long long 사용
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());  // 투 포인터를 위한 정렬

    int goodCount = 0;

    for (int k = 0; k < N; ++k) {
        long long target = A[k];
        int i = 0, j = N - 1;

        while (i < j) {
            if (i == k) {
                ++i;
                continue;
            }
            if (j == k) {
                --j;
                continue;
            }

            long long sum = A[i] + A[j];
            if (sum == target) {
                ++goodCount;
                break;
            } else if (sum < target) {
                ++i;
            } else {
                --j;
            }
        }
    }

    cout << goodCount << '\n';
    return 0;
}
