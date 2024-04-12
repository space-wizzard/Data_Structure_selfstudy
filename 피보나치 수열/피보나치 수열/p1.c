#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int* arr,int index,int seq,int n) {
	
	arr[index + 2] = arr[index] + arr[index + 1];
	n++;
	if (seq == 1) {
		return arr[0];
	}
	if (seq == 2) {
		return arr[1];
	}
	if (n == seq) {
		return arr[index + 2];
	}
	
	return Fibonacci(arr, index + 1, seq, n);

}

int main() {
	int index = 0;
	int n = 2;
	int seq;
	scanf("%d", &seq);
	int* arr = calloc(seq,sizeof(int));
	arr[0] = 1;
	arr[1] = 1;
	printf("%d",Fibonacci(arr, index, seq, n));
}