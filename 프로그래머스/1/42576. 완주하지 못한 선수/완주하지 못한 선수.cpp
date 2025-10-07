#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map <string, int> p;
    for(int i=0; i<participant.size(); i++){
        p[participant[i]] += 1;
    }
    
    for(int i=0; i<completion.size(); i++){
        p[completion[i]] -= 1;
    }
    
    for(int i=0; i<participant.size(); i++){
       if( p[participant[i]]!=0){
           answer = participant[i];
       }
    }
    
    return answer;
}