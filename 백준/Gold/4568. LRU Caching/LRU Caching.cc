#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

using namespace std;

void printCache(const list<char>& cache) {
    for (char c : cache) {
        cout << c;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, simulationCount = 1;
    string str;

    while (true) {
        cin >> n;
        if (n == 0) break; // 종료 조건

        cin >> str;
        cout << "Simulation " << simulationCount << "\n";

        list<char> cache; // 캐시 리스트 
        unordered_map<char, list<char>::iterator> cacheMap; // 캐시 위치를 추적하는 맵

        for (char c : str) {
            if (c == '!') {
                printCache(cache);
            } else {
                // 캐시 갱신
                if (cacheMap.find(c) != cacheMap.end()) {
                    // 이미 캐시에 존재 -> 위치 갱신
                    cache.erase(cacheMap[c]);
                    cache.push_back(c);
                    cacheMap[c] = --cache.end();
                } else {
                    // 캐시에 존재하지 않음 -> 추가
                    if (cache.size() == n) {
                        // 캐시가 꽉 찼다면 LRU 제거
                        char lru = cache.front();
                        cache.pop_front();
                        cacheMap.erase(lru);
                    }
                    cache.push_back(c);
                    cacheMap[c] = --cache.end();
                }
            }
        }

        simulationCount++;
    }

    return 0;
}
