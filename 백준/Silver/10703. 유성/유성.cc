#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    
    int r, s;
    cin >> r >> s;

    //만약 가장 낮은 위치에 있는 유성과
    //그 열에 가장 낮은 위치의 유성 - 가장 높은 위치에 있는 땅
    //그 값들의 최소값 만큼 내려 올 수 있다.
    
    vector<vector<char>> board(r,vector<char>(s));
    for (int i = 0; i < r; i++) {
        string input;
        cin >> input;

        //board 에 입력
        for (int j = 0; j < s; j++) {
            board[i][j] = input[j];
        }
    }

    int minDiff = INT_MAX;

    //열을 순회하면서 가장 작은 차이를 고른다
    for (int i = 0; i < s; i++) {
        int maxMeteor = -1;
        int maxGround = INT_MAX;
        for (int j = 0; j < r; j++) {
            if (board[j][i] == 'X') {
                maxMeteor = j;
            }
            if (board[j][i] == '#' && maxGround == INT_MAX) {
                maxGround = j;
            }
        }
        // 유성이 있고, 그 아래에 땅이 있는 경우만 계산
        if (maxMeteor != -1 && maxGround != INT_MAX) {
            minDiff = min(maxGround - maxMeteor , minDiff);
        }
    }


    //minDiff 만큼 유성을 아래로 내린다.
    //아래부터 탐색해서 중복을 없앤다
    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < s; j++) {
            if (board[i][j] == 'X') {
                board[i][j] = '.';
                board[i + minDiff-1][j] = 'X';
            }
        }
    }


    //복원 후 출력
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}