#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 100001
using namespace std;

int N, M, t;
int answer, conquer;
int connect[10001];
typedef struct li {
	int x;
	int y;
	int cost;
}li;
vector<li> line;

bool cmp(li a, li b) {
	if (a.cost < b.cost) return true;
	return false;
}

int Find(int x) {
	if (connect[x] == x) return x;
	else return connect[x] = Find(connect[x]);
}

void Union(int x, int y) {
	int xx = Find(x);
	int yy = Find(y);
	connect[xx] = yy;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		connect[i] = i;
	}
	for (int i = 0; i < line.size(); i++) {
		if (line[i].x == 1) {
			connect[1] = line[i].y;
			answer += line[i].cost;
			conquer++;
			break;
		}
	}
	for (int i = 0; i < line.size(); i++) {
		int x = Find(line[i].x);
		int y = Find(line[i].y);
		if (x != y) {
			Union(x, y);
			answer += (line[i].cost + conquer * t);
			conquer++;
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> t;
	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		line.push_back({ x,y,cost });
	}
	sort(line.begin(), line.end(), cmp);
	solve();
	return 0;
}