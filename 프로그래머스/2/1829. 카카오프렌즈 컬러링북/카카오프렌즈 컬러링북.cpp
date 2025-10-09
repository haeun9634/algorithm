#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void resetVisited() {
    for (int i = 0; i < 105; i++)
        fill(visited[i], visited[i] + 105, false);
}

int bfs(int x, int y, vector<vector<int>>& picture) {
    int color = picture[x][y]; // 현재 색
    int areaSize = 1;          // 넓이 = 1칸부터 시작
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 범위 확인
            if (nx < 0 || ny < 0 || nx >= picture.size() || ny >= picture[0].size())
                continue;
            
            // 같은 색 && 방문 안 했으면 탐색
            if (!visited[nx][ny] && picture[nx][ny] == color) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                areaSize++;
            }
        }
    }

    return areaSize;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    resetVisited();

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] != 0) {
                int size = bfs(i, j, picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, size);
            }
        }
    }

    return {number_of_area, max_size_of_one_area};
}
