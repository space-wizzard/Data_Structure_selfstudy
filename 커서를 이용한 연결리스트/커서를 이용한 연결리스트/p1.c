#include <stdio.h>
#include <stdlib.h>
#define NULL 0
// 프리 리스트: 사용하지 않는 노드를 관리하기 위한 자료 구조
typedef int Index;
typedef struct {
	int data;
	Index next;		//다음 노드
	Index Dnext;	// 프리 리스트의 다음 노드
}Node;

typedef struct {
	Index head;		// 머리 노드
	Index max;		// 사용 중인 프리 리스트의 꼬리 레코드
	Index deleted;	// 프리 리스트의 머리 커서
	Index crnt;		// 선택한 노드
	Node* n;		// 리스트 본체(배열)
}List;

void Initialize(List* list, int size) {
	list->n = calloc(size, sizeof(Node));
	list->head = NULL;
	list->max = NULL;
	list->deleted = NULL;
	list->crnt = NULL;
}

static Index GetIndex(List* list) {
	if (list->deleted == NULL) {
		return ++(list->max);
	}
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

void SetNode(Node* n, int d, Index next) {
	n->data = d;
	n->next = next;
}

void InsertFront(List* list,int data) {
	Index ptr = list->head;
	list->head =list->crnt= GetIndex(list);
	SetNode(&list->n[list->head], data, ptr);

}

int main() {
	List* list = malloc(sizeof(Node));
	int size;
	int data[10];	
	printf("Input Index size:");
	scanf_s("%d", &size);
	Initialize(list, size);
	for (int i = 0; i < 10; i++) {
		scanf("%d", data[i]);
		InsertFront(list, data[i]);
	}
	
}
