#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    // 그래프 구성
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;

        if (b == 0) {
            graph[u].emplace_back(v, 0); // 정방향: 비용 0
            graph[v].emplace_back(u, 1); // 역방향: 비용 1 (전환 필요)
        } else {
            graph[u].emplace_back(v, 0);
            graph[v].emplace_back(u, 0);
        }
    }

    // 모든 정점에 대해 0-1 BFS 수행
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int start = 1; start <= n; ++start) {
        deque<int> dq;
        dq.push_back(start);
        dist[start][start] = 0;

        while (!dq.empty()) {
            int cur = dq.front();
            dq.pop_front();

            for (auto [next, cost] : graph[cur]) {
                if (dist[start][next] > dist[start][cur] + cost) {
                    dist[start][next] = dist[start][cur] + cost;
                    if (cost == 0) dq.push_front(next);
                    else dq.push_back(next);
                }
            }
        }
    }

    // 쿼리 처리
    int k;
    cin >> k;
    while (k--) {
        int s, e;
        cin >> s >> e;
        cout << dist[s][e] << '\n';
    }

    return 0;
}
