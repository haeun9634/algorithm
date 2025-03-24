#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
const int MAX = 1005;
int n;
int arr[MAX];
int dp[MAX];
void printdp() {
    cout << "\n";
    for (int i = 0; i < n; i++) cout << dp[i] << " ";
}
int solve() {
    dp[0] = arr[0];
    
    for (int i = 1; i < n; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    //printdp();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve();

    return 0;
}
