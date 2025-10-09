#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm> // min, max 사용
using namespace std;

bool checkA(char a){//문자 여부 확인
    return (a>='a' && a<='z') || (a>='A' && a<='Z');
}

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> mp;
    unordered_map<string, int> mp2;
    
    for(int i=0; i<str1.size()-1; i++){
        if(checkA(str1[i]) && checkA(str1[i+1])) {
            if(str1[i]>='A' && str1[i]<='Z') str1[i] += 32;
            if(str1[i+1]>='A' && str1[i+1]<='Z') str1[i+1] += 32;

            string st;
            st += str1[i];
            st += str1[i+1];
            mp[st]++;
        }
    }
    
    for(int i=0; i<str2.size()-1; i++){
        if(checkA(str2[i]) && checkA(str2[i+1])) {
            if(str2[i]>='A' && str2[i]<='Z') str2[i] += 32;
            if(str2[i+1]>='A' && str2[i+1]<='Z') str2[i+1] += 32;

            string st;
            st += str2[i];
            st += str2[i+1];
            mp2[st]++;
        }
    }

    // ✅ 교집합 & 합집합 계산
    int inter = 0, uni = 0;
    unordered_map<string, int> all = mp;
    for (auto &m : mp2) all[m.first]; // 두 map key 병합

    for (auto &k : all) {
        inter += min(mp[k.first], mp2[k.first]); // 교집합 (작은 쪽)
        uni += max(mp[k.first], mp2[k.first]);   // 합집합 (큰 쪽)
    }

    if (uni == 0) return 65536; // 둘 다 공집합인 경우

    double temp = (double)inter / uni;
    answer = (int)(temp * 65536);

    cout << "교집합: " << inter << ", 합집합: " << uni << ", 결과: " << answer << "\n";
    return answer;
}
