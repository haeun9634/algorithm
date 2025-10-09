#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++) {
        int line = arr1[i] | arr2[i]; // 비트 OR → 하나라도 벽(#)이면 벽
        string row = "";
        
        // n자리 비트로 한 줄 만들기 (맨 뒤부터 읽기)
        for (int j = n - 1; j >= 0; j--) {
            if (line & (1 << j)) row += '#'; // j번째 비트가 1이면 벽
            else row += ' ';                 // 아니면 공백
        }
        answer.push_back(row);
    }

    return answer;
}
