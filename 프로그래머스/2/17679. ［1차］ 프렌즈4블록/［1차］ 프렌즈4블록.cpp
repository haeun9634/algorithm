#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (true) {
        set<pair<int, int>> toErase; // 지울 칸 좌표 저장 (중복 방지)

        // 1️⃣ 2x2 같은 블록 찾기
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char c = board[i][j];
                if (c == ' ') continue; // 빈칸은 스킵

                if (board[i + 1][j] == c &&
                    board[i][j + 1] == c &&
                    board[i + 1][j + 1] == c) {
                    toErase.insert({i, j});
                    toErase.insert({i + 1, j});
                    toErase.insert({i, j + 1});
                    toErase.insert({i + 1, j + 1});
                }
            }
        }

        // 2️⃣ 더 이상 지울 게 없으면 종료
        if (toErase.empty()) break;

        // 3️⃣ 블록 지우기
        for (auto [x, y] : toErase) board[x][y] = ' ';
        answer += toErase.size();

        // 4️⃣ 블록 떨어뜨리기 (열 기준)
        for (int col = 0; col < n; col++) {
            for (int row = m - 1; row >= 0; row--) {
                if (board[row][col] == ' ') { // 빈칸이면
                    // 위쪽 블록 찾기
                    for (int up = row - 1; up >= 0; up--) {
                        if (board[up][col] != ' ') {
                            board[row][col] = board[up][col];
                            board[up][col] = ' ';
                            break;
                        }
                    }
                }
            }
        }
    }

    return answer;
}
