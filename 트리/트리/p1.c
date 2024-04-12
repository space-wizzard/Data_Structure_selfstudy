#include <stdio.h>
#include <stdlib.h>

struct bnode {
	int data;
	struct bnode* left;
	struct bnode* right;
};

typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT
}Menu;

Menu SelectMenu() {
	int ch;
	do {
		prinf("(1)���� (2)���� (3)�˻� (4)��� (0)����:");
		scanf("%d", &ch);
	} while (ch<TERMINATE || ch>PRINT);
	return (Menu)ch;
}
static struct bnode* AllocBinNode() {
	struct bnode* newnode;
	newnode = calloc(1, sizeof(struct bnode));
	return newnode;
}

struct bnode SetBinNode(struct bnode* p, int x, struct bnode* left, struct bnode* right) {
	p->data = x;		//Ű ��
	p->left = left;		//���� ������
	p->right = right;	//������ ������
}

struct bnode* Add(struct bnode* p, int x) {
	if (p == NULL) {		//��Ʈ ��尡 NULL���� ��
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if (p->data == x)
		printf("%d�� �̹� ��ϵǾ� �ֽ��ϴ�.", x);
	else if (p->data > x)
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;
}

//struct bnode* Search(struct bnode** p, int** x) {
//
//}

//int Remove(struct BinNode** root, int** x) {
//	struct BinNode* next;
//	struct BinNode** left;
//	struct BinNode** p = root;
//	while (1) {
//		if (*p == NULL) {
//			printf("��ϵǾ� ���� �ʽ��ϴ�.");
//			return -1;
//		}
//	
//	}
//}

//void PrintTree(struct BinNode** p) {
//
//}
int main() {
	struct BinNode* root = NULL;
	int* x = calloc(10, sizeof(root));
	Menu menu;
	
	for (int i = 0; i < 10; i++) {
		scanf("%d", x[i]);
	}
	do {
		int i = 0;
		struct BinNode* temp=NULL;
		switch (menu = SelectMenu()) {

		case ADD:
			root = Add(root, x[i]);

		//case REMOVE:
		//	Remove(&root, &x);
		//	break;

		//case PRINT:
		//	puts("��� ��� ���");
		//	PrintTree(root);
		}
		i++;
	} while (menu != TERMINATE);
	
	printf("%d", root);
}