#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;
int n, k;
int Distance[MAX + 1]; // 거리 저장 배열
queue<int> q;

void bfs(int start) {
    Distance[start] = 1; // 시작점 방문 처리 (1부터 시작)
    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        if (here == k) { 
            cout << Distance[here] - 1; // 1부터 시작했으므로 -1 해서 출력
            return;
        }

        for (int next : {here - 1, here + 1, here * 2}) {
            if (next >= 0 && next <= MAX && Distance[next] == 0) {
                q.push(next);
                Distance[next] = Distance[here] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    bfs(n);

    return 0;
}
