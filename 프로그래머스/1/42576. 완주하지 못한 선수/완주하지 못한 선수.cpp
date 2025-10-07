#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string,int> mp;
    for(string name : participant) mp[name]++;
    for(string name : completion) mp[name]--;
    
    for(string name : participant){
        if(mp[name]!=0){
            answer = name;
            break;
        }
    }
    return answer;
}