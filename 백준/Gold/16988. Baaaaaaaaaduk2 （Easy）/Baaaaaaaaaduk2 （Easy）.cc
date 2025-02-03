#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#define V_SIZE 25
using namespace std;
using ll = long long int;
using pi = pair<int, int>;
int n, m;
vector <pair<int,int>> st;
int arr[V_SIZE][V_SIZE];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };//상하좌우 
int visited[V_SIZE][V_SIZE];
bool confirm(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == 0)
		return true;
	else return false;
}
void fillvisited() {
	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + m, 0);
	}
}
int bfs() {
	int ans = 0;
	fillvisited();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2 && visited[i][j] == 0) {
				bool a = true;
				queue<pi> q;
				q.push({ i,j });
				visited[i][j] = 1;
				int cnt = 0;
				while (!q.empty()) {
					pi top = q.front();
					q.pop();
					cnt++;//2의 갯수 
					for (int k = 0; k < 4; k++) {
						int newx = top.first + dx[k];
						int newy = top.second + dy[k];
						if (confirm(newx, newy)) {
							if (arr[newx][newy] == 2) {
								q.push({ newx,newy });
								visited[newx][newy] = 1;
							}
							else if (arr[newx][newy] == 0) {
								a = false;
								//0이 또하나 더있으므로 안됨 
							}

						}
					}
				}

				if (a) {
					ans += cnt;
				}
			}
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				st.push_back({ i,j });
		}
	}
	int answer = 0;

	for (int i = 0; i < st.size(); i++) {
		for (int j = 0; j < st.size(); j++) {
			if (i == j) continue;
			//0 2개 뽑음 
			pi first = { st[i].first, st[i].second };
			pi second = { st[j].first, st[j].second };
			//1로 변경
			arr[first.first][first.second] = 1;
			arr[second.first][second.second] = 1;

			int temp = bfs();
			answer = max(answer, temp);

			arr[first.first][first.second] = 0;
			arr[second.first][second.second] = 0;
			

		}
	}

	cout << answer;

	

	return 0;
}