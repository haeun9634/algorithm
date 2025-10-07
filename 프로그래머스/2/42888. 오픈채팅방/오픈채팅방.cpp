#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> split(string s) {
    vector<string> result;
    istringstream iss(s);
    string word;
    while (iss >> word) {   // 공백 단위로 한 단어씩 읽기
        result.push_back(word);
    }
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> names; // uid -> 이름 저장

    // 1️⃣ Enter / Change 명령어에서 이름 최신화
    for (int i = 0; i < record.size(); i++) {
        vector<string> tokens = split(record[i]);
        string cmd = tokens[0];
        string uid = tokens[1];

        if (cmd == "Enter" || cmd == "Change") {
            string name = tokens[2];
            names[uid] = name;
        }
    }

    // 2️⃣ 메시지 생성
    for (int i = 0; i < record.size(); i++) {
        vector<string> tokens = split(record[i]);
        string cmd = tokens[0];
        string uid = tokens[1];
        string name = names[uid]; // 최신 이름

        if (cmd == "Enter") {
            answer.push_back(name + "님이 들어왔습니다.");
        } 
        else if (cmd == "Leave") {
            answer.push_back(name + "님이 나갔습니다.");
        }
    }

    return answer;
}
