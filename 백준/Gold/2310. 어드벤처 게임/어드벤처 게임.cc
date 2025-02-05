#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Room {
    char type;
    int value;
    vector<int> doors;
};

const int MAX_N = 1005;
Room rooms[MAX_N];
bool visited[MAX_N];
int n;

bool dfs(int now, int money) {
    if (now == n) return true; // 마지막 방(n번 방)에 도착하면 성공

    visited[now] = true;

    for (int next : rooms[now].doors) {
        if (visited[next]) continue; // 이미 방문한 방이면 무시

        int next_money = money;

        // 방의 유형에 따라 소지금 변경
        if (rooms[next].type == 'L' && next_money < rooms[next].value) {
            next_money = rooms[next].value; // 최소 금액 보장
        }
        if (rooms[next].type == 'T') {
            if (next_money < rooms[next].value) continue; // 통행료 부족 시 이동 불가
            next_money -= rooms[next].value;
        }

        if (dfs(next, next_money)) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n;
        if (n == 0) break;

        memset(rooms, 0, sizeof(rooms));
        memset(visited, false, sizeof(visited));

        for (int i = 1; i <= n; i++) {
            cin >> rooms[i].type >> rooms[i].value;
            int door;
            while (true) {
                cin >> door;
                if (door == 0) break;
                rooms[i].doors.push_back(door);
            }
        }

        if (dfs(1, 0)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
