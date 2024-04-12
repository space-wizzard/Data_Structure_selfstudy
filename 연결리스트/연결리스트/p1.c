#include <stdio.h>
#include <stdlib.h>

//void allocMemory(void** ptr, int size) {
//	*ptr = malloc(size);	//ptr은 함수를 벗어나면 지역변수이므로 사용할 수 없다. 이중포인터를 사용해 함수 밖에서도 사용할 수 있어야 한다.
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

// 선형 연결리스트
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
//void removeNode(Node* n1) {	//node1의 next(n1->next)에는 node2의 주소가 들어있다. 따라서 node2의 data 값인 20이 삭제된다.
//	n1->next = n1->next->next;
//
//}
//
//struct node *findNode(Node* h,Node* n2) {
//	if (h == NULL)
//		return NULL;
//	Node* curr = h->next;	//h->next는 첫번쨰 노드가 있는 주소...여기서부터 노드를 찾기 시작한다.
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

 //반복 연결 리스트
typedef int Index;	//int형 변수를 Index로 쓸 수 있다.

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

void removeNode(Node* n1) {	//node1의 next(n1->next)에는 node2의 주소가 들어있다. 따라서 node2의 data 값인 20이 삭제된다.
	n1->next = n1->next->next;
}

struct node* findNode(Node* h, Node* n2) {
	if (h == NULL)
		return NULL;
	Node* curr = h->next;	//h->next는 첫번쨰 노드가 있는 주소...여기서부터 노드를 찾기 시작한다.
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
		newnode->data = num;	//newnode(노드 주소)와 node->data(데이터)는 같은 노드... 다만 prev->next에 newnode가 저장되어 있어서 newnode가 하나 위에 있음
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
//	Node* head;			//머리 노드의 포인터
//	Node* crnt;			//선택한 노드의 포인터
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