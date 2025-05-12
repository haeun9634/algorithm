#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int V_SIZE = 50;
int n;
vector<int> adj[V_SIZE];
int bfs(int start) {
	queue <pair<int,int>> q;
	q.push({start,0});
	int visited[V_SIZE] = { 0 };
	int ans = 0; 
	visited[start] = 1;
	//cout << "start: " << start << endl;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		//cout << "p.first: " << p.first << " p.second: " << p.second << endl;
		ans = max(ans, p.second);
		for (int i = 0; i < adj[p.first].size(); i++) {
			int next = adj[p.first][i];
			if (visited[next] == 0) {
				visited[next] = p.second + 1;
				q.push({ next, visited[next] });
			}
		}
	}
	return ans;
	
}
int main(void) {
	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int num[55];
	int minnum = 1000000;
	vector <int> answer;

	for (int i = 1; i <= n; i++) {
		num[i]=bfs(i);
		minnum = min(minnum, num[i]);
	}
	int cnt = 0; 
	for (int i = 0; i <= n; i++) {
		if (num[i] == minnum) {
			cnt++;
			answer.push_back(i);
		}
	}
	cout << minnum << " " << cnt << endl;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}