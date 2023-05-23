#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int count = 0;
	int n, k;
	int s[100] = { 0 };
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	int min = s[0];
	for (int i = 1; i < n; i++) {
		if (s[i] < min) {
			min = s[i];
			printf("%d", min);
		}

	}
	int temp = k * (n / k + n % k) - n;
	for (int i = 0; i <  temp ; i++) {
		for (int i = 0; i < k; i++) {
			s[i] = min;
			printf("%d ", s[i]);
			count++;
			i = k;
		}
	}

	printf("\n");
	printf("%d", count);
	return 0;
}
