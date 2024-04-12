#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int A[], int n) {
	int v;
	int j;
	for (int i = 0; i < n - 1; i++) {
		v = A[i];
		j = i;
		while (A[j - 1] > v && j >= 1) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = v;
	}
}

int main() {
	int n[6] = { 0,4,3,2,1 };
	InsertionSort(n, 5);
	for (int i = 0; i++; i++) {
		printf("%d\n", n[i]);
	}
}