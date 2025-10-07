#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
using namespace std;

vector<string> split(string& s, char d){
    vector<string> result;
    string token;
    istringstream iss(s);
    while(getline(iss,token, d)){
        result.push_back(token);
    }
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map <string, string> mp;
    
    for(int i=0; i<record.size(); i++){
        vector<string> token = split(record[i],' ');
        string cases = token[0];
        string uid = token[1];
        // name이 있을 때만 처리
        if(cases == "Enter" || cases == "Change"){
            string name = token[2];
            mp[uid] = name;
        }
    }
    
    for(int i=0; i<record.size(); i++){
        vector<string> token = split(record[i],' ');
        string cases = token[0];
        string uid = token[1];
        if(cases=="Enter"){
            answer.push_back(mp[uid]+"님이 들어왔습니다.");
        }
        else if (cases=="Leave"){
             answer.push_back(mp[uid]+"님이 나갔습니다.");
        }
    }
    return answer;
}