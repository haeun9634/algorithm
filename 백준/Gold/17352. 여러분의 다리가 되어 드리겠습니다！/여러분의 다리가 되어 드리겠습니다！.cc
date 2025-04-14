#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>

using ll = long long int;
using namespace std;
const int V_SIZE = 300005;
int n;
vector <int> v[V_SIZE];
int visited[V_SIZE];
void bfs(int num) {
    queue <int> q;
    q.push(num);
    while (!q.empty()) {
        int now = q.front();
        visited[now] = 1;
        //cout << now << " ";
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (!visited[next]) {
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a, b;
    for (int i = 2; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector <pair<int, int>> answer;
    bfs(1);
    for (int i = 1; i <= n; i++) {
        if (visited[i] != 1) {
            //이전 방문되었던 곳들 중 하나와 연결
            answer.push_back({ 1,i });
            bfs(i);
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i].first << " " << answer[i].second << "\n";
    }

    return 0;
}
