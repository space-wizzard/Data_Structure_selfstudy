#include <stdio.h>
#include<stdlib.h>

//Conversenum(int num[],int k[]) {//�迭�� �Լ��� �Ű������� ������ ���� ������ �������� ���޵Ǳ� ������ int num[] �̳� int*num �������� ������ �޾ƾ� �Ѵ�.
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < k[i]; j++) {
//			int* temp = calloc(k[i], sizeof(int));
//			//�ߴ�
//		}
//
//
//	}
//}
//
//
//	int main() {
//		int num[5] = { 0, };
//		int t[5] = { 0, };
//		int sum=0;
//		printf("Input number:");
//		for (int i = 0; i < 5; i++) {
//			scanf("%d", &num[i]);
//		}
//		for (int i = 0; i < 5; i++) {
//			while (1) {
//				int temp= num[i] % 2;
//
//				sum++;
//				if (temp == 0 || temp == 1) {
//					break;
//				}
//				for (int i = 0; i < 5; i++) {
//					
//					t[i] = sum;
//				}
//				sum = 0;
//			}
//		}
//		
//		Conversenum(num,t);
//
//}
//10����->16���� ��ȯ
int main() {
	char a[6] = "ABCDEF";
	int b[10] = {0,1,2,3,4,5,6,7,8,9};
	int num;
	printf("Input number:");
	scanf("%d", &num);
	int remainder = num % 16;
	int d = num / 16;
	if (remainder < 10) {
		printf("0x%d%d",d, remainder);
	}
	if (remainder >= 10) {
		printf("0x%d%c", d, a[remainder - 10]);
	}
}
	

