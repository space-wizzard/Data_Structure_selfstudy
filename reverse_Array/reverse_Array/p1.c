//배열의 요소 거꾸로 정렬해서 출력하기(거꾸로 출력은 쉽지만 정렬은 조금 생각해야 함!!)
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
//		printf("요소 출력:%d\n", a[i]);
//	}
//}
//
//int main() {
//	int n;
//	int* x;
//	printf("요소 개수 입력:");
//	scanf("%d", &n);
//	x = calloc(n, sizeof(int));
//	for (int i = 0; i < n; i++) {
//		printf("요소 입력:");
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
//	printf("%d\n%d\n", a, b);//c언어에서는 = 을 사용하면 우항에서 좌항으로 값이 넘어온다.
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
//	int* start = arr;//arr 변수는 배열 포인터니까 자동으로 배열의 첫번째 인덱스를 지정하고 있다.
//	int* end = arr + size - 1;//인덱스끼리의 덧셈이라고 보면 된다. 
//  //일반적으로 c언어에선 포인터의 덧셈 연산을 허락하고 있지 않다.
//	//start(거꾸로 정렬되기 전의 인덱스들 중 가장 앞의 인덱스)
//	//end(거꾸로 정렬되기 전의 인덱스들 중 가장 뒤의 인덱스)
//	while (start < end) {
//		int temp = *start;
//		*start = *end;
//		*end = temp;
//		
//		start++;//인덱스가 앞으로 추가됨
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
//	while (start < end) {	//소괄호 안-> 저게 참이어야 제어문이 돌아간다.
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
//	printf("배열의 최댓값:%d\n", max);
//}
//
//
//int main() {
//	int size;
//	printf("배열의 요소 수:");
//	scanf("%d", &size);
//	int* arr;
//	arr = calloc(size,sizeof(int));
//	for (int i = 0; i <= size - 1; i++) {
//		printf("요소 입력:");
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




