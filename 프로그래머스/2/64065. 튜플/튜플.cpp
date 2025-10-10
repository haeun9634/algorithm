#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_set>
using namespace std;

vector<int> solution(string s) {
    vector<vector<int>> sets;
    vector<int> answer;

    // 1️⃣ 가장 바깥 { } 제거
    s = s.substr(2, s.size() - 4); // 맨 앞 "{{"와 맨 뒤 "}}" 제거

    // 2️⃣ "},{" 기준으로 분리
    stringstream ss(s);
    string part;
    while (getline(ss, part, '}')) {
        if (part[0] == ',') part = part.substr(2); // "},{" 제거
        /*
        “만약 잘린 문자열이 ,로 시작한다면,
그건 바로 앞 집합 끝의 }랑 연결돼 있었던 "},{" 패턴이니까,
",{ 두 글자를 다 없애야 한다!”
*/
        else if (part[0] == '{') part = part.substr(1);
        
        // 3️⃣ 쉼표로 숫자 분리
        vector<int> nums;
        stringstream inner(part);
        string num;
        while (getline(inner, num, ',')) {
            if (!num.empty())
                nums.push_back(stoi(num));
        }
        if (!nums.empty())
            sets.push_back(nums);
    }

    // 4️⃣ 길이 기준으로 정렬
    sort(sets.begin(), sets.end(), [](auto &a, auto &b){
        return a.size() < b.size();
    });

    // 5️⃣ 처음 나오는 숫자만 추가
    unordered_set<int> seen;
    for (auto &v : sets) {
        for (int x : v) {
            if (seen.find(x) == seen.end()) {
                seen.insert(x);
                answer.push_back(x);
            }
        }
    }

    return answer;
}


/*
| 자른 위치 | 잘린 결과         | 앞부분 패턴          |
| ----- | ------------- | --------------- |
| 첫 번째  | `"2,"`        | `"{{"` → 앞부분 깨끗 |
| 두 번째  | `",{2,1,"`    | `"},{“`로 시작     |
| 세 번째  | `",{2,1,3,"`  | `"},{“`로 시작     |
| 네 번째  | `",{2,1,3,4"` | `"},{“`로 시작     |

*/