#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1));

    // 거리 초기화
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> dist[i][j];
        }
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 각 요청 처리
    for (int i = 0; i < M; ++i) {
        int A, B;
        long long C;
        cin >> A >> B >> C;

        if (dist[A][B] <= C) {
            cout << "Enjoy other party\n";
        } else {
            cout << "Stay here\n";
        }
    }

    return 0;
}
