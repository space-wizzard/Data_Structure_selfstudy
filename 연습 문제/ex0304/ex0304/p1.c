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
				printf("%d�� x[%d]�� �ֽ��ϴ�.", key, pc);
				break;
			}
		} while (pl <= pr);
		

	
}


int main() {
	int n;	
	int key;
	printf("��� ������ �Է��ϼ���:");
	scanf("%d", &n);
	int* x = calloc(n, sizeof(int));
	printf("���ĵ� �����͸� �Է��ϼ��� x[0]:");
	scanf("%d", &x[0]);
	for (int i = 1; i < n; i++) {
		do {
			printf("������������ �Է��ϼ��� x[%d]:",i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);//��ȣ �� ���ǽ��� ���� �� ���� ����, �ٽ� ����.
		//x[i] < x[i+1] �� ���ǽ��̸�, x[i+1] ���� ���� ���� �𸣱� ������ ������ ������ �ʴ´�. �񱳸� �ϱ� ���ؼ� �̹� ����Ǿ� �ִ� �� ���� ������ �ؾ� �Ѵ�.
		
	}
	printf("�˻���:");
	scanf("%d", &key);
	
	Bin_Search(n,key,x);

	
}
