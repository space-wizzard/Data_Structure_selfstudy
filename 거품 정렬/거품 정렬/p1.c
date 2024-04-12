#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int count = 0;
	int result = 0;
	scanf("%d\n", &n);
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++;
			}
		}
		if (count == 0) {
			break;
		}
		count = 0;
		result++;
	}
	printf("%d", result);
	free(arr);
	return 0;
}