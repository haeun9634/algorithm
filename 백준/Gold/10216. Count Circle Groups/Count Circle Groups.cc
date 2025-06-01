#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Enemy {
    int x, y, r;
};

int find(vector<int>& parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(vector<int>& parent, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a != b)
        parent[b] = a;
}

bool isConnected(const Enemy& a, const Enemy& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long r_sum = a.r + b.r;
    return dx * dx + dy * dy <= r_sum * r_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Enemy> enemies(N);
        vector<int> parent(N);

        for (int i = 0; i < N; ++i) {
            cin >> enemies[i].x >> enemies[i].y >> enemies[i].r;
            parent[i] = i;
        }

        // Union if connected
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (isConnected(enemies[i], enemies[j])) {
                    unite(parent, i, j);
                }
            }
        }

        // Count unique parents (groups)
        int groups = 0;
        for (int i = 0; i < N; ++i) {
            if (find(parent, i) == i)
                ++groups;
        }

        cout << groups << '\n';
    }

    return 0;
}
