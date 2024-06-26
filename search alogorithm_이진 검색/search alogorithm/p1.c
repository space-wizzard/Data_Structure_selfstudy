//#include <stdio.h>
//#include <stdlib.h>

//void Search(n, k, int* x) {
//		while(1) {
//			int i=0;
//			if (x[i]!=k) {
//				printf("검색 실패");
//			}
//			else {
//				printf("%d",x[i]);
//			}
//		}
//	}
//
//int main() {
//	int num, key;
//	puts("선형 검색:");
//	printf("요소 개수:");
//	scanf("%d", &num);
//	int* x = calloc(sizeof(int), num);
//	for (int i = 0; i < num; i++) {
//		printf("x[%d]:", i);
//		scanf("%d", &x[i]);
//	}
//	printf("검색값:");
//	scanf("%d", &key);
//	Search(num, key,x);
//
//	
//}
//정렬 안된 입력 데이터 정렬까지 완료! 이제 이진 검색으로 데이터 검색해보기!!
#include <stdio.h>
#include <stdlib.h>


void Checksort(int n, int* x) {
	int tmp = x[0];
	for (int j = n; j > 0; j--) {
		int count = 0;
		for (int i = 0; i < j - 1; i++) {//버블 정렬은(내림차순) 한 번 패스가 끝날 때마다 정렬된 데이터값이 하나씩 늘어난다.(패스는 데이터 하나가 정렬되는 과정)
			if (x[i] < x[i + 1]) {//따라서 j-1로 정렬의 대상이 되는 데이터 개수를 하나씩 줄이고 있다.
				tmp = x[i + 1];
				x[i + 1] = x[i];
				x[i] = tmp;
				count++;
			}
		}
		if (count == 0)//만약 count가 1이라면, 한번의 패스에서 정렬이 한번이라도 일어난 것이다.
			break;		//그러나 count가 0이라면, 한번의 패스에서 정렬이 한번도 일어나지 않았다.
	}
}

int Bin_Search(int n, int *x, int k) { //배열의 인덱스를 변수 start,end,middle로 했고, middle은 검색값에 따라 달라져서 while문 안에 있다.
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int middle = (start + end) / 2;
		if (x[middle] == k)
			return middle;

		else if (x[middle] < k) {
			start = middle + 1;//start하는 데이터의 위치가 middle로 바뀐다. middle은 검색 대상에서 제외되니까 +1
			if (start == end) {	//알고리즘을 계속 돌리다 보면 start,middle,end 값이 1씩 차이나는 때까지 온다. 그때는 그 3개의 인덱스 사이 어딘가에 검색값이 있을 것이란 소리다.
				printf("검색값이 x[%d]과 x[%d] 사이에 있습니다. ", middle, end);
			}
		}
			
		else {
			end = middle - 1;
			if (start + 1 == middle) {
				printf("검색값이x[%d]과 x[%d]사이에 있습니다.", start, middle);
			}		
		}	
	}
	return -1;
}

int main() {
	int n;
	printf("배열 개수 입력: ");
	scanf("%d", &n);
	int* x = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("배열 요소 입력:");
		scanf("%d", &x[i]);
	}
	Checksort(n, x);
	for (int i = 0; i < n; i++) {
		printf("%d\n", x[i]);
	}
	int key;
	printf("검색 대상:");
	scanf("%d", &key);
	int i=Bin_Search(n, x, key);
	if (i == -1)
		printf("검색에 실패했습니다.");
	else
		printf("검색값은 x[%d]에 있습니다.", i);
	free(x);
	return 0;
}




