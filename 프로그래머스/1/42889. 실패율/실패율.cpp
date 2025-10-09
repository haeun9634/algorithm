#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(pair<int,double>& a, pair<int,double>& b){
    if(a.second==b.second)
        return a.first<b.first;//오름차순
    return a.second>b.second;//내림차순
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map <int,int> mp;
    for(int i=0; i<stages.size(); i++){
        mp[stages[i]]++;
    }
    vector <pair<int, double>> failrate;
    int temp = stages.size();
    for(int i=1; i<=N; i++){
        double num=0;
        if(temp!=0)
            num =(double)mp[i]/temp;
        failrate.push_back({i,num});
        temp -= mp[i];
    }
    sort(failrate.begin(), failrate.end(), compare);
    
    for(int i=0; i<N; i++){
        answer.push_back(failrate[i].first);
    }
    

    
    
    return answer;
}