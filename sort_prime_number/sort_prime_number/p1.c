//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int i, n;
//	int num;
//	printf("Input num:");
//	scanf("%d", &num);
//	int count = 0;//count ������ �ʱ�ȭ�ؾ� �Ѵ�.
//	int* prime = calloc(num, sizeof(int));
//	for (i = 2; i < num; i++) {//�ߺ� �ݺ������� ���� �ݺ������� break�� ����ϸ� ���� �ݺ����� Ż���ϰ� �ܺ� �ݺ����� ��� �����Ѵ�.
//		for (n = 2; n < i; n++) {
//			if (i % n == 0) {
//				count++;
//				prime[count - 1] = i;
//				break;
//			}
//		}
//	}
//	for (int k = 0; k <= count; k++) {
//		/*if (k = count) {
//			printf("%d��° �ռ���:%d\n", k, prime[k]);
//		}*/
//		printf("%d��° �ռ���:%d\n", k + 1, prime[k]);
//	}
//	printf("�ռ��� ����:%d", count);
//
//	free(prime);
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

void Sort(int count, int* prime,int i) {
	prime[count] = i;
}

int main() {
	int num;
	int count = -1;

	printf("Input scope:");
	scanf("%d", &num);
	int* prime = calloc(num, sizeof(int));
	printf("1~%d\n", num);
	for (int i = 1; i <= num; i++) {
		for (int n = 2; n < num - 1; n++) {
			if (i <= n) {
				break;
			}
			if (i % n == 0) {
				if (i == 2) {
					break;
				}
				count++;
				Sort(count, prime,i);
				break;
			}
		
		}
	}


	for (int i = 0; i < count; i++) {
		printf("%d\n", prime[i]);
	}

	
}


