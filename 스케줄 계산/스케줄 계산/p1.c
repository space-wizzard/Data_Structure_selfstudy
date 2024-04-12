//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int n;
//	scanf("%d\n", &n);
//	int* arr = calloc(n,sizeof(int));
//
//	for (int i = 0; i < n; i++) {
//		scanf("%d\n", &arr[i]);
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n-i-1; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}			
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		int temp=i
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct schedule {
//	char name;
//	int year;
//	int month;
//	int day;
//	struct schedule* next;
//};
//
//
//
//struct schedule* Newnode(struct schedule* s) {
//	if (s->next == NULL) {
//		
//		return s->next;
//	}
//	else {
//
//	}
//}
//
//void InputArray(struct schedule* s, struct schedule** arr) {
//	if (arr = arr[0]) {
//		*arr = Newnode(s);
//	}
//	else {
//		s->next = Newnode(s);
//	}
//}
//
//void Input(struct schedule* s, int n, struct schedule** arr) {
//	for (int i = 0; i < n; i++) {
//		scanf("%s %d %d %d", &(s->name), &(s->year), &(s->month), &(s->day));
//		InputArray(s, arr[i]);
//		
//		/*arr[i]->name = s->name;
//		arr[i]->year = s->year;
//		arr[i]->month = s->month;
//		arr[i]->day = s->day;*/
//		s = NULL;
//	}
//
//}
//
//int main() {
//	int n;
//	struct schedule* s;
//	struct schedule** arr;	//arr�� �� ���Ұ� struct schedule�� �����͸� �����Ѿ� �Ѵ�. 
//	//��, arr�� �� ��Ҵ� ���������� ���� �Ҵ�� strcut schedule ��ü�� ����Ű�� �������̰�, arr�� �� �������� �迭�̴�.
//	// �� ��Ҹ��� struct schedule*�� ������ ������ �ʿ��ϴ�.
//	
//	s = malloc(sizeof(struct schedule));
//	scanf("%d", &n);
//	arr = calloc(n, sizeof(struct schedule*));
//	Input(&s, n, arr);
//	printf("%s", arr[0]->name);
//	printf("%d", arr[0]->year);
//	printf("%d", arr[0]->month);
//	printf("%d", arr[0]->day);
//
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//struct schedule {
//	char name;
//	int year;
//	int month;
//	int date;
//	struct schedule* next;
//};
//
//struct schedule* NewNode() {
//	struct schedule* newnode = malloc(sizeof(struct schedule));
//	scanf("%s %d %d %d", &(newnode->name), &(newnode->year), &(newnode->month), &(newnode->date));
//	if (newnode->month > 12 || newnode->date > 31) {
//		printf("Wrong Input");
//		return -1;
//	}
//	if (newnode->month / 2 == 0 && newnode->date > 30) {
//		printf("Wrong Input");
//		return -1;
//	}
//	newnode->next = NULL;
//	return newnode;
//}
//void CreateNode(struct schedule* head) {
//	struct schedule* current = head;
//	if (head == NULL) {
//		head = NewNode();
//		//return head;
//	}
//	else {
//		while (current != NULL) {
//			current = current->next;
//		}
//		current = NewNode();
//		//return current;
//	}
//}
//struct schedule* CreateNode(struct schedule* head) {
//	struct schedule* curr = head;
//		while (curr->next != NULL) {
//			curr = curr->next;
//		}
//		curr->next = malloc(sizeof(struct schedule));
//		scanf("%c %d %d %d", &(curr->name), &(curr->year), &(curr->month), &(curr->date));
//		curr->next->next = NULL;
//		return curr->next;
//}
//void Sort(struct schedule** arr) {
//	int max;
//	int temp;
//	while (*arr != NULL) {
//		//max = (*arr)->year;
//		*arr = (*arr)->next;
//		if (*arr > (*arr)->year) {
//			temp = *arr;
//			*arr
//		}
//
//
//	}
//}

//int main() {
//	int n;
//	struct schedule* s = NULL;
//	struct schedule** arr = NULL;
//	scanf("%d", &n);
//	arr = malloc(n * sizeof(struct schedule));
//	for (int i = 0; i < n; i++) {
//		arr[i] = NULL;
//		//arr[i] = CreateNode(s);
//		CreateNode(s);
//	}	
//	Sort(arr[0]->year);
//
//	printf("%d", s->year);
//}


#include <stdio.h>
#include <stdlib.h>

struct schedule {
	int year;
	int month;
	int date;
	char name[10];
	struct schedule* next;
};

struct schedule* Newnode() {
	struct schedule* newnode = malloc(sizeof(struct schedule));
	scanf("%s %d %d %d", (newnode->name), &(newnode->year), &(newnode->month), &(newnode->date));

	if (newnode->month > 12 || newnode->date > 31) {
		printf("Wrong Input");
		scanf("%s %d %d %d", (newnode->name), &(newnode->year), &(newnode->month), &(newnode->date));
	}

	if (newnode->month / 2 == 0 && newnode->date > 30) {
		printf("Wrong Input");
		scanf("%s %d %d %d", (newnode->name), &(newnode->year), &(newnode->month), &(newnode->date));
	}

	newnode->next = NULL;
	return newnode;
}

void Initialize(struct schedule** head) {
	struct schedule* newnode = Newnode();	//ù��° ��带 �����ϴ� �ڵ�

	if (*head == NULL) {
		*head = newnode;
	}

	else {
		struct schedule* current = *head;	//current ������ ���� ������ ������ head->next�� ���� ���ؼ���. ���� �ڵ忡 ������ head->next�� ������ head�� ���� �����ͱ� ������
		//������ ���� ���̴�. ����, ������ head�� ������ struct schedule *s �� ���� �������̴ϱ� ���� �����͸� ����� ���� *head�� �������Ѵ�.
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newnode;
		/*while ((*head)->next != NULL) {
			head = (*head)->next;
		}
		(*head)->next=newnode;
	}
	}*/
	}
}

void SortDate(struct schedule* current) {
	struct schedule* temp = NULL;

	if (current->date > current->next->date) {
		temp = current;
		current = current->next;
		current->next = temp;
	}
}

void SortMonth(struct schedule* current) {
	struct schedule* temp = NULL;

	if (current->month > current->next->month) {
		temp = current;
		current = current->next;
		current->next = temp;
	}

	if (current->month == current->next->month) {
		SortDate(current);
	}
}

void SortYear(struct schedule* s, int n) {
	for (int i = 0; i < n - 1; i++) {
		struct schedule* current = s;
		for (int j = 0; j < n - i - 1; j++) {
			if (current->year > current->next->year) {
				struct schedule* temp = current;
				current = current->next;
				current->next = temp;
			}

			if (current->year == current->next->year) {
				SortMonth(current);
			}
			current = current->next;
		}
	}
}
//void SortYear(struct schedule* s, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		struct schedule* current = s;
//		for (int j = 0; j < n - i - 1; j++) {
//			if (current->year > current->next->year) {
//				struct schedule* temp = current->next;
//				current->next = temp->next;
//				temp->next = current;
//				if (j == 0) {
//					s = temp;
//				}
//			}
//			else if (current->year == current->next->year) {
//				SortMonth(current);
//			}
//			current = current->next;
//		}
//	}
//}


int main() {
	int n;
	scanf("%d", &n);
	struct schedule* s = NULL;
	struct schedule* firsts = NULL;
	for (int i = 0; i < n; i++) {
		Initialize(&s);
			if (i == 0) {
				firsts = s;
			
		}
	}
	//�Ű������� ������������ ������ ���������͸� �Լ����� ��ȯ�� ����ü s������ ������Ʈ���� �ʱ� �����̴�.
	//�״�� s���� NULL���� ������ ���̴�. �ּҸ� ������ ���� �����͸� ����ؾ� s�� ����� ���� ���� �� �ִ�.

	SortYear(firsts,n);

	struct schedule* current = s;
	while (current != NULL) {
		printf("%s %d %d %d\n", current->name, current->year, current->month, current->date);
		current = current->next;
	}

	current = s;
	while (current != NULL) {
		struct schedule* temp;
		temp = current;
		current = current->next;
		free(temp);
	}
}