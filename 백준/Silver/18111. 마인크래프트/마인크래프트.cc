#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, b;
int ground[505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력 받기
    cin >> n >> m >> b;
    vector<int> heightCount(257, 0);  // 높이 0~256에 대한 블록 개수 세기

    // 땅의 높이 정보 입력받고, 각 높이의 블록 개수 세기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ground[i][j];
            heightCount[ground[i][j]]++;
        }
    }

    int minTime = 1e9;  // 최소 시간을 초기화 (큰 값으로 설정)
    int bestHeight = -1;  // 최적의 높이 (최소 시간이 나오는 높이)

    // 목표 높이 0 ~ 256까지 시도
    for (int targetHeight = 0; targetHeight <= 256; ++targetHeight) {
        int time = 0;  // 현재 목표 높이를 만들기 위한 시간
        int inventory = b;  // 인벤토리 블록 수

        // 목표 높이로 만들기 위해 필요한 시간 계산
        for (int h = 0; h <= 256; ++h) {
            int blockDiff = h - targetHeight;  // 목표와 현재 높이 차이

            if (blockDiff > 0) {
                // 블록을 제거해야 할 경우
                time += blockDiff * 2 * heightCount[h];  // 블록을 제거하는 데 걸리는 시간
                inventory += blockDiff * heightCount[h];  // 인벤토리에 블록을 더함
            }
            else if (blockDiff < 0) {
                // 블록을 추가해야 할 경우
                time -= blockDiff * heightCount[h];  // 블록을 추가하는 데 걸리는 시간
                inventory += blockDiff * heightCount[h];  // 인벤토리에서 블록을 소모
            }
        }

        // 인벤토리가 부족하면 이 목표 높이는 불가능
        if (inventory < 0) continue;

        // 최소 시간 업데이트
        if (time < minTime) {
            minTime = time;
            bestHeight = targetHeight;
        }
        // 시간이 같으면 더 높은 높이를 선택
        else if (time == minTime && targetHeight > bestHeight) {
            bestHeight = targetHeight;
        }
    }

    // 결과 출력
    cout << minTime << " " << bestHeight << "\n";
    return 0;
}
