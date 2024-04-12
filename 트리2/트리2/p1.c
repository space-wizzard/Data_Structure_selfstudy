//#include <stdio.h>
//#include <stdlib.h>
//
//struct bnode {
//	int data;
//	struct bnode* left;
//	struct bnode* right;
//};
//
//typedef enum {
//	TERMINATE, ADD, REMOVE, SEARCH, PRINT
//}Menu;
//
//Menu SelectMenu() {
//	int ch;
//	do {
//		prinf("(1)���� (2)���� (3)�˻� (4)��� (0)����:");
//		scanf("%d", &ch);
//	} while (ch<TERMINATE || ch>PRINT);
//	return (Menu)ch;
//}
//static struct bnode* AllocBinNode() {
//	struct bnode* newnode;
//	newnode = calloc(1, sizeof(struct bnode));
//	return newnode;
//}
//
//struct bnode SetBinNode(struct bnode* p, int x, struct bnode* left, struct bnode* right) {
//	p->data = x;		//Ű ��
//	p->left = left;		//���� ������
//	p->right = right;	//������ ������
//}
//
//struct bnode* Add(struct bnode* p, int x) {
//	if (p == NULL) {		//��Ʈ ��尡 NULL���� ��
//		p = AllocBinNode();
//		SetBinNode(p, x, NULL, NULL);
//	}
//	else if (p->data == x)
//		printf("%d�� �̹� ��ϵǾ� �ֽ��ϴ�.", x);
//	else if (p->data > x)
//		p->left = Add(p->left, x);
//	else
//		p->right = Add(p->right, x);
//	return p;
//}
//
////struct bnode* Search(struct bnode** p, int** x) {
////
////}
//
////int Remove(struct BinNode** root, int** x) {
////	struct BinNode* next;
////	struct BinNode** left;
////	struct BinNode** p = root;
////	while (1) {
////		if (*p == NULL) {
////			printf("��ϵǾ� ���� �ʽ��ϴ�.");
////			return -1;
////		}
////		else if()
////	}
////}
//
////void PrintTree(struct BinNode** p) {
////
////}
//int main() {
//	struct BinNode* root = NULL;
//	int* x = calloc(10, sizeof(root));
//	Menu menu;
//
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", x[i]);
//	}
//	Add(root, &x);
//	/*do {
//		int i = 0;
//		struct BinNode* temp = NULL;
//		switch (menu = SelectMenu()) {
//
//		case ADD:
//			root = Add(root, x[i]);
//
//			case REMOVE:
//				Remove(&root, &x);
//				break;
//
//			case PRINT:
//				puts("��� ��� ���");
//				PrintTree(root);
//		}
//		i++;
//	} while (menu != TERMINATE);*/
//
//	printf("%d", root);
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct bnode {
//    int data;
//    struct bnode* left;
//    struct bnode* right;
//};
//
//typedef enum {
//    TERMINATE, ADD, REMOVE, SEARCH, PRINT,FREE
//} Menu;
//
//Menu SelectMenu() {
//    int ch;
//    do {
//        printf("(1)ADD (2)REMOVE (3)SEARCH (4)PRINT (0)TERMINATE");
//        scanf("%d", &ch);
//    } while (ch < TERMINATE || ch > PRINT);
//    return (Menu)ch;
//}
//
//static struct bnode* AllocBinNode() {
//    struct bnode* newnode;
//    newnode = calloc(1, sizeof(struct bnode));
//    return newnode;
//}
//
//struct bnode* SetBinNode(struct bnode* p,int x, struct bnode* left, struct bnode* right) {
//    int key;
//    p->data = x;        //Ű ��
//    p->left = left;     //���� ������
//    p->right = right;   //������ ������
//    return p;
//}
//
//struct bnode* Add(struct bnode* p,int x) {
//    if (p == NULL) {        //��Ʈ ��尡 NULL���� ��
//        p = AllocBinNode();
//        SetBinNode(p, x, NULL, NULL);
//    }
//    else if (p->data == x) {
//        printf("%d�� �̹� ��ϵǾ� �ֽ��ϴ�.", x);
//        return 0;
//    }
//    else if (p->data > x)
//        p->left = Add(p->left, x);
//    else
//        p->right = Add(p->right, x);
//    return p;
//}
//void Remove(struct bnode** root,int target) {
//    struct bnode** p = Search(root,target);     //���� ��带 p�� ����
//    struct bnode* next;
//    struct bnode** left;
//    struct bnode* temp;
//    if ((*p)->left == NULL) {
//        next = (*p)->right;
//    }
//    else {
//        left = &((*p)->left);
//        while (&(*left)->right != NULL) {
//            left = &(*left)->right;
//        }
//        next = *left;
//        *left = (*left)->right;
//        next->left = (*p)->left;
//        next->right = (*p)->right;
//    }
//    temp = *p;
//    *p = next;
//    free(temp);
//
//    return 0;
//}
//
//struct bnode* Search(struct bnode* root, int n) {
//    if (root = NULL)
//        return NULL;
//    else if (root->data == n)
//        return root;
//    else if (root->data > n)
//        Search(root->left, n);
//    else
//        Search(root->right, n);
//    return -1;
//}
//
//void Print(struct bnode* p) {
//    if (p != NULL) {
//        Print(p->left);
//        printf("%d", p->left->data);
//        Print(p->right);
//    }
//}
//
//void Free(struct bnode* p) {
//    if (p != NULL) {
//        Free(p->left);
//        Free(p->right);
//        free(p);
//    }
//}
//
//int main() {
//    struct bnode* root = NULL;
//    Menu menu;
//    int key;
//    int n;
//    int temp;
//    int target;
//    scanf("%d", &n);
//    int* x = calloc(n,sizeof(struct bnode));
//    do {
//        switch (menu) {
//            int count = -1;
//        case ADD:
//            for (int i = 0; i < n; i++) {
//                count++;
//                root = Add(root, x + count);
//            }
//            break;
//        case REMOVE:
//            scanf("%d", &target);
//            if (Search(root, target) == -1) {
//                printf("Wrong target. Input Again.");
//                scanf("%d", &target);
//            }
//            Remove(&root,target);
//            break;
//        case PRINT:
//            printf("Print All Nodes.");
//            Print(root);
//            break;
//        case SEARCH:
//            scanf("%d", &key);
//            temp=Search(root,key);
//            printf("%d", temp);
//            break;
//        case FREE:
//            Free(root);
//            break;
//        }
//    } while (menu != TERMINATE);
//   
//
//    return 0;
//}
//

#include <stdio.h>
#include <stdlib.h>
struct bnode {
    int data;
    struct bnode* left;
    struct bnode* right;
};

typedef enum {
    TERMINATE, ADD, REMOVE, SEARCH, PRINT, FREE
} Menu;

Menu SelectMenu() {
    int ch;
    do {
        printf("(1)���� (2)���� (3)�˻� (4)��� (5)���� (0)����:");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > FREE);
    return (Menu)ch;
}

static struct bnode* AllocBinNode() {
    struct bnode* newnode=malloc(sizeof(struct bnode));
    //newnode = calloc(1, sizeof(struct bnode));
    return newnode;
}

struct bnode* SetBinNode(struct bnode* p, int x, struct bnode* left, struct bnode* right) {
    p->data = x;        //Ű ��
    p->left = left;     //���� ������
    p->right = right;   //������ ������
    return p;
}

struct bnode* Add(struct bnode* p, int x) {
    if (p == NULL) {        //��Ʈ ��尡 NULL���� ��
        p = AllocBinNode();
        SetBinNode(p, x, NULL, NULL);   //�¿� ���� ���� NULL�� ���ܵα�...���� �Է°��� ũ�⿡ ���� �¿� ������
    }

    else if (p->data == x) {
        printf("%d�� �̹� ��ϵǾ� �ֽ��ϴ�.", x);
        return p;
    }

    else if (p->data > x)   // �߰��� ���� ���� ����� ������ ���� ���� ����
        p->left = Add(p->left, x);

    else
        p->right = Add(p->right, x);    //Ŭ ���� ������
    return p;
}

struct bnode* Search(struct bnode* root, int n) {
    if (root == NULL)
        return NULL;

    else if (root->data == n)
        return root;

    else if (root->data > n)
        return Search(root->left, n);

    else
        return Search(root->right, n);
}


void Remove(struct bnode** root, int target) {
    struct bnode* node = *root;
    struct bnode* parent = NULL;

   
    while (node != NULL && node->data != target) {          //���� ��� ã��
        parent = node;
        if (node->data > target)
            node = node->left;
        else
            node = node->right;
    }
  
    if (node->left == NULL && node->right == NULL) {        //���� ����� �ڽ� ��尡 0��
        if (parent == NULL) 
            *root = NULL;
        
        else if (parent->left == node) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
        free(node);
    }

    
    else if (node->left == NULL || node->right == NULL) {   // ���� ����� �ڽ� ��尡 1��
        struct bnode* child = (node->left != NULL) ? node->left : node->right;
        if (parent == NULL) {
            *root = child;
        }
        else if (parent->left == node) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }
        free(node);
    }
    
    else {                                                  //���� ����� �ڽ� ��尡 2��
        struct bnode* successor = node->right;
        parent = NULL;
        while (successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }
        node->data = successor->data;
        if (parent != NULL) {
            parent->left = successor->right;
        }
        else {
            node->right = successor->right;
        }
        free(successor);
    }
}


void Print(struct bnode* p) {
    if (p != NULL) {
        Print(p->left);
        printf("%d ", p->data);
        Print(p->right);
    }
}

void Free(struct bnode* p) {
    if (p != NULL) {
        Free(p->left);
        Free(p->right);
        free(p);
    }
}

int main() {
    struct bnode* root = NULL;
    Menu menu;
    int n;
    scanf("%d", &n);
    int* x = calloc(n, sizeof(struct bnode));

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        root = Add(root, x[i]);
    }
    //root�� ��Ʈ ���
    do {
        menu = SelectMenu();
        switch (menu) {
        case ADD:
            printf("Insert values: ");
            int value;
            scanf("%d", &value);
            root = Add(root, value);
            break;

        case REMOVE:
            printf("Remove target: ");
            int target;
            scanf("%d", &target);

            if (Search(root, target) == NULL) {
                printf("Wrong target. Input Again.\n");
            }

            else {
                Remove(&root, target);
                printf("%d removed.\n", target);
            }
            break;

        case PRINT:
            printf("Print All Nodes: ");
            Print(root);
            printf("\n");
            break;

        case SEARCH:
            printf("Search value: ");
            int key;
            scanf("%d", &key);
            struct bnode* result = Search(root, key);
            if (result != NULL) {
                printf("%d found.\n", key);
            }

            else {
                printf("%d not found.\n", key);
            }

            break;

        case FREE:
            Free(root);
            root = NULL;
            printf("Memory freed.\n");
            break;
        }
    } while (menu != TERMINATE);

    return 0;
}



//struct bnode* SearchParent(struct bnode* root, int n) {
//    struct bnode* prev = root;
//    if (root == NULL)
//        return NULL;
//
//    else if (root->data == n)
//        return prev;
//
//    else if (root->data > n) {
//        prev = root;
//        return SearchParent(root->left, n);
//    }
//
//    else {
//        prev = root;
//        return SearchParent(root->right, n);
//    }
//        
//}

//void Remove(struct bnode** root, int target) {
//    struct bnode* node = *root;
//    struct bnode* parent;
//    while (node->data != target) {                      //���� ��� ã��
//        parent = node;
//        if (node->data > target) {
//           
//            node = node->left;
//        }
//            
//        else {
//            
//            node = node->right;
//        }
//            
//        if (node == NULL) {
//            printf("No target.");
//            break;
//        }
//            
//    }    
//    
//    if (node->left == NULL && node->right == NULL) {    //���� ����� �ڽ� ��尡 0���� ��
//        if (parent->left == node)
//            parent->left = NULL;
//        if (parent->right == node)
//            parent->right = NULL;
//        free(node);
//    }
//    
//    else if (node->left == NULL || node->right == NULL) {
//        struct bnode* child;
//        if (parent->left==node) {
//           
//            parent->right = node->right;
//        }
//        else {
//            
//        }
//    }
//
//    
   // struct bnode** p = SearchParent(root, target);
   // struct bnode* next;
   // struct bnode** left;
   // struct bnode* temp;
   // if ((*p)->left == NULL) {
   //     next = (*p)->right;
   //     temp = *p;
   //     *p = next;
   //     free(temp);
   // }

   ///* else {
   //     left = &((*p)->left);
   //     while ((*left)->right != NULL) {
   //         left = &((*left)->right);
   //     }
   //     next = *left;
   //     *left = (*left)->left;
   //     next->left = (*p)->left;
   //     next->right = (*p)->right;
   // }*/
   // if ((*p)->right == NULL) {
   //     next = (*p)->left;
   //     temp = *p;
   //     *p = next;
   //     free(temp);
   // }
   // if ((*p)->left == NULL && (*p)->right == NULL) {
   //     free(*p);
   // }


//