#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef __int128 xll;

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    vector<vector<int>> edges(n);
    vector<bool> exc(n);	// 정점의 제거 여부를 저장
    vector<int> neigh(n);	// 정점의 이웃 수를 저장
    
    // 그래프의 간선 배열을 만들고, 각 정점의 이웃 수를 계산합니다.
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        
        edges[u].push_back(v);
        edges[v].push_back(u);
        
        neigh[u]++;
        neigh[v]++;
    }
    
    // 가장자리 정점을 삽입하는 큐입니다.
    queue<int> q;
    
    // 가장자리 정점의 수를 셉니다.
    int ec = 0;
    for (int i = 0; i < n; i++) {
        if (neigh[i] == 1) {
            ec++;
        }
    }
    
    // 가장자리 정점의 수가 3개 이상이면 큐에 정점들을 삽입합니다.
    if (ec > 2) {
        for (int i = 0; i < n; i++) {
            if (neigh[i] == 1) {
                q.push(i);
                exc[i] = true;
            }
        }
    }
    
    // 그래프가 줄기만 남게 될때까지 가장자리 정점을 제거합니다.
    while (1) {
    	// 큐의 크기가 2 이하, 즉 그래프가 줄기만 남게 되면 종료합니다.
        int loop = q.size();
        if (loop <= 2) break;
        
        vector<int> next_elems;
        
        for (int i = 0; i < loop; i++) {
            int v = q.front();
            q.pop();
            
            // 큐에 담긴 정점들을 제거하고, 이웃한 정점들의 이웃 수를 1 줄입니다.
            for (int c: edges[v]) {
                if (!exc[c] && --neigh[c] == 1) {
                    next_elems.push_back(c);
                    q.push(c);
                }
            }
        }
        
        if (next_elems.size() <= 2) break;
        
        for (int x: next_elems) {
            exc[x] = true;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!exc[i]) cout << i << " ";
    }
}