#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 각도를 계산하는 함수
double calculate_angle(int hh, int mm) {
    // 시침과 분침의 각도 계산
    double hour_angle = 30 * (hh % 12) + 0.5 * mm;
    double minute_angle = 6 * mm;
    double angle = fabs(hour_angle - minute_angle);

    // 작은 각도를 반환 (180도를 초과하면 360 - angle)
    return min(angle, 360 - angle);
}

int main() {
    int T;
    cin >> T;  // 테스트 케이스의 수

    while (T--) {
        vector<pair<double, string>> angles;
        
        // 5개의 시간을 입력받고 각도를 계산하여 저장
        for (int i = 0; i < 5; ++i) {
            string time;
            cin >> time;
            
            int hh, mm;
            sscanf(time.c_str(), "%d:%d", &hh, &mm);
            
            double angle = calculate_angle(hh, mm);
            angles.push_back(make_pair(angle, time));
        }

        // 각도를 기준으로 오름차순 정렬, 각도 동일하면 시간을 기준으로 정렬
        sort(angles.begin(), angles.end(), [](const pair<double, string>& a, const pair<double, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second;  // 각도가 같으면 시간을 기준으로 정렬
            }
            return a.first < b.first;  // 각도를 기준으로 정렬
        });

        // 중간값인 세 번째 시간을 출력
        cout << angles[2].second << endl;
    }

    return 0;
}
