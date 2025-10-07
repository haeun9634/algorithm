#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool compare(pair<int,double>& a, pair<int,double>& b){
    if(a.second==b.second)//같을 경우
        return a.first < b.first;//작은 번호 먼저, 오름차순
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map <int,int> mp;
    for(int i=0; i<stages.size(); i++){
        mp[stages[i]]++;
    }
    vector<pair<int,double>> st;
    int total = stages.size();
    for(int i=1; i<=N; i++){
        double failRate = 0.0;

        if (total != 0) { // 분모가 0이 아닐 때만 계산
            failRate = (double)mp[i] / total;
        }

        st.push_back({i, failRate});
        total -= mp[i];
    }
    
    sort(st.begin(), st.end(), compare);
    for(int i=0; i<st.size(); i++){
        answer.push_back(st[i].first);
    }
    
        
    return answer;
}