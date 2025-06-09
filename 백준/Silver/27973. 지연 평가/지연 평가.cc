#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long int;
const int V_SIZE = 105;
int q;
int x, n;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> q;
	ll num = 1;
	ll d = 1;
	ll temp = 0;
	while (q--) {
		cin >> x;
		switch (x) {
		case 0:
			cin >> n;
			num += n;
			break;
		case 1:
			cin >> n;
			num *= n;
			if (d == 1) d = n;
			else d *= n;
			break;
		case 2:
			cin >> n;
			temp = n * d;
			num += temp;
			break;
		default:
			//continue;
			cout << num << "\n";
		}
		//cout << num << "\n";

	}
	return 0;
	
	
}