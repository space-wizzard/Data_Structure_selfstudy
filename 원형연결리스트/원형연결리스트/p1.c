#include <stdio.h>
#include <stdlib.h>

struct CLLNode {
	int data;
	struct CLLNode* prev;
	struct CLLNode* next;
};

int CircularListLength(struct CLLNode* head) {
	struct CLLNode* current = head;
	int count = 0;
	if (head == NULL) {
		return 0;
	}
	do {
		current = current->next;
		count++;
	} while (current != head);
	return count;
}

void InsertMiddle(struct CLLNode** head, int data,int position) {
	struct CLLNode* temp = *head;
	int k = 1;
	struct CLLNode* newnode = malloc(sizeof(struct CLLNode));
	newnode->data = data;

	while (k < position && temp->next != *head) {
		k++;
		temp = temp->next;
	}
	newnode->next = newnode;
	if (*head == NULL)
		*head = newnode;
	else {
		newnode->next = *head;
		newnode->prev = temp;
		temp->next = newnode;
	}
}

void PrintNode(struct CLLNode* head) {
	struct CLLNode* current = head;
	do  {
		printf("%d\n", current->data);
		current = current->next;
	} while (current != head);
}

void CreateCLLNode(struct CLLNode** head, int n) {
	static int count = 0;
	count++;
	struct CLLNode* newnode = malloc(sizeof(struct CLLNode));
	int data;
	scanf("%d", &data);
	if (count == 1) {
		newnode->prev = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->prev = (*head)->prev;
		newnode->next = *head;
		(*head)->prev->next = newnode;
		(*head)->prev = newnode;
	}
	newnode->data = data;
	if (n == 1) {
		/*struct CLLNode* temp = *head;
		while (temp = NULL) {
			temp = temp->prev;
		}
		newnode->next = temp;*/
		*head = newnode;
		printf("%d\n", (*head)->data); //1 출력... 결과적으로 1 2 3 4 5 순서로 출력됨
		return;
	}

	/*newnode->next = malloc(sizeof(struct CLLNode));
	newnode->next->prev = newnode;*/
	CreateCLLNode(&newnode->next, n - 1);
	*head = newnode;
	printf("%d\n", (*head)->data);	// 5,4,3,2,1 입력했더니 2 3 4 5 순서로 출력
}

int main() {
	struct CLLNode* curr=NULL;
	int n;
	scanf("%d", &n);
	CreateCLLNode(&curr, n);
	PrintNode(curr);
	printf("\n");
	InsertMiddle(&curr, 20, 3);
	PrintNode(curr);

}
//void InsertEnd(struct CLLNode** head, int data) {
//	struct CLLNode* temp = *head;
//	struct CLLNode* newnode = malloc(sizeof(struct CLLNode));
//	newnode->data = data;
//	while (temp->next != *head) {
//		temp = temp->next;
//	}
//	temp->next = newnode;
//	newnode->next = *head;
//}
//
//void InsertFirst(struct CLLNode** head, int data) {
//	struct CLLNode* temp = *head;
//	struct CLLNode* newnode = malloc(sizeof(struct CLLNode));
//	newnode->data = data;
//	while (temp->next != *head) {
//		temp = temp->next;
//		newnode->next = newnode;
//	}
//	temp->next = newnode;
//	newnode->next = *head;
//}
//#include <stdio.h>
//#include <stdlib.h>
//int Print(int n) {
//	int* num = calloc(6, sizeof(int));
//	static int i = 0;
//	if (n == 0)
//		return num;
//	else {
//		num[i] = Print(n - 1);
//		i++;
//	}
//}
//
//int main() {
//	int* num = calloc(6,sizeof(int));
//	Print(6);
//	for (int i = 0; i < 6; i++) {
//		printf("%d\n", num[i]);
//	}
//}\


