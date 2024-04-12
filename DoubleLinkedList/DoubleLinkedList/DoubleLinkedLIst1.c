#include "DoubleLinkedList1.h"

HeadNode* CreateLinkedList() {
	HeadNode* newnode = NULL;
	newnode = (HeadNode*)malloc(sizeof(HeadNode));
	newnode->head = NULL;
	return newnode;
}

ListNode* CreateNode() {
	ListNode* newnode=NULL;
	newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		printf("NULL");
		return NULL;
	}
		
	newnode->rlink = NULL;
	newnode->llink = NULL;
	printf("Newnode data?");
	scanf("%s", newnode->data);
	return newnode;
}

ListNode* SearchNode(HeadNode*L,char* x) {
	ListNode* curr = L->head;
	while (curr != NULL) {
		if (strcmp(curr->data, x) == 0)
			return curr;
		else
			curr = curr->rlink;
	}
	return NULL;
}


void InsertNode(HeadNode* L) {
	ListNode* left= NULL;
	ListNode* newnode = NULL;
	newnode = CreateNode();
	char x[10] = { 0, };
	printf("Target Node?");
	printf("Target ");
	scanf("%s", x);
	if (L->head == NULL) {		// ��� ��忡 �ƹ��͵� ���� ���(���Ḯ��Ʈ�� �ƹ��͵� ���� ��)
		L->head = newnode;	// �� ��带 ��� �����ͷ� ����
		printf("��� ��忡 �ƹ��͵� ���� ���\n");
	}
	else if (SearchNode(L, x) == NULL) {						// data x�� ���Ḯ��Ʈ�� ���� ��� ... ���Ḯ��Ʈ ó���� ����
		newnode->rlink = L->head;
		//newnode->rlink->llink = newnode;
		L->head = newnode;
		printf("data x�� ���Ḯ��Ʈ�� ���� ���\n");
	}
		
	else  {	// data x�� �ִ� ��� �ڿ� �����ϴ� ���
		left=SearchNode(L,x);
		if (left->rlink == NULL) {	// Ÿ�� ��尡 ���Ḯ��Ʈ�� ������ ����� ��� ... ���Ḯ��Ʈ �������� ����
			newnode->llink = left->rlink;
			left->rlink = newnode;
			printf("Ÿ�� ��尡 ���Ḯ��Ʈ�� ������ ����� ���\n");
		}		
		else {					// Ÿ�� ��尡 ���Ḯ��Ʈ �߰��� �ִ� ��� ... Ÿ�� ��� ������ ����
			newnode->rlink= left->rlink;
			left->rlink = newnode;
			newnode->llink = left;
			left->rlink->llink = newnode;
			printf("Ÿ�� ��尡 ���Ḯ��Ʈ ó���̳� �߰��� �ִ� ���\n");
		}
	}

}


void PrintList(HeadNode* L) {
	ListNode* curr = L->head;
	while (curr != NULL) {
		printf("%s\n", curr->data);
		curr = curr->rlink;
	}
	

}
