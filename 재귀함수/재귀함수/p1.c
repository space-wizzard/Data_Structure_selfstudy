//#include <stdio.h>
//#include <stdlib.h>
//


//int factorial(int n) {
//	if (n > 0) {
//		return n * factorial(n - 1);
//	}
//	else
//		return 1;
//}
//int main() {
//	int x;
//	scanf("%d", &x);
//	printf("%d",factorial(x));
//}

//void recur(int n) {
//	if (n > 0) {
//		recur(n - 1);		//recur(3);
//		printf("%d\n", n);	//4
//		recur(n - 2);		//recur(2);
//	}
//}
//
//int main() {
//	int x;
//	scanf("%d", &x);
//	recur(x);
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int pos[8];
//
//void print(void) {
//	for (int i = 0; i < 8; i++) {
//		printf("%2d", pos[i]);
//	}
//}
//
//void set(int i) {
//	for (int j = 0; j < 8; j++) {
//		pos[i] = j;
//		if (i == 7)
//			print();
//		else
//			set(i + 1);
//	}
//}
//
//int main() {
//	set(0);
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//#define swap(type,x,y) do{ type t=x;x=y;y=t;} while(0)
//
//void partition(int a[], int n) {
//	int pl = 0;
//	int pr = n - 1;
//	int x = a[n / 2];
//	
//
//	do {
//		while (a[pl] < x)
//			pl++;
//		while (a[pr] > x)
//			pr--;
//		if (pl <= pr) {
//			swap(int, a[pl], a[pr]);
//			pl++;
//			pr--;
//		}
//		printf("%d %d\n", pl, pr);
//	} while (pl <= pr);
//	printf("피벗의 값은 %d입니다.\n", x);
//	printf("피벗 이하의 그룹\n");
//	for (int i = 0; i <= pl - 1; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	
//
//		/*printf("피벗과 일치하는 그룹\n");
//		for (int i = pr + 1; i < pl - 1; i++) {
//			printf("%d ", a[i]);
//		}
//		printf("\n");*/
//		printf("피벗 이상의 그룹\n");
//		for (int i = pr + 1; i < n; i++) {
//			printf("%d ", a[i]);
//		}
//	
//	
//}
//
//int main() {
//	int nx;
//	printf("요소 개수:");
//	scanf("%d", &nx);
//	int* x = calloc(nx, sizeof(int));
//	for (int i = 0; i < nx; i++) {
//		printf("x[%d]:", i);
//		scanf("%d", &x[i]);
//	}
//	partition(x, nx);
//	free(x);
//	
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type,x,y) do { type t=x;x=y;y=t;} while(0)
//
//void quick(int a[], int left, int right) {
//	int pl = left;
//	int pr = right;
//	int x = a[(pl + pr) / 2];
//
//	do {
//		while (a[pl] < x)
//			pl++;
//		while (a[pr] > x)
//			pr--;
//		if (pl < pr) {
//			swap(int, a[pl], a[pr]);
//			pl++;
//			pr--;
//			printf("%d %d\n", pl, pr);
//		}
//	} while (pl <= pr);
//	if (left < pr)
//		quick(a, left, pr);
//	if (pl < right)
//		quick(a, pl, right);
//}
//
//int main() {
//	int nx;
//	printf("요소 입력:");
//	scanf("%d", &nx);
//	int* x = calloc(nx, sizeof(int));
//	for (int i = 0; i < nx; i++) {
//		printf("x[%d]:", i);
//		scanf("%d", &x[i]);
//	}
//	quick(x, 0, nx - 1);
//	for (int i = 0; i < nx; i++) {
//		printf("x[%d]=%d\n", i, x[i]);
//	}
//	free(x);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type,x,y) do { type t=x;x=y;y=t;} while(0)
//
//struct node {
//	int x;
//	int rank;
//	struct node* next;
//};
//
//struct node* Initialize(int nx) {
//	struct node* head = NULL;							//head node
//	
//	struct node* current = NULL;	//사실 else에서 head->next로 계속 이어나가도 되는데 변수명이 헷갈릴까봐 current로 바꿨다.
//	// 그리고 return할 때 가장 첫번째 노드를 넘겨야 밑에서 노드 값들을 처음부터 출력할 수 있다.
//	for (int i = 0; i < nx; i++) {
//		struct node* newnode = malloc(sizeof(struct node));	//new node
//		scanf("%d", &newnode->x);
//		//newnode->next = NULL;
//
//		if (head == NULL) {
//			head = newnode;
//			current = head;
//		}
//		else {
//			current->next = newnode;
//			current = current->next;
//		}		
//	}
//	return head;
//}
//
//struct node* ReverseNode(struct node* current) {
//	if (current == NULL || current->next == NULL) {
//		return current;
//	}
//	struct node* rest = ReverseNode(current->next);
//	current->next->next = current;
//	current->next = NULL;
//	return rest;
//}
//
//
//void QuickSort(struct node* head,int left,int right) {
//	struct node* current = head;
//	struct node* fix = head;
//	struct node* reverse = NULL;
//	for (int i = 0; i < right / 2 || right + 1 / 2; i++) {
//		current = current->next;
//	}
//	int pivot = current->x;
//	for (int i = right / 2 || right + 1 / 2; i <= right; i++) {
//		current = current->next;
//	}
//	int leftcount = left;
//	int rightcount = right;
//	do {
//		while (left < pivot) {
//			fix = fix->next;
//			leftcount++;
//		}
//		while (right > pivot) {
//			reverse=ReverseNode(current);
//			rightcount--;
//		}
//		if (leftcount <= rightcount) {
//			swap(struct node*, fix, reverse);
//			leftcount++;
//			rightcount--;
//		}
//		fix = fix->next;
//		ReverseNode(current);
//	} while (leftcount <= rightcount);
//	if (left < rightcount)
//		QuickSort(fix, left, rightcount);
//	if (leftcount < right)
//		QuickSort(reverse, leftcount, right);
//}
//int main() {
//	int nx;
//	printf("요소 입력:");
//	scanf("%d", &nx);
//	struct node* n = NULL;
//	n = Initialize(nx);
//
//	QuickSort(n, 0, nx - 1);
//
//	struct node* current = n;
//	for (int i = 0; i < nx; i++) {
//		printf("%d\n",current->x);
//		current = current->next;
//	}
//
//	current = n;
//	struct node* temp = NULL;
//	while (current != NULL) {
//		temp = current;
//		current = current->next;
//		free(temp);
//	}
//
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct node {
    int x;
    struct node* next;
};

// Function to initialize a linked list with nx nodes
struct node* Initialize(int nx) {
    struct node* head = NULL;
    struct node* current = NULL;

    for (int i = 0; i < nx; i++) {
        struct node* newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->x);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            current = head;
        }
        else {
            current->next = newnode;
            current = current->next;
        }
    }
    return head;
}


struct node* ReverseNode(struct node* current) {
    struct node* prev = NULL;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void QuickSort(struct node** head, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = left + (right - left) / 2;
    struct node* pivotNode = *head;
    for (int i = left; i < pivotIndex; i++) {
        pivotNode = pivotNode->next;
    }
    int pivotValue = pivotNode->x;

    struct node* current = *head;
    struct node* less = NULL;
    struct node* equal = NULL;
    struct node* greater = NULL;

    while (current != NULL) {
        struct node* next = current->next;
        if (current->x < pivotValue) {
            current->next = less;
            less = current;
        }
        else if (current->x == pivotValue) {
            current->next = equal;
            equal = current;
        }
        else {
            current->next = greater;
            greater = current;
        }
        current = next;
    }

    QuickSort(&less, left, pivotIndex - 1);
    QuickSort(&greater, pivotIndex + 1, right);

    if (less != NULL) {
        *head = less;
        while (less->next != NULL) {
            less = less->next;
        }
        less->next = equal;
    }
    else {
        *head = equal;
    }

    if (equal != NULL) {
        while (equal->next != NULL) {
            equal = equal->next;
        }
        equal->next = greater;
    }
    else {
        *head = greater;
    }
}


void PrintList(struct node* head) {
    while (head != NULL) {
        printf("%d\n", head->x);
        head = head->next;
    }
}


void FreeList(struct node* head) {
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int nx;
    printf("요소 입력: ");
    scanf("%d", &nx);

    struct node* n = Initialize(nx);
    struct node** head = &n;

    QuickSort(head, 0, nx - 1);

    printf("정렬된 리스트:\n");
    PrintList(*head);

    FreeList(*head);

    return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//
//void Num(int n) {
//	printf("%d\n", n);
//	if (n == 1)
//		return;
//
//	if (n % 2 == 1)
//		Num(3 * n + 1);
//
//	else 
//		Num(n / 2);
//	
//	
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	Num(n);
//
//}