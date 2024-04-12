#include <stdio.h>
#include<stdlib.h>

//Conversenum(int num[],int k[]) {//배열을 함수의 매개변수로 전달할 때는 포인터 형식으로 전달되기 때문에 int num[] 이나 int*num 형식으로 변수를 받아야 한다.
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < k[i]; j++) {
//			int* temp = calloc(k[i], sizeof(int));
//			//중단
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
//10진수->16진수 변환
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
	

