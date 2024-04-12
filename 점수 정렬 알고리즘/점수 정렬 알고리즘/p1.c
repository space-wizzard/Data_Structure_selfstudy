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
		//(*head)->n = 0;		*head�� �޸� �Ҵ� ���ε� 0�� �����Ϸ��� �ϸ� ������ �߻��Ѵ�.
		*head = NewNode();		//���⼭ *head->next�� �ƴ϶� *head�� �� ��带 �����Ѵٴ� �� else���� �������̴�.
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
		scores[i] = NULL;	//�ݵ�� scores[i](�����ͺ���)�� NULL�� �ʱ�ȭ�ϰ� ���� �����ؾ��Ѵ�. �׷��� ������ ������ ���� �޸𸮰� �����Ǵ� ���� �����ϱ� ���� �����Ϸ��� ���� �����Ų��.
		scores[i] = Initialize(&scores[i]);
		if (i == 0)
			scores[i]->n = 1;
		else
			scores[i]->n = scores[i-1]->n + 1;	//�̰Ÿ� scores[i]->n++�� �ϸ� ���ʿ� scores[i]->n�� ���� ���� ���¿��� ++�� �ϴϱ� ������ ����.
			// ���� �׳� �� �� ���ڿ��� +1�Ѵٴ� �������� ���� �Ѵ�.
		
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

