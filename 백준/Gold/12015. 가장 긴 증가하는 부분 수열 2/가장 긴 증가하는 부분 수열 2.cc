#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define V_SIZE 1000005

using namespace std;

int n;
vector <int> ans;
int arr[V_SIZE];

void solve(){
    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back()) ans.push_back(arr[i]);
        else {
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            *it = arr[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ans.push_back(arr[0]);
    solve();
  
    cout << ans.size();
    return 0;
}
