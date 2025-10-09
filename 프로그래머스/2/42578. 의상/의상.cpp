#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> mp;

    // 종류별 옷 개수 세기
    for (auto& c : clothes) {
        mp[c[1]]++;
    }

    int answer = 1;
    // 각 종류별 (옷개수 + 1) 곱하기
    for (auto& m : mp) {
        answer *= (m.second + 1);
    }

    // 아무것도 안 입는 경우 제외
    return answer - 1;
}
