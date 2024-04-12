//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int n;
//	scanf("%d\n", &n);
//	int* arr = calloc(n,sizeof(int));
//
//	for (int i = 0; i < n; i++) {
//		scanf("%d\n", &arr[i]);
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n-i-1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}			
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		int temp=i
//	}
//}

#include <stdio.h>
#include <stdlib.h>

struct schedule {
	char name;
	int year;
	int month;
	int day;
};

void Input(struct schedule** s,int n,struct schedule** arr) {
	for (int i = 0; i < n; i++) {
		arr[i] = NULL;
		scanf("%s %d %d %d", &((*s)->name),&((*s)->year),&((*s)->month),&((*s)->day));
		arr[i] = *s;
		/*arr[i]->name = s->name;
		arr[i]->year = s->year;
		arr[i]->month = s->month;
		arr[i]->day = s->day;*/
	}
	
}

int main() {
	int n;
	struct schedule** s;
	struct schedule** arr;	//배열을 선언하기 때문에 이중 포인터
	*s = malloc(sizeof(struct schedule));
	scanf("%d", &n);
	arr = calloc(n, sizeof(struct schedule));
	Input(s,n,arr);
	printf("%s", arr[0]->name);
	printf("%d", arr[0]->year); 
	printf("%d", arr[0]->month);
	printf("%d", arr[0]->day);

}