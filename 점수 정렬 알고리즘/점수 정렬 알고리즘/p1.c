#include <stdio.h>
#include <stdlib.h>

struct score {
	int math;
	int intel;
	int n;
	struct score* next;
};

struct score* NewNode() {
	struct score* newnode = malloc(sizeof(struct score));
	scanf("%d%d", &newnode->math, &newnode->intel);
	
	newnode->next = NULL;
	return newnode;
}

struct score* Initialize(struct score** head) {
	if (*head == NULL) {
		//(*head)->n = 0;		*head에 메모리 할당 전인데 0을 대입하려고 하면 문제가 발생한다.
		*head = NewNode();		//여기서 *head->next가 아니라 *head에 새 노드를 대입한다는 게 else문과 차이점이다.
		return *head;
	}
	else {
		struct score* curr = *head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = NewNode();
		return curr->next;
	}
}
void SortingIntel(struct score** scores, int n) {
	if (scores[n]->intel < scores[n + 1]->intel) {
		struct score* temp;
		temp = scores[n];
		scores[n] = scores[n + 1];
		scores[n + 1] = temp;
	}
	if (scores[n]->intel == scores[n + 1]->intel) {
		scores[n]->intel = scores[n + 1]->intel;
	}
}

void Print(struct score** scores, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", scores[i]->n, scores[i]->math, scores[i]->intel);
	}
}

void SortingScores(struct score** scores, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (scores[j]->math < scores[j + 1]->math) {
				struct score* temp;
				temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;
			}
			if (scores[j]->math == scores[j + 1]->math) {
				SortingIntel(scores, j);
			}
		}
	}
	Print(scores, n);

}

int main() {
	int n;
	scanf("%d", &n);
	struct score** scores = malloc(n * sizeof(struct score*));
	for (int i = 0; i < n; i++) {
		scores[i] = NULL;	//반드시 scores[i](포인터변수)를 NULL로 초기화하고 값을 대입해야한다. 그렇지 않으면 엉뚱한 곳에 메모리가 배정되는 것을 방지하기 위해 컴파일러가 강제 종료시킨다.
		scores[i] = Initialize(&scores[i]);
		if (i == 0)
			scores[i]->n = 1;
		else
			scores[i]->n = scores[i-1]->n + 1;	//이거를 scores[i]->n++로 하면 애초에 scores[i]->n가 값이 없는 상태에서 ++를 하니까 오류가 난다.
			// 따라서 그냥 그 전 숫자에서 +1한다는 개념으로 가야 한다.
		
	}
	SortingScores(scores, n);

	for (int i = 0; i < n; i++) {
		struct score* current = scores[i];
		while (current != NULL) {
			struct score* temp = current;
			current = current->next;
			free(temp);
		}
	}

}

