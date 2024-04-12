#include <stdio.h>
#include <stdlib.h>

void Order2(int num, int arr[],int sum) {
	int count = sum;
	for (int i = 0; i < num - sum; i++) {
		if (arr[i] > arr[i + 1]) {
			count++;
		}
		if (arr[i] <= arr[i + 1]) {
			printf("섞임");
			return;
		}
		if (count == num) {
			printf("내림차순");
			return;
		}
	}
}

void Order(int num, int arr[]) {
	int sum = 1;
	for (int i = 0; i < num - 1 ; i++) {
		if (arr[i] < arr[i + 1]) {	//오름차순
			sum++;
			}
		else {
			Order2(num, arr, sum);
			return;
		}
	}
	if (sum == num ) {
		printf("오름차순");
	}
	
}

int main() {
	int n;
	scanf("%d", &n);
	if (n > 100) {
		printf("종료\n다시 입력하세요.");
		scanf("%d", &n);
	}
	else {
		int* a = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		Order(n, a);

		free(a);
	}
	}



