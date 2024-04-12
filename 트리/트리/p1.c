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
		prinf("(1)삽입 (2)삭제 (3)검색 (4)출력 (0)종료:");
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
	p->data = x;		//키 값
	p->left = left;		//왼쪽 포인터
	p->right = right;	//오른쪽 포인터
}

struct bnode* Add(struct bnode* p, int x) {
	if (p == NULL) {		//루트 노드가 NULL값일 때
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if (p->data == x)
		printf("%d는 이미 등록되어 있습니다.", x);
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
//			printf("등록되어 있지 않습니다.");
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
		//	puts("모든 노드 출력");
		//	PrintTree(root);
		}
		i++;
	} while (menu != TERMINATE);
	
	printf("%d", root);
}