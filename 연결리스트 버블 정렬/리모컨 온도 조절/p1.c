//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//	������ ���
//struct schedule {
//	int year;
//	int month;
//	int date;
//	char name[10];
//	struct schedule* next;
//};
//
//struct schedule* Newnode() {
//	struct schedule* newnode = malloc(sizeof(struct schedule));
//	scanf("%s %d %d %d", (newnode->name), &(newnode->year), &(newnode->month), &(newnode->date));
//	if (newnode->month > 12 || newnode->date > 31) {
//		printf("Wrong Input");
//		scanf("%s %d %d %d", (newnode->name), &(newnode->year), &(newnode->month), &(newnode->date));
//	}
//	if (newnode->month % 2 == 0 && newnode->date > 30) {
//		printf("Wrong Input");
//		scanf("%s %d %d %d", (newnode->name), &(newnode->year), &(newnode->month), &(newnode->date));
//	}
//	newnode->next = NULL;
//	return newnode;
//}
//
//void Initialize(struct schedule** head) {
//	struct schedule* newnode = Newnode();
//	if (newnode == NULL) {
//		return;
//	}
//
//	if (*head == NULL) {
//		*head = newnode;
//	}
//	else {
//		struct schedule* current = *head;
//		while (current->next != NULL) {
//			current = current->next;
//		}
//		current->next = newnode;
//	}
//}
//
//void SortDate(struct schedule* current) {
//	struct schedule* temp = NULL;
//	if (current->date > current->next->date) {
//		temp = current->next;
//		current->next = temp->next;
//		temp->next = current;
//	}
//}
//
//void SortMonth(struct schedule* current) {
//	struct schedule* temp = NULL;
//	if (current->month > current->next->month) {
//		temp = current->next;
//		current->next = temp->next;
//		temp->next = current;
//	}
//	if (current->month == current->next->month) {
//		SortDate(current);
//	}
//}
//
//void SortYear(struct schedule* s, int n) {
//	for (int i = 0; i < n - 1; i++) {
//		struct schedule* current = s;
//		for (int j = 0; j < n - i - 1; j++) {
//			if (current->next == NULL) {
//				printf("Finish");
//				break;
//			}
//			if (current->year > current->next->year) {	
//				struct schedule* temp = current->next;
//				current->next = temp->next;
//				temp->next = temp;
//		}
//			if (current->year == current->next->year) {
//				SortMonth(current);
//			}
//			
//		}
//	}
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	struct schedule* firsts = NULL;
//	struct schedule* s = NULL;
//	for (int i = 0; i < n; i++) {
//		Initialize(&s);
//		if (i == 0) {
//			firsts = s;
//		}
//	}
//
//	SortYear(firsts, n);
//	struct schedule* current = s;
//	while (current != NULL) {
//		printf("%s %d %d %d\n", current->name, current->year, current->month, current->date);
//		current = current->next;
//	}
//
//	current = s;
//	while (current != NULL) {
//		struct schedule* temp = current;
//		current = current->next;
//		free(temp);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct machine {
//	int identity;
//	int store;
//	struct machine* next;
//};
//
//struct machine* Newnode() {
//	struct machine* newnode = malloc(sizeof(struct machine));
//	scanf("%d %d", &(newnode->identity), &(newnode->store));
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
//	struct machine* current = mach;
//	while (current != NULL) {
//		if (current->identity > current->next->identity) {
//			struct machine* temp = current;
//			current = current->next;
//			current->next = temp;
//		}
//		current = current->next;
//	}
//}
//
//int main() {
//	struct machine* mach = NULL;
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		Initialize(&mach);
//	}
//
//	SortIdentity(mach);		//���⼭ �ּҸ� ���ڷ� �Լ��� �ѱ��� �ʴ� ������ ���⿡ mach���� ��� ������Ʈ�� �ʿ�� ���� �����̴�.
//	struct machine* current = mach;
//	while (current != NULL) {
//		printf("%d\n", current->identity);
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
//
//}
//���Ḯ��Ʈ ���� �����ϱ�
#include <stdio.h>
#include <stdlib.h>

struct machine {
    int identity;
    int store;
    struct machine* next;
};

struct machine* Newnode() {
    struct machine* newnode = malloc(sizeof(struct machine));
    if (newnode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    scanf("%d %d", &(newnode->identity), &(newnode->store));
    newnode->next = NULL;
    return newnode;
}

void Initialize(struct machine** head) {
    struct machine* newnode = Newnode();
    if (*head == NULL) {
        *head = newnode;
    }
    else {
        struct machine* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

void SortIdentity(struct machine* mach) {
    if (mach == NULL) {
        return;
    }

    int swapped;
    struct machine* current;
    /*struct machine* prev = NULL;*/
    struct machine* temp = NULL;
    do {
        swapped = 0;
        current = mach;
        while (current->next != NULL) {
            if (current->identity > current->next->identity) {
                int tempIdentity = current->identity;           //�ٲ� ����� �ĺ���ȣ, ���差 ����
                int tempStore = current->store;

                current->identity = current->next->identity;    //��� ��ġ �ٲٱ�
                current->next->identity = tempIdentity;

                current->store = current->next->store;          //��� ��ġ �ٲٱ�
                current->next->store = tempStore;
                /*temp = prev->next;
               prev->next = current->next;
                current->next = temp;*/
                swapped = 1;        //������ �Ϸ�������� �ݺ����� ����Ǵ� ���� �����ϱ� ���� 
            }                       //�ѹ��� if���� ������ �ʾҴٴ� ���� ������ �Ϸ�Ǿ��ٴ� �ǹ�
            /*prev = current;*/
            current = current->next;
        }
        
    } while (swapped);
   
}

int main() {
    struct machine* mach = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Initialize(&mach);
    }

    SortIdentity(mach);

    struct machine* current = mach;
    while (current != NULL) {
        printf("%d %d\n", current->identity,current->store);
        current = current->next;
    }

    current = mach;
    while (current != NULL) {
        struct machine* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
