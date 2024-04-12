#include <stdio.h>
#include <stdlib.h>
#define NULL 0
// ���� ����Ʈ: ������� �ʴ� ��带 �����ϱ� ���� �ڷ� ����
typedef int Index;
typedef struct {
	int data;
	Index next;		//���� ���
	Index Dnext;	// ���� ����Ʈ�� ���� ���
}Node;

typedef struct {
	Index head;		// �Ӹ� ���
	Index max;		// ��� ���� ���� ����Ʈ�� ���� ���ڵ�
	Index deleted;	// ���� ����Ʈ�� �Ӹ� Ŀ��
	Index crnt;		// ������ ���
	Node* n;		// ����Ʈ ��ü(�迭)
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
