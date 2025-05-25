#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> adj(N + 1, vector<bool>(N + 1, false));

    // 입력
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A][B] = true; // A가 B보다 강하다
    }

    // 플로이드-워셜로 관계 유추
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (adj[i][k] && adj[k][j]) {
                    adj[i][j] = true;
                }
            }
        }
    }

    int result = 0;

    for (int i = 1; i <= N; ++i) {
        int count = 0;
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue;
            if (adj[i][j] || adj[j][i]) {
                count++;
            }
        }
        if (count == N - 1) result++; // 모든 소들과 비교 가능하면 순위 확정
    }

    cout << result << '\n';
    return 0;
}
