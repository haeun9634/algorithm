#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define arr_size 55
using namespace std;
using ll = long long int;
int n, m;
int room[arr_size][arr_size];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool isSafe(int y,int x) {
	if (y >= 0 && x >= 0 && y < n && x < m && room[y][x] == 0) return true;
	else return false;
}
int solve(int r,int c, int d) {
	int cnt = 0;
	while (1) {
		if (room[r][c] == 0) {//청소되지 않은 경우
			room[r][c] = 3;
			cnt++;
		}
		bool a = false;
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;//북 동 남 서 순으로 
			int newr = r + dx[d];
			int newc = c + dy[d];
			if (isSafe(newr, newc)) {//청소되지 않은 경우
				r += dx[d];
				c += dy[d];
				a = true;
				break;
			}
		}
		if (!a) {//후진할때
			int idx = (d + 2) % 4;
			if (room[r + dx[idx]][c + dy[idx]] == 1) break; //후진할 수 없다면 break
			r += dx[idx];
			c += dy[idx];
		}

		
	}

	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int r,c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}
	cout << solve(r,c, d);
	// 00 01 02
	// 10 11 12
	// 20 21 22 
}