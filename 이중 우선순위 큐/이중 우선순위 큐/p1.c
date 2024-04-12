#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};


struct node* CreateNode(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if (newnode == NULL) {
		printf("Memory allocation splitted!");
	}
	
		newnode->next = NULL;		//노드 안에 최소한 NULL이라도 입력해야 컴퓨터가 노드로 인식하고 다음 노드로 넘어간다. 이 변수는 다음 노드의 주소를 저장하는 변수
		newnode->data = data;
		return newnode;
	
	
}

struct node* AppendNode(struct node* head,struct node* n,int data) {
	
	struct node* newnode = CreateNode(data);
	if (n == NULL) {
		head->next = newnode;
		return newnode;
	}
	else {
		n->next = newnode;
		return newnode;
	}
	//else {
	//	struct node* curr = head;	//헤드에서 시작해서..
	//	while (curr->next != NULL) {
	//		curr = curr->next;			// 노드 끝까지 반복한 다음, 노드의 끝자락에 도달하면,
	//	}
	//	curr = newnode;			// 노드를 추가한다.
	//	return curr;
	//}

}
// 노드를 제거할 때도 헤드 노드를 제거할 때와 일반 노드를 제거할 때를 구분지어야 한다.
void RemoveNode(struct node* prev,struct node* storage) {
	/*if (storage->next == NULL) {
		printf("EMPTY");
	}*/
	prev->next = storage->next;
	free(storage);
	
}


int main() {
	int k;
	char a;
	int data;
	scanf("%d", &k);
	struct node* n = NULL;
	struct node* head = (struct node*)malloc(sizeof(struct node));
	for (int i = 0; i < k; i++) {
		scanf(" %c%d", &a, &data);
		int tmp;
		struct node* max_node = NULL;
		struct node* min_node = NULL;
		struct node* curr = head->next;	//curr에 head->next를 해야 head->data(없는 값)을 찾는 불상사가 일어나지 않는다.
		struct node* prev = head;		//prev를 선언하면, 데이터 값은 다음 노드에, 주소값은 이전 노드에 있는 괴리를 해소할 수 있다.
		switch (a) {
		case 'I':
			n = AppendNode(head, n, data);	// 반환값: 새로 만든 노드(next에 새로 만든 노드가 저장되어 있고, data에도 입력값이 있음)
			break;
		case 'D':
				if (data == 1) {
					tmp = -100000;		//엄청 작은 수를 지정하고, 
					while (curr != NULL) {
						if (curr->data > tmp) {
							tmp = curr->data;
							max_node = prev;	//현재 노드를 넘길 때 curr->next를 넘기면 그 다음 노드를 넘기는 것이다. 반드시 curr를 넘기도록 한다.
						}
						prev = curr;
						curr = curr->next;
					}
					RemoveNode(max_node,max_node->next);
				}

				if (data == -1) {
					tmp =1000000;
					while (curr != NULL) {
						if (curr->data < tmp) {
							tmp = curr->data;
							min_node = prev;
						}
						prev = curr;
						curr = curr->next;
					}
					RemoveNode(min_node,min_node->next);
				}
				break;
			
				
		default:
			printf("Wrong input1");
			break;
			}
		}
		struct node* current = head->next;
		struct node* temp;
		while (current != NULL) {
			printf("%d ", current->data);
			current = current->next;
			if (current->next == NULL) {
				printf(" ");
			}
		}

		while (current != NULL) {
			temp = head->next;
			head->next = temp->next;
			free(temp);
		}
		free(head);

		return 0;
	}


//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 10000
//
//typedef struct DualPriorityQueue {
//    int heap[MAX_SIZE];
//    int size;
//} DualPriorityQueue;
//
//// 이중 우선순위 큐를 초기화하는 함수
//void initializeQueue(DualPriorityQueue* q) {
//    q->size = 0;
//}
//
//// 최댓값과 최솟값을 동시에 삽입하는 함수
//void insertData(DualPriorityQueue* q, int data) {
//    q->heap[q->size] = data;
//    int idx = q->size;
//
//    while (idx > 0 && q->heap[idx] > q->heap[(idx - 1) / 2]) {
//        // 최대 힙 구성
//        int temp = q->heap[idx];
//        q->heap[idx] = q->heap[(idx - 1) / 2];
//        q->heap[(idx - 1) / 2] = temp;
//        idx = (idx - 1) / 2;
//    }
//
//    q->size++;
//}
//
//// 최댓값을 삭제하는 함수
//void deleteMax(DualPriorityQueue* q) {
//    if (q->size == 0) {
//        printf("Queue is empty.\n");
//        return;
//    }
//
//    q->heap[0] = q->heap[q->size - 1];
//    q->size--;
//
//    int idx = 0;
//    while (idx * 2 + 1 < q->size) {
//        int child;
//        if (idx * 2 + 2 == q->size) {
//            child = idx * 2 + 1;
//        }
//        else {
//            child = (q->heap[idx * 2 + 1] > q->heap[idx * 2 + 2]) ? idx * 2 + 1 : idx * 2 + 2;
//        }
//
//        if (q->heap[idx] < q->heap[child]) {
//            // 최대 힙 구성
//            int temp = q->heap[idx];
//            q->heap[idx] = q->heap[child];
//            q->heap[child] = temp;
//            idx = child;
//        }
//        else {
//            break;
//        }
//    }
//}
//
//// 최솟값을 삭제하는 함수
//void deleteMin(DualPriorityQueue* q) {
//    if (q->size == 0) {
//        printf("Queue is empty.\n");
//        return;
//    }
//
//    int idx = 0;
//    while (idx * 2 + 1 < q->size) {
//        int child;
//        if (idx * 2 + 2 == q->size) {
//            child = idx * 2 + 1;
//        }
//        else {
//            child = (q->heap[idx * 2 + 1] < q->heap[idx * 2 + 2]) ? idx * 2 + 1 : idx * 2 + 2;
//        }
//
//        if (q->heap[idx] > q->heap[child]) {
//            // 최소 힙 구성
//            int temp = q->heap[idx];
//            q->heap[idx] = q->heap[child];
//            q->heap[child] = temp;
//            idx = child;
//        }
//        else {
//            break;
//        }
//    }
//
//    q->heap[q->size - 1] = 0;
//    q->size--;
//}
//
//// 최댓값과 최솟값 출력
//void printMaxAndMin(DualPriorityQueue* q) {
//    if (q->size == 0) {
//        printf("Queue is empty.\n");
//    }
//    else {
//        printf("Maximum value: %d\n", q->heap[0]);
//        printf("Minimum value: %d\n", q->heap[q->size - 1]);
//    }
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    DualPriorityQueue queue;
//    initializeQueue(&queue);
//
//    for (int i = 0; i < n; i++) {
//        char command;
//        int data;
//        scanf(" %c%d", &command, &data);
//
//        if (command == 'I') {
//            insertData(&queue, data);
//        }
//        else if (command == 'D') {
//            if (data == 1) {
//                deleteMax(&queue);
//            }
//            else if (data == -1) {
//                deleteMin(&queue);
//            }
//        }
//    }
//
//    printMaxAndMin(&queue);
//
//    return 0;
//}


