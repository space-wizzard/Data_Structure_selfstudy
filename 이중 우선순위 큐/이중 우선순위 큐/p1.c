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
	
		newnode->next = NULL;		//��� �ȿ� �ּ��� NULL�̶� �Է��ؾ� ��ǻ�Ͱ� ���� �ν��ϰ� ���� ���� �Ѿ��. �� ������ ���� ����� �ּҸ� �����ϴ� ����
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
	//	struct node* curr = head;	//��忡�� �����ؼ�..
	//	while (curr->next != NULL) {
	//		curr = curr->next;			// ��� ������ �ݺ��� ����, ����� ���ڶ��� �����ϸ�,
	//	}
	//	curr = newnode;			// ��带 �߰��Ѵ�.
	//	return curr;
	//}

}
// ��带 ������ ���� ��� ��带 ������ ���� �Ϲ� ��带 ������ ���� ��������� �Ѵ�.
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
		struct node* curr = head->next;	//curr�� head->next�� �ؾ� head->data(���� ��)�� ã�� �һ�簡 �Ͼ�� �ʴ´�.
		struct node* prev = head;		//prev�� �����ϸ�, ������ ���� ���� ��忡, �ּҰ��� ���� ��忡 �ִ� ������ �ؼ��� �� �ִ�.
		switch (a) {
		case 'I':
			n = AppendNode(head, n, data);	// ��ȯ��: ���� ���� ���(next�� ���� ���� ��尡 ����Ǿ� �ְ�, data���� �Է°��� ����)
			break;
		case 'D':
				if (data == 1) {
					tmp = -100000;		//��û ���� ���� �����ϰ�, 
					while (curr != NULL) {
						if (curr->data > tmp) {
							tmp = curr->data;
							max_node = prev;	//���� ��带 �ѱ� �� curr->next�� �ѱ�� �� ���� ��带 �ѱ�� ���̴�. �ݵ�� curr�� �ѱ⵵�� �Ѵ�.
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
//// ���� �켱���� ť�� �ʱ�ȭ�ϴ� �Լ�
//void initializeQueue(DualPriorityQueue* q) {
//    q->size = 0;
//}
//
//// �ִ񰪰� �ּڰ��� ���ÿ� �����ϴ� �Լ�
//void insertData(DualPriorityQueue* q, int data) {
//    q->heap[q->size] = data;
//    int idx = q->size;
//
//    while (idx > 0 && q->heap[idx] > q->heap[(idx - 1) / 2]) {
//        // �ִ� �� ����
//        int temp = q->heap[idx];
//        q->heap[idx] = q->heap[(idx - 1) / 2];
//        q->heap[(idx - 1) / 2] = temp;
//        idx = (idx - 1) / 2;
//    }
//
//    q->size++;
//}
//
//// �ִ��� �����ϴ� �Լ�
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
//            // �ִ� �� ����
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
//// �ּڰ��� �����ϴ� �Լ�
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
//            // �ּ� �� ����
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
//// �ִ񰪰� �ּڰ� ���
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


