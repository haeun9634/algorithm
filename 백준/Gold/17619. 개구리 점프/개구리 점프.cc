#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Log {
    int x1, x2, y, id;
};

int N, Q;
vector<Log> logs;
vector<int> parent;

bool cmp(const Log& a, const Log& b) {
    return a.y < b.y;
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;
    logs.resize(N);
    parent.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> logs[i].x1 >> logs[i].x2 >> logs[i].y;
        logs[i].id = i;
        parent[i] = i;
    }

    sort(logs.begin(), logs.end(), cmp); // y 기준으로 정렬

    // 세그먼트 트리 없이 수직 점프 가능한 통나무끼리 Union
    // x1 ~ x2가 겹치면 같은 컴포넌트로 묶음
    vector<pair<int, int>> active; // {x2, log_id}

    for (int i = 0; i < N; ++i) {
        int x1 = logs[i].x1, x2 = logs[i].x2;
        int id = logs[i].id;

        for (auto& [ax2, aid] : active) {
            if (logs[aid].x2 < x1) continue; // 완전히 겹치지 않으면 skip
            if (logs[aid].x1 > x2) continue;
            unite(id, aid);
        }

        active.push_back({x2, id});
    }

    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << (find(a) == find(b) ? 1 : 0) << '\n';
    }

    return 0;
}
