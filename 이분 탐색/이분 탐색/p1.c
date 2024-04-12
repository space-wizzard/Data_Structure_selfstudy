#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{type t=x;x=y;y=t;} while(0)

void SortArr(int arr[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = arr[(pl + pr) / 2];	//피벗

	do {
		while (arr[pl] < x)
			pl++;
		while (arr[pr] > x)
			pr--;
		if (pl < pr) {
			swap(int, arr[pl], arr[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr)
		SortArr(arr, left, pr);
	if (pl < right)
		SortArr(arr, pl, right);
}

void PrintArr(int* arr,int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}

int main() {
	int n;
	int k;
	int count = 0;
	scanf("%d%d", &n,&k);
	int* arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	SortArr(arr, 0, n - 1);
	PrintArr(arr, n);
	for (int i = 0; i < n; i++) {
		if (arr[i] >= k)
			break;
		count++;
	}
	printf("%d", count);
	free(arr);

	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type,x,y) do { type t=x;x=y;y=t;} while(0)
//struct array {
//	int* x;
//	int* rank;
//};
//
//void quick(struct array arr, int left, int right) {
//	int pl = left;
//	int pr = right;
//	int x = arr.x[(pl + pr) / 2];
//	for (int i = 0; i < pl + pr; i++) {
//		while (arr.x[pl] < x)
//			pl++;
//		while (arr.x[pr] > x)
//			pr--;
//		if (pl < pr) {
//			swap(int, arr.x[pl], arr.x[pr]);
//			swap(int, arr.rank[pl], arr.rank[pr]);
//			pl++;
//			pr--;
//			printf("%d %d\n", pl, pr);
//		}
//		if (left < pr)
//			quick(arr, left, pr);
//		if (pl < right)
//			quick(arr, pl, right);
//	}
//
//}
//
//int main() {
//	int nx;
//	printf("요소 입력:");
//	scanf("%d", &nx);
//	struct array arr;
//	arr.x = calloc(nx, sizeof(int));
//	arr.rank = calloc(nx, sizeof(int));
//	arr.rank[0] = 0;
//	for (int i = 0; i < nx; i++) {
//		printf("x[%d]:", i);
//		scanf("%d", &arr.x[i]);
//		arr.rank[i + 1] = arr.rank[i] + 1;
//	}
//	quick(arr, 0, nx - 1);
//	for (int i = 0; i < nx; i++) {
//		printf("%d\n", arr.rank[i]);
//	}
//	free(arr.x);
//
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//
//// 오름차순으로 정렬할 때 사용하는 비교함수
//int static compare (const void* first, const void* second)
//{
//    if (*(int*)first > *(int*)second)
//        return 1;
//    else if (*(int*)first < *(int*)second)
//        return -1;
//    else
//        return 0;
//}
//
//int main()
//{
//    int arr[] = {32, 11, 97, 42, 21, 70, 56, 67, 88, 100};
//    int array_size = sizeof(arr) / sizeof(int);
//    int i;
//
//    // 정렬 전
//    for (i = 0; i < array_size; i++) printf("%d ", arr[i]);
//    printf("\n");
//
//    qsort(arr, array_size, sizeof(int), compare);
//
//    // 정렬 후
//    for (i = 0; i < array_size; i++) printf("%d ", arr[i]);
//    printf("\n");
//
//    return 0;
//}