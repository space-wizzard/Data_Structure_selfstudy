#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
};

struct Stack {
	int data;
	struct Stack* prev;
	struct Stack* next;
};

//struct Stack* Newnode(struct Stack** node,int n) {
//	static int count = 0;
//	count++;
//	*node = (struct Stack*)malloc(sizeof(struct Stack));
//	if (n == 1) {
//		(*node)->next = NULL;
//		scanf("%d", &(*node)->data);
//		return *node;
//	}
//	(*node)->next = malloc(sizeof(struct Stack));
//	(*node)->next->prev = *node;
//	scanf("%d", &(*node)->data);
//	if (count == 1) {
//		(*node)->prev = NULL;
//		return *node;
//	}
//	return *node;
//	
//}
//struct Stack* CreateStack(struct Stack** node,int n) {
//	if (n == 0)
//		return *node;
//	struct Stack* newnode = Newnode(&*node,n); 
//	CreateStack(newnode, n - 1);
//}
void PreOrder(struct BinaryTreeNode* root) {	//전위 탐색
	//뿌리 방문 후, 왼쪽, 오른쪽 부속 트리를 각각 탐색한다.
	if (root) {
		printf("%d", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//
//void Push(struct Stack* S, struct BinaryTreeNode* root) {
//	struct Stack* temp;
//	temp = malloc(sizeof(struct Stack));
//	if (!temp)
//		return NULL;
//	temp->data=
//}

void PreOrderNon(struct BinaryTreeNode* root,int n) {
	struct Stack* S=CreateStack(&S, n);
	while (1) {
		while (root) {
			printf("%d", root->data);
			Push(S, root);
		}
	}
}

int main() {
	struct BinaryTreeNode* n=malloc(sizeof(struct BinaryTreeNode));
	n->data = 3;

	PreOrder(n);
}