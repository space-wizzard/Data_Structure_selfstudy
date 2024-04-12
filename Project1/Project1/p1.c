#include <stdio.h>
#include <stdlib.h>
int A[] = { 0, };
int Function(int n) {
	if (n == 1) return;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			printf("*\n");
	Function(n - 3);
		

	}

int Print(int n) {
	if (n == 0) return 0;
	else {
		printf("%d\n", n);
		return Print(n - 1);
	}
}

void Binary(int n) {
	if (n < 1)
		printf("%s", A);
	else {
		A[n - 1] = 0;
		Binary(n - 1);
		A[n - 1] = 1;
		Binary(n - 1);
	}
}
int main() {
	//Function(4);
	/*int n=Print(4);
	printf("%d", n);*/
	Binary(4);
}