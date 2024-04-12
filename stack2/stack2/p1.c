////�迭�� �̿��� ���� ����
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//	int max;//���� �ִ� �뷮
//	int ptr;// ���� ������(���ÿ� �׿� �ִ� ������ ����)
//	int* stk;// ������ ����Ű�� ������(�������� Ǫ�ó� �˵� �����͵��� ������ �뵵�� �迭�� ����Ű�� ������), �Ʒ��� ������ �迭 x�� ��ü �����͸� ����ִ� �뵵
//}stack;
//
//int Initialize(stack* p, int max) {
//	p->ptr = 0;
//	p->max = max;
//	p->stk = calloc(p->max, sizeof(double));
//	if (p->stk == NULL)
//		return -1;
//	return 0;
//}
//
//int Push(stack* p, int* x) {
//	if (p->ptr >= p->max) {
//		return -1;
//	}
//	p->stk[p->ptr++] = *x;
//	return 0;
//}
//
//int Pop(stack* p, int* x) {
//	if (p->stk <= 0) {
//		return -1;
//	}
//	*x = p->stk[--p->ptr];
//	return *x;
//}
//void Clear(stack* p) {
//	free(p->stk);
//	p->stk = NULL;
//	p->ptr = 0;
//}
//
//
//int main() {
//	int max;
//	printf("���� �� ����:");
//	scanf("%d", &max);//ũ��
//	
//	stack* p = malloc(sizeof(stack));
//	int* x = calloc(max, sizeof(double));
//
//	for (int i = 0; i < max; i++) {
//		Initialize(p, max);
//		printf("����#%d\n", i + 1);
//		for (int j = 0; j < max; j++) {
//			printf("������ �Է�:");
//			scanf("%d", x + j);
//			Push(p, x + j);
//		}
//		for (int i = 0; i < max; i++) {
//			int popvalue = Pop(p, x+i);
//			if (popvalue == -1) {
//				printf("stack is empty");
//			}
//			else {
//				printf("����#%d:%d\n", i + 1, popvalue);
//			}
//		}
//		
//		Clear(p);
//		
//	}
//	free(p);
//	free(x);
//}
//

//��������
//�ϳ��� �迭�� �����Ͽ� �迭�� ó���� ���� ����� 2���� ������ �����ϴ� ���� ���α׷��� ���弼��.

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//	int ptr;
//	int* stk;
//}stack;
//
//int Initialize(int m,stack* p) {
//	p->stk = calloc(m, sizeof(int));
//	p->ptr = 0;
//	return 0;
//}
//
//int FPush(int m, stack* p,int *x) {
//	if (p->ptr > m) {
//		return -1;
//	}
//	for (int j = m / 3; j < 2 * m / 3; j++) {
//			printf("Input number:");
//			scanf("%d", p->stk + j);
//			*x = p->stk[++p->ptr];
//	}
//		
//	
//	return 0;
//}
//
//
//�ڿ��� ��� �Ҵ�
//
//int main() {
//	int max;
//	int* x;
//	stack* p = malloc(sizeof(int));
//	do {
//		printf("�迭�� �� ����(3�� ���):");
//		scanf("%d", &max);
//	} while (max % 3 != 0);
//
//	x = calloc(max, sizeof(int));
//	Initialize(max, p);
//	for (int i = 0; i < max / 3; i++) {
//		printf("�迭 ��� �Է�:");
//		scanf("%d", x + i);
//		p->ptr = i;
//	}
//	printf("%d\n", p->ptr);
//	FPush(max, p, x);
//	�ڿ��� ��� �Ҵ�
//
//	for (int i = 0; i < max; i++) {
//		printf("%d\n", p->stk+i);
//	}
//}





// ���Ḯ��Ʈ(������)�� �̿��� ����

#include <stdio.h>
#include <stdlib.h>

struct stk {
	int data;
	struct stk* node ;
};


struct stk* Initialize(struct stk* curr,int data) {
	if (curr->node == NULL) {
		curr->node = malloc(sizeof(struct stk));// ù��° ���(���), �����ʹ� �Ʊ� 0 ����(��ǻ� �ǹ̾��� ����)
		curr->data = data;
		curr->node->node = NULL;
		return curr->node;
	}
	else {
		while (curr->node!= NULL) {
			curr = curr->node;
		}
		curr->node = malloc(sizeof(struct stk));// �̰Ŷ� �ؿ� ���̶� ��� ��ġ�� �޶� �������� ���� ������!!
		curr->node->data = data;
		curr->node->node = NULL;
		return curr->node;
	}
	
	
}


int main() {
	int data;
	struct stk* newnode=malloc(sizeof(struct stk));
	newnode->data = 0;
	newnode->node = NULL;
	for (int i = 0; i < 5; i++) {
		printf("Input data:");
		scanf("%d", &data);
		newnode=Initialize(newnode, data);
	}
	
	struct stk* curr = malloc(sizeof(struct stk));
	while (curr->node != NULL) {  // ���� ��尡 NULL�̸� ���� curr=curr->node�� ���� ���� �Ѿ ������ ����.
		curr = curr->node;
		printf("%d\n", curr->data);
	}
	
		curr = newnode;
		while (curr != NULL) {
			struct stk* tmp = curr;	// tmp�� ��带 ���ܵΰ�, �� tmp�� �����Ѵ�.
			curr = curr->node;		   // �Ժη� curr�� �ٷ� �����ϸ� curr�� ����Ǿ� �ִ� �ٸ� ��� ���� ������ �Ұ���������.
			free(tmp);
		}
	
}

