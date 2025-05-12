#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int V_SIZE = 1025;
int arr[V_SIZE][V_SIZE];
int sum[V_SIZE][V_SIZE];
int n, m;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// 2차원 배열 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// 2차원 누적합
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum[i][j] = arr[i][j];
			if (i > 0) sum[i][j] += sum[i - 1][j];
			if (j > 0) sum[i][j] += sum[i][j - 1];
			if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
		}
	}


	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << sum[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	// 쿼리 처리
	// (x1, y1) ~ (x2, y2) 구간의 합
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == 1 && y1 == 1)
			cout << sum[x2 - 1][y2 - 1] << "\n";
		else if (x1 == 1)
			cout << sum[x2 - 1][y2 - 1] - sum[x2 - 1][y1 - 2] << "\n";
		else if (y1 == 1)
			cout << sum[x2 - 1][y2 - 1] - sum[x1 - 2][y2 - 1] << "\n";
		else
			cout << sum[x2 - 1][y2 - 1] - sum[x2 - 1][y1 - 2] - sum[x1 - 2][y2 - 1] + sum[x1 - 2][y1 - 2] << "\n";

	}

}