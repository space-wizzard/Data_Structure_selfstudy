#include <stdio.h>
#include <stdlib.h>

//void allocMemory(void** ptr, int size) {
//	*ptr = malloc(size);	//ptr�� �Լ��� ����� ���������̹Ƿ� ����� �� ����. ���������͸� ����� �Լ� �ۿ����� ����� �� �־�� �Ѵ�.
//}
//
//int main() {
//
//	long long* numptr;
//	allocMemory(&numptr, sizeof(long long));
//	*numptr = 10;
//	printf("%lld", *numptr);
//
//	free(numptr);
//}

// ���� ���Ḯ��Ʈ
//typedef struct node {
//	struct node* next;
//	int data;
//}Node;
//
//void addNode(Node* n2) {
//	Node* newnode = malloc(sizeof(Node));
//	n2->next = newnode;
//	newnode->data = 30;
//	newnode->next = NULL;
//}
//
//void removeNode(Node* n1) {	//node1�� next(n1->next)���� node2�� �ּҰ� ����ִ�. ���� node2�� data ���� 20�� �����ȴ�.
//	n1->next = n1->next->next;
//
//}
//
//struct node *findNode(Node* h,Node* n2) {
//	if (h == NULL)
//		return NULL;
//	Node* curr = h->next;	//h->next�� ù���� ��尡 �ִ� �ּ�...���⼭���� ��带 ã�� �����Ѵ�.
//	while (curr != NULL) {
//		if (curr == n2) {
//			return curr;
//		}
//		curr = curr->next;
//	}
//	return NULL;
//}
//
//int main() {
//	Node* find;
//	Node* head = malloc(sizeof(Node));
//
//	Node* node1 = malloc(sizeof(Node));
//	head->next = node1;
//	node1->data = 10;
//
//	Node* node2 = malloc(sizeof(Node));
//	node1->next = node2;
//	node2->data = 20;
//	node2->next = NULL;
//
//	addNode(node2);
//	removeNode(node1);
//	Node* curr = head->next;
//	find=findNode(head,node2->next);
//	while (curr != NULL) {
//		printf("%d\n", curr->data);
//		curr = curr->next;
//	}
//
//	if (find == NULL) {
//		printf("Not found");
//	}
//	else {
//		printf("%d\n", find->data);
//	}
//
//	free(head);
//	free(node1);
//	free(node2);
//
//	
//	return 0;
//}

 //�ݺ� ���� ����Ʈ
typedef int Index;	//int�� ������ Index�� �� �� �ִ�.

typedef struct node {
	struct node* next;
	//Index arrayindex;
	int data;
}Node;

void addNode(Node* n2) {
	Node* newnode = malloc(sizeof(Node));
	n2->next = newnode;
	newnode->data = 30;
	newnode->next = NULL;
}

void removeNode(Node* n1) {	//node1�� next(n1->next)���� node2�� �ּҰ� ����ִ�. ���� node2�� data ���� 20�� �����ȴ�.
	n1->next = n1->next->next;
}

struct node* findNode(Node* h, Node* n2) {
	if (h == NULL)
		return NULL;
	Node* curr = h->next;	//h->next�� ù���� ��尡 �ִ� �ּ�...���⼭���� ��带 ã�� �����Ѵ�.
	while (curr != NULL) {
		if (curr == n2) {
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

int main() {
	int n;
	int num;
	scanf("%d", &n);
	Node* find;
	Node* head = malloc(sizeof(Node));

	Node* node1 = malloc(sizeof(Node));
	head->next = node1;
	node1->data = 10;
	for (int i = 0; i < n; i++) {
		Node* prev=head->next;
		Node* newnode = malloc(sizeof(Node));
		prev->next = newnode;
		scanf("%d", &num);
		newnode->data = num;	//newnode(��� �ּ�)�� node->data(������)�� ���� ���... �ٸ� prev->next�� newnode�� ����Ǿ� �־ newnode�� �ϳ� ���� ����
	}

	/*Node* node2 = malloc(sizeof(Node));
	node1->next = node2;
	node2->data = 20;
	node2->next = NULL;*/

	/*addNode(node2);
	removeNode(node2);*/
	Node* curr = head->next;
	
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	/*find = findNode(head, node2->next);
	if (find == NULL) {
		printf("Not found");
	}
	else {
		printf("%d\n", find->data);
	}*/

	free(head);
	free(node1);
	//free(node2);


	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node {
//	int data;
//	Node* next;
//}Node;
//
//typedef struct {
//	Node* head;			//�Ӹ� ����� ������
//	Node* crnt;			//������ ����� ������
//}List;
//
//Node* CreateNode(List* list,Node* node) {
//	if (list->head == NULL) {
//		node->next = (Node*)malloc(sizeof(node));
//		return node->next;
//	}
//	/*else {
//		Node* curr = malloc(sizeof(node));
//		while (curr->next != NULL) {
//
//		}
//	}*/
//}
//
//List* AppendNode(List* list, Node* node) {
//	int n;
//	if (list->head = NULL) {
//		list->head = CreateNode(list, node);
//		list->head = node;
//		node->data = scanf_s("%d", &n);
//		list->crnt = list->head;
//		return list->crnt;
//	}
//	Node* ptr = list->head;
//	while (node->next != NULL) {
//
//		ptr = ptr->next;
//	}
//	
//}
//int main() {
//	List* list = (List*)malloc(sizeof(List));
//	Node* node = (Node*)malloc(sizeof(Node));
//	AppendNode(list, node);
//}