//�迭�� ��� �Ųٷ� �����ؼ� ����ϱ�(�Ųٷ� ����� ������ ������ ���� �����ؾ� ��!!)
//#include <stdio.h>
//#include <stdlib.h>
//
//void ArrayReverse(int n,int a[]) {
//	int temp;
//	for (int i = 0; i <= n-1; i++) {
//		temp = a[i];
//		a[i] = a[n-1 - i];
//		a[n-1 - i] = temp;
//	}
//}
//void ArrayPrint(int n, int a[]) {
//	for (int i = 0; i <= n - 1; i++) {
//		printf("��� ���:%d\n", a[i]);
//	}
//}
//
//int main() {
//	int n;
//	int* x;
//	printf("��� ���� �Է�:");
//	scanf("%d", &n);
//	x = calloc(n, sizeof(int));
//	for (int i = 0; i < n; i++) {
//		printf("��� �Է�:");
//		scanf("%d", &x[i]);
//	}
//	printf("\n");
//	ArrayPrint(n, x);
//	printf("\n");
//	ArrayReverse(n, x);
//	printf("\n");
//	ArrayPrint(n, x);
//	
//}

//#include <stdio.h>
//
//void reverseSortArray(int arr[], int size) {
//	for (int i = 0; i < size / 2; i++) {
//		int temp = arr[i];
//		arr[i] = arr[size - 1 - i];
//		arr[size - 1 - i] = temp;
//	}
//}
//
//int main() {
//	int arr[] = { 5, 2, 8, 3, 1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("Original Array: ");
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	reverseSortArray(arr, size);
//
//	printf("Reversed Sorted Array: ");
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//	int temp;
//	int a = 1;
//	int b = 2;
//	temp = a;
//	a = b;
//	b = temp;
//	printf("%d\n%d\n", a, b);//c������ = �� ����ϸ� ���׿��� �������� ���� �Ѿ�´�.
//}

//#include <stdio.h>
//
//void reverseSortArray(int* arr, int size) {
//	int* start = arr;
//	int* end = arr + size - 1;
//
//	while (start < end) {
//		int temp = *start;
//		*start = *end;
//		*end = temp;
//
//		start++;
//		end--;
//	}
//}
//
//int main() {
//	int arr[] = { 5, 2, 8, 3, 1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("Original Array: ");
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	reverseSortArray(arr, size);
//
//	printf("Reversed Sorted Array: ");
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//#include <stdio.h>
//
//void reverseSortArray(int* arr, int size) {
//	int* start = arr;//arr ������ �迭 �����ʹϱ� �ڵ����� �迭�� ù��° �ε����� �����ϰ� �ִ�.
//	int* end = arr + size - 1;//�ε��������� �����̶�� ���� �ȴ�. 
//  //�Ϲ������� c���� �������� ���� ������ ����ϰ� ���� �ʴ�.
//	//start(�Ųٷ� ���ĵǱ� ���� �ε����� �� ���� ���� �ε���)
//	//end(�Ųٷ� ���ĵǱ� ���� �ε����� �� ���� ���� �ε���)
//	while (start < end) {
//		int temp = *start;
//		*start = *end;
//		*end = temp;
//		
//		start++;//�ε����� ������ �߰���
//		end--;
//	}
//}
//
//int main() {
//	int arr[] = { 5, 2, 8, 3, 1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printf("Original Array: ");
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	reverseSortArray(arr, size);
//
//	printf("Reversed Sorted Array: ");
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void Reversearraysort(int* arr, int size) {
//	int* start = arr;
//	int* end = arr + size - 1;
//
//	while (start < end) {	//�Ұ�ȣ ��-> ���� ���̾�� ����� ���ư���.
//		int temp;
//		temp = *start;
//		*start = *end;
//		*end = temp;
//
//		start++;
//		end--;
//	}
//}
//
//void Findmax(int* arr,int size) {
//	int max = *arr;
//	for (int i = 0; i < size; i++) {
//		if (max < arr[i]) {
//			max = arr[i];
//			printf("%d\n", max);
//		}
//		
//	}
//	printf("�迭�� �ִ�:%d\n", max);
//}
//
//
//int main() {
//	int size;
//	printf("�迭�� ��� ��:");
//	scanf("%d", &size);
//	int* arr;
//	arr = calloc(size,sizeof(int));
//	for (int i = 0; i <= size - 1; i++) {
//		printf("��� �Է�:");
//		scanf("%d", &arr[i]);
//				
//	}
//	int j=0;
//	while (j<size) {
//		printf("%d ", arr[j]);
//		j++;
//	}
//	Reversearraysort(arr, size);
//	printf("\n");
//	for (int i = 0; i <= size - 1; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n\n");
//	Findmax(arr,size);
//	free(arr);
//}




