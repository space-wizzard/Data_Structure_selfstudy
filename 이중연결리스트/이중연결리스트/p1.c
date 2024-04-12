////연결리스트 색다른 방법으로
//#include <stdio.h>
//#include <stdlib.h>
//
//struct ListNode {
//	int data;
//	struct ListNode* next;
//};
//
//int ListLength(struct ListNode* head) {
//	struct ListNode* current = head;
//	int count = 0;
//	while (current != NULL) {
//		count++;
//		current = current->next;
//	}
//	return count;
//}
//
//
//void CreateNode(struct ListNode** head,int n) {
//	if (n == 0)
//		return;
//	*head = (struct ListNode*)malloc(sizeof(struct ListNode));
//	scanf("%d", &(*head)->data);
//	(*head)->next = NULL;
//	CreateNode(&(*head)->next, n - 1);
//}
//
//void InsertInLinkedList(struct ListNode** head) {
//	int data, position;
//	printf("Input data, position:");
//	scanf("%d%d", &data, &position);
//	int k = 1;
//	struct ListNode* p, * q, * newNode;
//	newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (!newNode) {
//		printf("Memory Error");
//		return;
//	}
//	newNode->data = data;
//	p = *head;
//	if (position == 1) {
//		newNode->next = p;
//		*head = newNode;
//	}
//	else {
//		while (p != NULL && k <= position - 1) {
//			k++;
//			q = p;	//q는 이전 노드
//			p = p->next; //p는 현재 노드 
//		}
//		if (p == NULL) {	//q가 마지막 노드, p는 NULL 상태
//			q->next = newNode;
//			newNode->next = NULL;
//		}
//		else {	// q와 p 사이에 노드 삽입
//			q->next = newNode;	//q 다음 주소 newnode
//			newNode->next = p;  // newnode 다음 주소 p
//		}
//	}
//}
//
//void DeleteLinkedList(struct ListNode** head) {
//	int position;
//	printf("Input position:");
//	scanf("%d", &position);
//	int k = 1;
//	struct ListNode* p, *q;
//	p = *head;
//	if (position == 1) {	//처음 노드 삭제
//		p = *head;
//		*head = (*head)->next;
//		free(p);
//	}
//	else {
//		while (p != NULL&&k<=position-1) {
//			k++;
//			q = p;
//			p = p->next;
//		}
//		if (p == NULL) {	//잘못된 position(삭제할 노드 순서) 입력
//			printf("This was the last node");
//		}
//		else {				//사용자가 지정한 노드(position)... 중간 노드 삭제
//			q->next = p->next;
//			free(p);
//		}
//	}
//}
//
//
//
//void PrintNode(struct ListNode* head) {
//	struct ListNode* current = head;
//	while (current != NULL) {
//		printf("%d\n", current->data);
//		current = current->next;
//	}
//}
//
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	struct ListNode* head = NULL;
//	CreateNode(&head,n);
//	
//	int a;
//	printf("(1)InsertInLinkedList (2)DeleteLinkedList (3)ListLength");
//	scanf("%d", &a);
//	switch (a) {
//	case 1:
//		InsertInLinkedList(&head);
//		PrintNode(head);
//		break;
//	case 2:
//		DeleteLinkedList(&head);
//		PrintNode(head);
//		break;
//	case 3:
//		printf("%d\n", ListLength(head));
//		break;
//	default:
//		printf("default\n");
//		break;
//	}
//	
//	
//}

//이중 연결리스트

#include <stdio.h>
#include <stdlib.h>

struct DLLNode {
	int data;
	struct DLLNode* next;
	struct DLLNode* prev;
};

int ListLength(struct DLLNode* head) {
	struct DLLNode* current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

void DLLInsert(struct DLLNode** head, int data, int position) {
	int k = 1;
	struct DLLNode* temp, *newNode;
	newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
	newNode->data = data;
	if (position == 1) {
		newNode->next = *head;
		newNode->prev = NULL;
		(*head)->prev = newNode;
		*head = newNode;
	}
	temp = *head;
	while ((k <= position - 1) && (temp->next == NULL)) {
		temp = temp->next;
		k++;
	}
	if (temp->next == NULL) {
		newNode->next = NULL;
		newNode->prev = temp;
		temp->next = newNode;
	}
	else {
		newNode->next = temp->next;		//temp->next는 temp 다음 노드이다. 
		//temp 다음 노드 전에 newNode가 insert되므로 newNode->next가 temp->next를 가리키게 한다.
		newNode->prev = temp;
		temp->next->prev = newNode; // 위치 노드(temp) 다음 노드의 이전 포인터(prev)
		temp->next = newNode;
	}
}

void DLLDelete(struct DLLNode**head,int position) {
	struct DLLNode* temp, * temp2;
	temp = *head;
	int k = 1;

	if (position == 1) {
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return;
	}

	while ((k < position) && temp->next != NULL) {	//사용자 지정 노드에서 멈추거나 마지막 노드에서 멈추기
		temp = temp->next;
		k++;
	}

	if (temp->next == NULL) {
			temp2 = temp->prev;		//temp2는 삭제할 노드의 이전 노드
			temp2->next = NULL;		//temp2의 next를 NULL로 변환한다.
			free(temp);
	}
	else {
			temp2 = temp->prev;
			temp2->next = temp->next;
			temp->next->prev = temp2;
			free(temp);
	}
	return;
}

void CreateNode(struct DLLNode** head, int data, int n) {
	int newdata;
	struct DLLNode* newnode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
	if (!newnode) {
		printf("Memory allocation error.");
		return;
	}

	if (*head == NULL) {
		newnode->prev = NULL;
		newnode->data = data;
		newnode->next = (struct DLLNode*)malloc(sizeof(struct DLLNode));	//다음 노드에 미리 동적할당.. 안 그러면 계속 if(*head==NULL)로 들어감
		newnode->next->prev = newnode;		//미리 prev에 현재 노드를 넣어둠
		*head = newnode;
		scanf("%d", &newdata);
		CreateNode(&newnode->next, newdata, n - 1);
	}

	else {
		newnode->data = data;
		newnode->next = (struct DLLNode*)malloc(sizeof(struct DLLNode));	//다음 노드에 미리 동적할당.. 안 그러면 계속 if(*head==NULL)로 들어감
		newnode->next->prev = newnode;		
		if (n == 2) {
			int lastdata;
			scanf("%d", &lastdata);
			newnode->next->data = lastdata;
			newnode->next->next = NULL;
			*head = newnode;
			return;
		}
		*head = newnode;
		scanf("%d", &newdata);
		CreateNode(&newnode->next, newdata, n - 1);
	}

}

void PrintNode(struct DLLNode* p) {
	struct DLLNode* curr = p;
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

void Designate(struct DLLNode* p,int n) {
	if (n == 0)
		return;
	int insertdata, insertn, deleten;
	int a;
	printf("(1)InsertInLinkedList (2)DeleteLinkedList (3)ListLength");
	scanf("%d", &a);
	switch (a) {
	case 1:
		scanf("%d%d", &insertdata, &insertn);
		DLLInsert(&p, insertdata, insertn);
		PrintNode(p);
		break;
	case 2:
		scanf("%d", &deleten);
		DLLDelete(&p, deleten);
		PrintNode(p);
		break;
	case 3:
		printf("%d\n", ListLength(p));
		break;
	default:
		printf("default\n");
		break;
	}
	Designate(p, n-1);
}


int main() {
	struct DLLNode* p;
	int data,n;
	scanf("%d%d", &data, &n);
	CreateNode(&p, data, n);
	PrintNode(p);
	printf("Finish creating node.\n");
	Designate(p,n);
	
}