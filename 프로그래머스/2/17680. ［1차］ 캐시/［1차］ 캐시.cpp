#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return cities.size() * 5; // 캐시 크기가 0이면 전부 miss

    int answer = 0;
    list<string> cache; // LRU 캐시 리스트

    for (auto city : cities) {
        // 대소문자 구분 없음
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        // 캐시 안에 해당 도시가 존재하는가?
        auto it = find(cache.begin(), cache.end(), city);
        if (it != cache.end()) {
            // ✅ cache hit
            answer += 1;
            // 최근에 사용되었으므로 맨 뒤로 옮기기
            cache.erase(it);
            cache.push_back(city);
        } else {
            // ❌ cache miss
            answer += 5;
            if (cache.size() == cacheSize) {
                // LRU: 가장 오래된 것 제거 (맨 앞)
                cache.pop_front();
            }
            cache.push_back(city);
        }
    }

    return answer;
}
