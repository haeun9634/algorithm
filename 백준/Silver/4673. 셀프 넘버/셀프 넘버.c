#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int arr[10000] = { 0 };
int arr2[10000]={0};
int d(int n);
int main(void) {
	int n = 10000;
	int result,i=0;
	result=d(n);
	int j = 0; 
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= result; j++) {
			if (i == arr[j]) {
				arr2[i] = 1;
				j = result+1;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (arr2[i] != 1) {
			printf("%d\n", i);
		}
	}

	return 0;

}
int d(int n) {
	int i, j = 1;
	for (i = 1; i <= n; i++) {
		if (i <= 9) {
			arr[j] = i + i;
			j++;
		}
		else if (i <= 99) {
			arr[j] = i+ i / 10 + i % 10;
			j++;
		}
		else if (i <= 999) {
			arr[j] =i+ i / 10 / 10 + i / 10 % 10 + i % 10;
			j++;
		}
		else if (i <= 9999) {
			arr[j] =i+ i / 10 / 10 / 10 + i / 10 / 10 % 10 + i / 10 % 10 + i % 10;
			j++;
		}
		else if (i == 10000) {
			arr[j] = i+1;
		}
	}
	return j;
	
}