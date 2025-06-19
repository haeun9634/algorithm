#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple> // 추가 필요
using namespace std;

const int MAX_N = 1005;
int parent[MAX_N];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return false;
    parent[pa] = pb;
    return true;
}

int calc_cost(const string& a, const string& b) {
    int cost = 0;
    for (int i = 0; i < a.size(); ++i)
        cost += abs(a[i] - b[i]);
    return cost;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> words(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];

    // 모든 간선 계산
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            int cost = calc_cost(words[i], words[j]);
            edges.emplace_back(cost, i, j);
        }

    sort(edges.begin(), edges.end());

    int left = 0, right = 500;
    int answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        for (int i = 0; i < n; ++i) parent[i] = i;

        int count = 0;
        for (auto& edge : edges) {
            int cost = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);
            if (cost > mid) continue;
            if (unite(u, v)) ++count;
        }

        if (count == n - 1) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
