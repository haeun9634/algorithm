#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int MAX = 100;

unordered_map<string, int> name_to_id;
vector<string> id_to_name;
vector<int> indegree;
vector<vector<int>> graph;
vector<double> blood;
vector<pair<string, string>> parent_info; // i번 사람이 누구의 자식인지 저장

int get_id(const string& name) {
    if (name_to_id.count(name)) return name_to_id[name];
    int id = name_to_id.size();
    name_to_id[name] = id;
    id_to_name.push_back(name);
    indegree.push_back(0);
    graph.emplace_back();
    blood.push_back(0.0);
    parent_info.emplace_back("", "");
    return id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    string founder;
    cin >> founder;
    int founder_id = get_id(founder);
    blood[founder_id] = 1.0;

    // 가족 관계 입력
    for (int i = 0; i < N; ++i) {
        string child, p1, p2;
        cin >> child >> p1 >> p2;
        int cid = get_id(child);
        int pid1 = get_id(p1);
        int pid2 = get_id(p2);

        // 부모 → 자식 방향 그래프
        graph[pid1].push_back(cid);
        graph[pid2].push_back(cid);
        indegree[cid] += 2;

        // 부모 정보 저장
        parent_info[cid] = {p1, p2};
    }

    // 위상 정렬로 혈통 계산
    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int child : graph[cur]) {
            indegree[child]--;
            if (indegree[child] == 0) {
                // 부모의 혈통을 자식에게 반씩 더해줌
                string p1 = parent_info[child].first;
                string p2 = parent_info[child].second;
                int pid1 = name_to_id[p1];
                int pid2 = name_to_id[p2];
                blood[child] = 0.5 * blood[pid1] + 0.5 * blood[pid2];
                q.push(child);
            }
        }
    }

    // 왕위 주장자 입력 및 최댓값 찾기
    string result;
    double max_blood = -1.0;
    for (int i = 0; i < M; ++i) {
        string claimant;
        cin >> claimant;
        int id = get_id(claimant); // 아직 등장 안한 사람도 있을 수 있음
        if (blood[id] > max_blood) {
            max_blood = blood[id];
            result = claimant;
        }
    }

    cout << result << '\n';
    return 0;
}
