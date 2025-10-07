#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, bool> phone_map;

    // 1️⃣ 모든 전화번호를 해시맵에 저장
    for (auto &num : phone_book) {
        phone_map[num] = true;
    }

    // 2️⃣ 각 번호의 접두사를 하나씩 잘라가며 검사
    for (auto &num : phone_book) {
        string prefix = "";
        for (int i = 0; i < num.size() - 1; i++) {  // 마지막 전체 번호는 제외
            //마지막 번호 제외하는 이유 -> 자기 자신도 검사할 수 있음
            //1195524421인 경우 119552442 까지만 검사. 
            //119도 11까지만 검사. 다른 경우엔 119까지 다 봄. 
            prefix += num[i];
            if (phone_map.find(prefix) != phone_map.end()) {
                return false; // 다른 번호가 이 번호의 접두사임
            }
        }
    }

    return true;
}
