#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#define V_SIZE 100005

using namespace std;
using ll = long long int;
ll dp[105][10];
int solve(int n, int j) {//n과 자릿수 j 
    if (j < 0 || j >9) return 0;
    if (n == 1) {
        if (j == 0) return 0;
        else return 1;
    }

    if (dp[n][j] > 0) return dp[n][j];

    dp[n][j] = solve(n - 1, j - 1) % 1000000000 + solve(n - 1, j + 1) % 1000000000;
    dp[n][j] %= 1000000000;
    return dp[n][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;

    ll answer = 0;

    for (int i = 0; i <= 9; i++) {
        answer += solve(n, i);
        answer %= 1000000000;
    }

    cout << answer << " ";

    return 0;

  
}
