////배열을 이용한 스택 구조
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//	int max;//스택 최대 용량
//	int ptr;// 스택 포인터(스택에 쌓여 있는 데이터 개수)
//	int* stk;// 스택을 가리키는 포인터(스택으로 푸시나 팝된 데이터들을 저장할 용도의 배열을 가리키는 포인터), 아래에 선언한 배열 x는 전체 데이터를 담아주는 용도
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
//	printf("스택 총 개수:");
//	scanf("%d", &max);//크기
//	
//	stack* p = malloc(sizeof(stack));
//	int* x = calloc(max, sizeof(double));
//
//	for (int i = 0; i < max; i++) {
//		Initialize(p, max);
//		printf("스택#%d\n", i + 1);
//		for (int j = 0; j < max; j++) {
//			printf("데이터 입력:");
//			scanf("%d", x + j);
//			Push(p, x + j);
//		}
//		for (int i = 0; i < max; i++) {
//			int popvalue = Pop(p, x+i);
//			if (popvalue == -1) {
//				printf("stack is empty");
//			}
//			else {
//				printf("스택#%d:%d\n", i + 1, popvalue);
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

//연습문제
//하나의 배열을 공유하여 배열의 처음과 끝을 사용해 2개의 스택을 구현하는 스택 프로그램을 만드세요.

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
//뒤에서 요소 할당
//
//int main() {
//	int max;
//	int* x;
//	stack* p = malloc(sizeof(int));
//	do {
//		printf("배열의 총 개수(3의 배수):");
//		scanf("%d", &max);
//	} while (max % 3 != 0);
//
//	x = calloc(max, sizeof(int));
//	Initialize(max, p);
//	for (int i = 0; i < max / 3; i++) {
//		printf("배열 요소 입력:");
//		scanf("%d", x + i);
//		p->ptr = i;
//	}
//	printf("%d\n", p->ptr);
//	FPush(max, p, x);
//	뒤에서 요소 할당
//
//	for (int i = 0; i < max; i++) {
//		printf("%d\n", p->stk+i);
//	}
//}





// 연결리스트(포인터)를 이용한 스택

#include <stdio.h>
#include <stdlib.h>

struct stk {
	int data;
	struct stk* node ;
};


struct stk* Initialize(struct stk* curr,int data) {
	if (curr->node == NULL) {
		curr->node = malloc(sizeof(struct stk));// 첫번째 노드(헤드), 데이터는 아까 0 대입(사실상 의미없는 숫자)
		curr->data = data;
		curr->node->node = NULL;
		return curr->node;
	}
	else {
		while (curr->node!= NULL) {
			curr = curr->node;
		}
		curr->node = malloc(sizeof(struct stk));// 이거랑 밑에 줄이랑 노드 위치는 달라도 논리적으로 같은 묶음임!!
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
	while (curr->node != NULL) {  // 다음 노드가 NULL이면 굳이 curr=curr->node로 다음 노드로 넘어갈 이유가 없다.
		curr = curr->node;
		printf("%d\n", curr->data);
	}
	
		curr = newnode;
		while (curr != NULL) {
			struct stk* tmp = curr;	// tmp에 노드를 남겨두고, 이 tmp를 해제한다.
			curr = curr->node;		   // 함부로 curr를 바로 해제하면 curr에 연결되어 있는 다른 노드 순차 해제가 불가능해진다.
			free(tmp);
		}
	
}

