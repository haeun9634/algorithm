#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define V_SIZE 1000005
using namespace std;
using ll = long long int;
bool visited[V_SIZE];
vector <int> v;
int n;
int arr[V_SIZE];
int sum = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k,x;
    int ans = 1000005;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) v.push_back(i);
    }
    if (v.size() < k) cout << "-1";//라이언의 길이가 x보다 짧을 경우
    else {
        for (int i = 0; i <= v.size()-k; i++) {
            ans = min(ans, v[i+k-1] - v[i] + 1);
            //마지막 위치 i+x-1에서 처음 위치 i를 빼줌
        }
        cout << ans;
    }
}