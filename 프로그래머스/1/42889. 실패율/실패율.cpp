#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

// 정렬 함수: 실패율 내림차순, 같으면 스테이지 번호 오름차순
bool compare(pair<int, double>& a, pair<int, double>& b) {
    if (a.second == b.second)
        return a.first < b.first;  // 스테이지 번호 오름차순
    return a.second > b.second;    // 실패율 내림차순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map<int, int> mp;  // 스테이지별 인원 수
    int len = stages.size();     // 전체 사용자 수

    // 각 스테이지에 멈춘 사용자 수 세기
    for (int i = 0; i < len; i++) {
        mp[stages[i]]++;
    }

    int now = len;  // 현재 스테이지 이상 도달한 사람 수
    vector<pair<int, double>> fail;

    for (int i = 1; i <= N; i++) {
        double rate = 0.0;
        if (now != 0)  // 나눗셈 방지
            rate = (double)mp[i] / now;
        fail.push_back({i, rate});
        now -= mp[i];  // 다음 스테이지로 넘어감
    }

    sort(fail.begin(), fail.end(), compare);

    for (int i = 0; i < fail.size(); i++) {
        answer.push_back(fail[i].first);
    }

    return answer;
}
