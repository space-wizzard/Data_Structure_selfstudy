//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	int rank;
//	struct node* next;
//};
//
//struct node* CreateNode() {
//	struct node* newnode = malloc(sizeof(struct node));
//	scanf("%d", &(newnode->data));
//	newnode->rank = 0; 
//	newnode->next = NULL;
//	return newnode;
//}
//
//struct node* Initialize(int n) {
//	if (n <= 0)
//		return NULL;
//	struct node* head = CreateNode();
//	head->next = Initialize(n - 1);
//	return head;
//}
//
//void Split(struct node* source, struct node** left, struct node** right) {
//	struct node* fast;
//	struct node* slow;
//	if (source == NULL || source->next == NULL) {
//		*left = source;
//		*right = NULL;
//	}
//	else {
//		slow = source;
//		fast = source->next;
//		while (fast != NULL) {
//			fast = fast->next;
//			if (fast != NULL) {
//				slow = slow->next;
//				fast = fast->next;
//			}
//		}
//		*left = source;
//		*right = slow->next;
//		slow->next = NULL;
//	}
//}
//
//struct node* Merge(struct node* left, struct node* right) {
//	if (left == NULL)
//		return right;
//	if (right == NULL)
//		return left;
//
//	struct node* result = NULL;
//	if (left->data <= right->data) {
//		result = left;
//		result->rank += 1;  // Increment rank when merging
//		result->next = Merge(left->next, right);
//	}
//	else {
//		result = right;
//		result->next = Merge(left, right->next);
//	}
//	return result;
//}
//
//void MergeSort(struct node** head) {
//	struct node* current = *head;
//	struct node* left;
//	struct node* right;
//
//	if (current == NULL || current->next == NULL)
//		return;
//
//	Split(current, &left, &right);
//	MergeSort(&left);
//	MergeSort(&right);
//
//	*head = Merge(left, right);
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	struct node* node = Initialize(n);
//
//	MergeSort(&node);
//
//	struct node* current = node;
//	while (current != NULL) {
//		printf("%d\n", current->rank);
//		current = current->next;
//	}
//
//	// Free allocated memory
//	current = node;
//	while (current != NULL) {
//		struct node* temp = current;
//		current = current->next;
//		free(temp);
//	}
//
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	int rank;
//	struct node* next;
//};
//
//struct node* CreateNode() {
//	struct node* head = malloc(sizeof(struct node));
//	scanf("%d", &(head->data));
//	head->rank = head->next = NULL;
//	return head;
//}
//
//struct node* Initialize(int n, struct node** head) {	//재귀로 하기
//	struct node* newnode = CreateNode();
//
//	if (*head == NULL) {
//		*head = newnode;
//		Initialize(n - 1, &(*head));	//반환값이 있는 함수인데 받아주는 변수가 있어야 한다!! 그러니까 위에 처럼 굳이 매개변수로 *head를 둘 필요가 없다.
//		//return *head;
//	}
//	else {
//		if (n == 0)
//			return 0;
//		(*head)->next = newnode;
//		Initialize(n - 1, &(*head)->next);
//		//return *head;
//	}
//
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	struct node* node = NULL;
//	Initialize(n, &node);
//
//	struct node* current = node;
//	while (current != NULL) {
//		printf("%d\n", current->data);
//		current = current->next;
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	int rank;
//	struct node* next;
//};
//
//struct node* CreateNode(int rank) {
//	struct node* head = malloc(sizeof(struct node));
//	scanf("%d", &(head->data));
//	head->next = NULL;
//	head->rank = rank;
//	return head;
//}
//
//
//struct node* Initialize(int n,int rank) {
//	if (n <= 0) {
//		return NULL;
//	}
//	struct node* newnode = CreateNode(rank);
//	newnode->next = Initialize(n - 1, rank + 1);
//	return newnode;
//
//}
//
//void Resort(struct node* node, int n) {
//	struct node* current = node;
//	struct node* temp;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - i; j++) {
//			if (current->data < current->next->data) {
//				current->next->rank++;
//				current->rank--;
//				temp = current;
//				current = current->next;
//				current->next = temp;
//			}
//			current = current->next;
//		}
//		current = node;
//	}
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	struct node* node = NULL;
//	node = Initialize(n,0);
//	Resort(node, n);
//
//	struct node* current = node;
//	while (current != NULL) {
//		printf("%d\n", current->rank);
//		current = current->next;
//	}
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	int rank;
//	struct node* next;
//};
//
//struct node* CreateNode() {
//	struct node* newnode = malloc(sizeof(struct node));
//	scanf("%d", &(newnode->data));
//	newnode->next = NULL;
//	newnode->rank = 0;
//	return newnode;
//}
//
//struct node* Initialize(int n) {
//	if (n <= 0) {
//		return NULL;	//마지막 노드에 NULL을 반환하고, 다시 newnode->next=Initialize(n-1,rank-1);로 복귀
//	}
//	struct node* newnode = CreateNode();	//현재 노드 생성
//	newnode->next = Initialize(n - 1);// 다음 노드를 재귀적으로 생성
//	return newnode;			// 가장 마지막에 생성된 노드의 포인터 반환(newnode->next에 NULL인 상태)
//}
//
//
//
//void Resort(struct node* node, int n) {
//	/*struct node* current = node;
//	struct node* fix = node;
//	for (int j = 0; j < n; j++) {
//		for (int i = 0; i < n; i++) {
//			if (fix->data > current->data) {
//				fix->rank++;
//			}
//			current = current->next;
//		}
//		fix = fix->next;
//		current = node;
//	}
//	*/
//	struct node* current = node;
//	struct node* fix = node;
//	int left = 0;
//	int right = n - 1;
//	for (int i = 0; i < n / 2 || n + 1 / 2; i++) {
//		current = current->next;
//	}
//	int x = current->data;
//	do {
//		while (fix->data < x)
//			fix = fix->next;
//		while (fix->data > x)
//			fix = fix->next;
//		if()
//	}
//	
//
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	struct node* node = NULL;
//	node = Initialize(n);
//	Resort(node, n);
//
//	struct node* current = node;
//	while (current != NULL) {
//		printf("%d ",current->rank);
//		current = current->next;
//	}
//
//	// Free allocated memory
//	current = node;
//	while (current != NULL) {
//		struct node* temp = current;
//		current = current->next;
//		free(temp);
//	}
//
//	return 0;
//}


//void Resort(struct node* node, int n) {		//수정하기
//	int swapped;
//	struct node* current;
//	struct node* temp = NULL;
//
//	do {
//		swapped = 0;
//		current = node;
//
//		while (current->next != temp) {
//			if (current->data > current->next->data) {
//				current->next->rank++;
//				current->rank--;
//				int tempData = current->data;
//				current->data = current->next->data;
//				current->next->data = tempData;
//				swapped = 1;
//			}
//			current = current->next;
//		}
//		temp = current;
//	} while (swapped);
//}

#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do { type t=x;x=y;y=t;} while(0)
struct array {
	int* x;
	int* rank;
};

void quick(struct array arr, int left, int right) {
	int pl = left;
	int pr = right;
	int x = arr.x[(pl + pr) / 2];
	for (int i = 0; i < pl + pr ; i++) {
		while (arr.x[pl] < x)
			pl++;
		while (arr.x[pr] > x)
			pr--;
		if (pl < pr) {
			swap(int, arr.x[pl], arr.x[pr]);
			swap(int, arr.rank[pl], arr.rank[pr]);
			pl++;
			pr--;
			printf("%d %d\n", pl, pr);
		}
		if (left < pr)
			quick(arr, left, pr);
		if (pl < right)
			quick(arr, pl, right);
	}
	
}

int main() {
	int nx;
	printf("요소 입력:");
	scanf("%d", &nx);
	struct array arr;
	arr. x = calloc(nx, sizeof(int));
	arr.rank =calloc(nx,sizeof(int));
	arr.rank[0] = 0;
	for (int i = 0; i < nx; i++) {
		printf("x[%d]:", i);
		scanf("%d", &arr.x[i]);
		if (i != 0)
			arr.rank[i] = arr.rank[i - 1] + 1;
	}
	quick(arr, 0, nx - 1);
	for (int i = 0; i < nx; i++) {
		printf("%d\n", arr.rank[i]);
	}
	free(arr.x);

	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//struct node {
//	int data;
//	struct node* next;
//};
//
//struct node* CreateNode(int data) {
//	struct node* newnode = (struct node*)malloc(sizeof(struct node));
//	newnode->data = data;
//	newnode->next = NULL;
//	return newnode;
//}
//struct node* Initialize(struct node** node,int n) {
//	if (n <= 0)
//		return *node;
//	int data;
//	scanf("%d", &data);
//	*node = CreateNode(data);
//	
//	(*node)->next = Initialize(&((*node)->next), n - 1);
//	return *node;
//}
//
//struct node* Quick(struct node* node,int n) {
//	struct node* current = node;
//	
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	struct node* node = NULL;
//	node = Initialize(&node, n);
//	Quick(node, n);
//	/*struct node* current = node;
//	while (current != NULL) {
//		printf("%p\n", current->next);
//		printf("%d ", current->data);
//		current = current->next;
//	}*/
//	struct node* freecurrent = node;
//	struct node* temp = NULL;
//	while(freecurrent!=NULL) {
//		temp = freecurrent;
//		free(temp);
//		freecurrent = freecurrent->next;
//	}
//	
//}