//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int SuperSum(int k, int n) {
//
//}
//int main() {
//	int n;
//	int k;
//	while (scanf("%d %d", &k, &n) != EOF)
//		printf("%d\n", SuperSum(k, n));
//}
//
//static char memo[128][1024];
//
//void recur(int n) {
//	if (memo[n + 1][0] != '\0') {
//		printf("%s", memo[n + 1]);
//	}
//	else {
//		if (n > 0) {
//			recur(n - 1);
//			printf("%d", n);
//			recur(n - 2);
//		}
//		else { 
//			strcpy(memo[n + 1], " ");
//		}
//	}
//}
//int main() {
//	int x;
//	scanf("%d", &x);
//
//	recur(x);
//
//	return 0
//}

#include <stdio.h>

static char memo[128][1024];

void recur(int n) {
	if (memo[n + 1][0] != '\0') {
		printf("%s", memo[n + 1]);
	}
	else {
		if (n > 0) {
			recur(n - 1);
			printf("\n");
			printf("%d", n);
			printf("m\n");
			recur(n - 2);
		}
		/*else { 
			strcpy(memo[n + 1], " ");
		}*/
	}
}

int main() {
	recur(10);
}