//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct person {	//struct ����ü �̸� ������ �Ŀ� ����ü ������ ������ �� ������ struct�� �ٿ���� �Ѵ�. 
//	//typedef struct ����ü �̸� ������ ����ü ������ ������ �� struct�� ������ �ʾƵ� �ȴ�.
//	char name[20];
//	int height;
//	double vision;
//}check;
//
//typedef struct {
//	char name[2];
//	int mame;
//}k;
//
//typedef struct person {
//	char nae[2];
//	int masef;
//}m;
//int main() {
//	struct person p1;
//	k p2;
//	m p3;
//
//}
//
//typedef struct {
//	char name[3];
//	int height;
//	double vision;
//}physicalcheck;
// Ű�� ��հ�



////�÷� ����
//int main() {
//	physicalcheck p1;
//	strcpy(p1.name[0], "�̼���");
//	strcpy(p1.name[1], "dgrg");
//	strcpy(p1.name[2], "geurgh");
//	int count=
//
//	
//}

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	int rank;
	struct node* next;
};

struct node* CreateNode() {
	struct node* head = malloc(sizeof(struct node));
	scanf("%d", &(head->data));
	head->rank = head->next = NULL;
	return head;
}

struct node* Initialize(int n, struct node** head) {	//��ͷ� �ϱ�
	struct node* newnode = CreateNode();

	if (*head == NULL) {
		(*head)->next = malloc(sizeof(struct node));
		(*head)->data = (*head)->rank = NULL;
		n--;
		Initialize(n, &(*head)->next);
	}
	else {
		struct node* current = (*head)->next;
		/*while (current->next != NULL) {
			current = current->next;
		}*/
		current = newnode;
		n--;
		if (n == 0)
			printf("%d", current);
		return 0;
		Initialize(n, &current);
	}

}

int main() {
	int n;
	scanf("%d", &n);
	struct nodes* node = malloc(n * sizeof(struct node));
	Initialize(n, &node);
	Ranking(&node);
}