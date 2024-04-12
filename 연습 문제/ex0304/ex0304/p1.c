#include <stdio.h>
#include <stdlib.h>

int Bin_Search(int n, int key, int* x) {
	int pl = 0;
	int pr = n - 1;
	
		printf("   |");
	    for (int i = 0; i < n; i++) printf("%4d", i);
	    printf("\n---+");
		for (int i = 0; i < n; i++) printf("----");
	    printf("--\n");

		do {
			
			int pc = (pl + pr) / 2;
		
			printf("   |");
			for (int i = 0; i < 4 * pl; i++) {
				printf(" ");
			}
	        printf(" <-");
			for (int i = 0; i < 4 * (pc - pl); i++) {
				printf(" ");
					}
			printf("+");
			for (int i = 0; i < 4 * (pr - pc) ; i++) {
				printf(" ");
					}
			printf("->\n");
			printf("%d  |", pc);
			for (int i = 0; i < n; i++) {
				printf("%4d", x[i]);
			}
			printf("\n");
			if (x[pc] < key) {
				pl = pc + 1;
			}
			else if (x[pc] > key) {
				pr = pc - 1;
			}
			else {
				printf("%d는 x[%d]에 있습니다.", key, pc);
				break;
			}
		} while (pl <= pr);
		

	
}


int main() {
	int n;	
	int key;
	printf("요소 개수를 입력하세요:");
	scanf("%d", &n);
	int* x = calloc(n, sizeof(int));
	printf("정렬된 데이터를 입력하세요 x[0]:");
	scanf("%d", &x[0]);
	for (int i = 1; i < n; i++) {
		do {
			printf("오름차순으로 입력하세요 x[%d]:",i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);//괄호 안 조건식이 참일 때 루프 멈춤, 다시 진행.
		//x[i] < x[i+1] 이 조건식이면, x[i+1] 값이 아직 뭔지 모르기 때문에 루프가 멈추지 않는다. 비교를 하기 위해선 이미 저장되어 있는 두 수를 가지고 해야 한다.
		
	}
	printf("검색값:");
	scanf("%d", &key);
	
	Bin_Search(n,key,x);

	
}
