#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main(void) {
	char a[9][9] = { '.' };
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (a[i][j] == 'F')
						cnt++;
				}
			}
			else {
				if (j % 2 != 0) {
					if (a[i][j] == 'F')
						cnt++;
				}
			}
		}
	}
	
	cout << cnt;

	return 0;
}