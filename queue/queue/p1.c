//#include <stdio.h>
//#include <stdlib.h>
//// �� ���� ������ �迭
//typedef struct {
//	int max;	// ť�� �ִ� ������ ����
//	int front;	// ť�� ù��° ����� �ε���
//	int rear;	// ť�� ������ ��� �ϳ� ���� �ε���
//	int num;	// ť�� ����� ���� ������ ����
//	int* que;	// ��ť�� �����͸� �����ϱ� ���� ť �� ��ü
//}IntQueue;
//
//int Initialize(IntQueue* q, int max) {	//�ʱ�ȭ �Լ�
//	q->num = q->front = q->rear = 6;
//	q->que = calloc(max, sizeof(int));
//	if (q->que == NULL) {	//ť�� calloc�Լ��� �迭 ��Ҹ� �ڵ� �Ҵ��ϴµ�[q->que = calloc(max, sizeof(int))], �� ���� NULL�̸� �迭 ����
//		q->max = 0;
//		return -1;
//	}
//	q->max = max;
//	return 0;
//}
//
//int Enque(IntQueue* q, int x) {
//	if (q->num > q->max) {
//		return -1;
//	}
//	else {
//		q->num++;
//		q->que[q->rear++] = x;
//		if (q->rear == q->max) {	//rear���� ť�� �ִ� �뷮 �ʰ� ���� �ڵ�
//			q->rear = 0;			// �� ���� �����̱� ������, �ε��� �ʱⰪ�� 0�� �ƴϴ�. ����, �ִ� �뷮�� ��� �ٽ� �ε���0���� ����ϴ� ��찡 ����� ���� ������ ���δ�.
//		}
//		if (q->num == q->max)
//			q->num = 0;
//		return 0;
//	}
//}
//
//int Deque(IntQueue* q,int* x) {
//	if (q->num <= 0) {
//		return -1;
//	}
//	else {
//		q->num--;
//		for (int i = 0; i < 7; i++) {
//			x[i] = q->que[q->front++];
//			if (q->front == q->max) {	//��������
//				q->front = 0;
//			}
//			if (q->num <= 0)
//				q->num = q->max;
//		}
//		
//		return 0;
//	}
//		
//}
//
//int main(void) {
//
//	IntQueue que;
//	if (Initialize(&que, 7) == -1) {
//		puts("ť ������ �����Ͽ����ϴ�.");
//		return -1;
//	}
//
//	int* x = calloc(7, sizeof(int));// ����ڰ� �Է��� ������ �����ϱ� ���ϰ� ���� �뵵 �� �̻� �� ���ϵ� �ƴϴ�.
//	for (int i = 0; i < 7; i++) {
//		printf("������ �Է�:");
//		scanf("%d", &x[i]);
//		Enque(&que, x[i]);
//	}
//
//	int* y = calloc(7, sizeof(int));
//	for (int i = 0; i < 7; i++) {
//		Deque(&que, y);
//	}
//	if (Deque(&que, y) == 0){
//		printf("%d\n%d\n%d\n", y[1], y[3], y[5]);
//	}
//	else {
//		puts("����");
//	}
//
//	free(que.que);
//	free(x);
//	free(y);
//	
//}
//

//���� ť
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int max;
	int front;
	int rear;
	int* que;
} IntQueue;

int Initialize(IntQueue* q,int max,int start) {
	q->front = q->rear = start;
	q->num = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}
	else {
		q->max = max;
		return 0;
	}
}

int Enque(IntQueue* q,int x) {
	
	if (q->rear == q->max) {
		q->rear = 0;
	}
	q->que[q->rear++] = x;
	q->num++;
	if (q->num == q->max) {	//��� �� ���ǹ� ��� �Լ� ȣ�� Ƚ�� ��ü�� max�� ���س��� ������ ť ���� ���� �帣���� ���� ���̴�.
		return -1;
	}

	return 0;
}

int Deque(IntQueue* q, int* y) {
	if (q->num <= 0) {
		return -1;
	}
		

	*y = q->que[q->front++];
	q->num--;
	

	
	if (q->front == q->max) {
		q->front = 0;
	}
		
	
	return 0;
}

int main() {
	IntQueue q;
	int max;
	int start;

	printf("ť�� �뷮,������: ");
	scanf("%d %d", &max, &start);
	int* x = calloc(max, sizeof(int));
	int y;
	if (Initialize(&q, max, start) == 0) {
		printf("���� ����\n");
	}
		

	else {
		printf("�迭 ���� ����\n");
		return -1;
	}
		
	for (int i = 0; i < max; i++) {
		printf("ť ��� �Է�: ");
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < max; i++) {
		Enque(&q, x[i]);
		printf("��� �Է� �Ϸ�!\n");
	}
	
	for (int i = 0; i < max; i++) {
		Deque(&q, &y);
		printf("��� ���� �Ϸ�! %d\n",y);
		
	}

	free(x);
	free(q.que);
	return 0;
	
}


