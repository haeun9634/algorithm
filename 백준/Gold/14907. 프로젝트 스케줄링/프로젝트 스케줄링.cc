#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 26;
    vector<vector<int>> graph(N);
    vector<int> indegree(N, 0);
    vector<int> time(N, 0);
    vector<int> dp(N, 0);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        char task_char;
        int duration;
        string prereq;

        ss >> task_char >> duration >> prereq;
        int task = task_char - 'A';
        time[task] = duration;

        for (char ch : prereq) {
            int pre = ch - 'A';
            graph[pre].push_back(task);
            indegree[task]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0 && time[i] > 0) {
            q.push(i);
            dp[i] = time[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : graph[cur]) {
            indegree[next]--;
            dp[next] = max(dp[next], dp[cur] + time[next]);
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    int result = *max_element(dp.begin(), dp.end());
    cout << result << '\n';
    return 0;
}
