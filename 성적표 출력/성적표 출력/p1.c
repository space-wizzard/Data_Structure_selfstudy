//#include <stdio.h>
//#include <stdlib.h>
//
//struct machine {
//	char identity;
//	int store;
//	struct machine* next;
//};
//
//struct machine* Newnode() {
//	struct machine* newnode = malloc(sizeof(struct machine));
//	if (newnode == NULL) {
//		printf("Memory allocation error\n");
//		exit(1);
//	}
//	scanf("%s %d", &(newnode->identity), &(newnode->store));
//	newnode->next = NULL;
//	return newnode;
//}
//
//void Initialize(struct machine** head) {
//	struct machine* newnode = Newnode();
//	if (*head == NULL) {
//		*head = newnode;
//	}
//	else {
//		struct machine* current = *head;
//		while (current->next != NULL) {
//			current = current->next;
//		}
//		current->next = newnode;
//	}
//}
//
//void SortIdentity(struct machine* mach) {
//	if (mach == NULL) {
//		return;
//	}
//
//	int swapped;
//	struct machine* current;
//	//struct machine* prev = mach;
//	struct machine* temp = NULL;
//	do {
//		swapped = 0;
//		current = mach;
//			while (current->next != NULL) {
//				if (current->identity > current->next->identity) {
//					int tempIdentity = current->identity; //바꿀 노드의 식별번호, 저장량 저장
//					int tempStore = current->store;
//
//					current->identity = current->next->identity; //노드 위치 바꾸기
//					current->next->identity = tempIdentity;
//
//					current->store = current->next->store; //노드 위치 바꾸기
//					current->next->store = tempStore;
//					/*temp = prev->next;
//					prev->next = current->next;
//					current->next = temp;*/
//					swapped = 1; //정렬이 완료됐음에도 반복문이 실행되는 것을 방지하기 위해
//				} //한번도 if문에 들어오지 않았다는 것은 정렬이 완료되었다는 의미
//				/*prev = current;*/
//				current = current->next;
//			}
//	} while (swapped);
//
//}
//
//int main() {
//	struct machine* mach = NULL;
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		Initialize(&mach);
//	}
//	SortIdentity(mach);
//
//	struct machine* current = mach;
//	while (current != NULL) {
//		printf("%c %d\n", current->identity, current->store);
//		current = current->next;
//	}
//
//	current = mach;
//	while (current != NULL) {
//		struct machine* temp = current;
//		current = current->next;
//		free(temp);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct score {
//	char name[10];
//	int data[];
//}s;
//
//int main() {
//	s.data[0] = 1;
//	s.name[0] = "ewrwe";
//	s.name[1] = "wefewf";
//	printf("%c", s.name[1]);
//}