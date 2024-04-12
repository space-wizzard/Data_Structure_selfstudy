//#include <stdio.h>
//#include <stdlib.h>
//// 링 버퍼 모형의 배열
//typedef struct {
//	int max;	// 큐의 최대 데이터 개수
//	int front;	// 큐의 첫번째 요소의 인덱스
//	int rear;	// 큐의 마지막 요소 하나 뒤의 인덱스
//	int num;	// 큐에 저장된 현재 데이터 개수
//	int* que;	// 인큐한 데이터를 저장하기 위한 큐 그 자체
//}IntQueue;
//
//int Initialize(IntQueue* q, int max) {	//초기화 함수
//	q->num = q->front = q->rear = 6;
//	q->que = calloc(max, sizeof(int));
//	if (q->que == NULL) {	//큐에 calloc함수로 배열 요소를 자동 할당하는데[q->que = calloc(max, sizeof(int))], 이 값이 NULL이면 배열 실패
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
//		if (q->rear == q->max) {	//rear값이 큐의 최대 용량 초과 방지 코드
//			q->rear = 0;			// 링 버퍼 모형이기 때문에, 인덱스 초기값이 0이 아니다. 따라서, 최대 용량을 찍고 다시 인덱스0부터 출발하는 경우가 상당히 많을 것으로 보인다.
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
//			if (q->front == q->max) {	//마찬가지
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
//		puts("큐 생성에 실패하였습니다.");
//		return -1;
//	}
//
//	int* x = calloc(7, sizeof(int));// 사용자가 입력한 데이터 저장하기 편하게 만든 용도 그 이상 그 이하도 아니다.
//	for (int i = 0; i < 7; i++) {
//		printf("데이터 입력:");
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
//		puts("실패");
//	}
//
//	free(que.que);
//	free(x);
//	free(y);
//	
//}
//

//원형 큐
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
	if (q->num == q->max) {	//사실 이 조건문 없어도 함수 호출 횟수 자체를 max로 정해놨기 때문에 큐 값이 넘쳐 흐르지는 않을 것이다.
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

	printf("큐의 용량,시작점: ");
	scanf("%d %d", &max, &start);
	int* x = calloc(max, sizeof(int));
	int y;
	if (Initialize(&q, max, start) == 0) {
		printf("베열 생성\n");
	}
		

	else {
		printf("배열 생성 실패\n");
		return -1;
	}
		
	for (int i = 0; i < max; i++) {
		printf("큐 요소 입력: ");
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < max; i++) {
		Enque(&q, x[i]);
		printf("요소 입력 완료!\n");
	}
	
	for (int i = 0; i < max; i++) {
		Deque(&q, &y);
		printf("요소 제거 완료! %d\n",y);
		
	}

	free(x);
	free(q.que);
	return 0;
	
}


