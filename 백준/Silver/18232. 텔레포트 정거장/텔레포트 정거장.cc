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
int n, m;
int s, e;
vector <int> v[V_SIZE];
int visited[V_SIZE];
int answer = 2e9;
int d;
void bfs(int num) {
    queue <pair<int, int>> q;
    q.push({num,1});
    visited[num] = 1;
    while (!q.empty()) {
        pair<int,int> num = q.front();
        if (num.first == e) {
            answer = num.second - 1;
;            break;
        }
      // cout << num.first << " " << num.second << "\n";
        q.pop();
        for (int i = 0; i < v[num.first].size(); i++) {
            if (!visited[v[num.first][i]]) {
                visited[v[num.first][i]] = 1;
                q.push({ v[num.first][i], num.second + 1 });
            }
        }
        if (!visited[num.first + 1] && num.first + 1 <= 300000) {
            visited[num.first + 1] = 1;
            q.push({ num.first + 1, num.second + 1 });
        }
        if (!visited[num.first - 1] && num.first - 1 >= 1) 
        {
            visited[num.first - 1] = 1;
            q.push({ num.first - 1, num.second + 1 });
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s >> e;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(s);
    cout << answer;

    return 0;
}
