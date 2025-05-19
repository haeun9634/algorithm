#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

const int V_SIZE = 300005;
int n, k; 
int arr[V_SIZE];
using p = pair<int, int>;
vector <p> v;
int maxnum = 0, maxidx = 0;
int solve() {
	int ans = 0;
	int cnt = 1;
	for (int i = maxidx; i > 0; i--) {
		if (maxnum-cnt == arr[i - 1]) {
			cnt++;
		}
	}
	return n - cnt;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back({ i, arr[i]});
		if (arr[i] > maxnum) {
			maxnum = arr[i];
			maxidx = i;
		}
	}
	cout << solve();
}