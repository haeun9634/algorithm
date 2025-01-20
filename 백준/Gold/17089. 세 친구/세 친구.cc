#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define arr_size 100005

using namespace std;
int n, m;
vector <int> v[4005];

bool check(int x, int y) {
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int answer = 2e9;
    //숫자 3개 고르기

    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            if (check(a, b)) {//a와 b가 친구면
                for (int c = b + 1; c <= n; c++) {
                    if (check(c, b) && check(c, a)) {//a와 c, c와 a가 친구면
                        //세친구 a,b,c 로직 계산
                        int temp = v[a].size() + v[b].size() + v[c].size() - 6;
                        answer = min(answer, temp);
                    }
                }
            }
        }
    }
    if (answer == 2e9) answer = -1;
    cout << answer << "\n";



    return 0;
}
