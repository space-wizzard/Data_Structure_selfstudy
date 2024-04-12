#include <stdio.h>
#include <stdlib.h>
struct grade {
	char name[10];
	int g1;
	int g2;
	int g3;
};
struct node {
	struct grade g;		//grade 구조체를 담는 구조체
	struct node* n;		// 바로 위 구조체의 주소를 담는 포인터 변수
};
struct grade Score() {
	struct grade grade;
	scanf("%s %d %d %d", &grade.name, &grade.g1, &grade.g2, &grade.g3);
	return grade;
}

struct node* CreateNode() {
	struct node* newnode = malloc(sizeof(struct node));

	newnode->n = NULL;
	newnode->g = Score();
	return newnode;
}


struct node* Initialize(struct node** head) {
	struct node* newnode = CreateNode();

	if (*head == NULL) {
		*head = newnode;
	}
	else {
		struct node* current = *head;
		while (current->n != NULL) {
			current = current->n;
		}
		current->n = newnode;
	}
	return newnode;
}


void Comparing(struct node** nodes,int num,int count) {
	int max = nodes[count]->g.g2;
	int counter = 1;
	for (int i = 0; i < num; i++) {
		if (max < nodes[i]->g.g2) {
			counter++;
		}
	}
	printf("%d\t", counter);
	counter = 1;
	max = nodes[count]->g.g3;
	for (int i = 0; i < num; i++) {
		if (max < nodes[i]->g.g3) {
			counter++;
		}
	}
	printf("%d\t", counter);
}


void Grading(struct node** nodes,int num) {
	int max = nodes[0]->g.g1;
	int count=0;
	for (int i = 0; i < num; i++) {
		if (max < nodes[i]->g.g1) {
			max = nodes[i]->g.g1;
			count = i;
		}
	}
	printf("%s\t", nodes[count]->g.name);
	Comparing(nodes, num, count);
	
	
}


int main() {
	int num;
	scanf("%d", &num);
	struct node** nodes = calloc(num, sizeof((*nodes)->g));
	for (int i = 0; i < num; i++) {
		nodes[i]=Initialize(&nodes[i]);
	}
	Grading(nodes,num);	// 매개변수가 *nodes면 노드들의 배열에 대한 포인터의 배열을 다루게 된다.
			// 위의 Grading인자는 struct node* nodes[]로 배열을 받기를 기대하고 있지만, 형식이 일치하지 않아 오류가 발생한다.

}


//void Initialize( struct node** node) {
//	struct node* newnode = CreateNode(node);
//	struct node* current = malloc(sizeof(node));
//
//	while (current != NULL) {
//		current = current->n;
//		}
//		current= newnode;
//	
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//struct grade {
//	char name[10];
//	int g1;
//	int g2;
//	int g3;
//};
//
//int main() {
//	struct grade* g;
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		g[n] = Score();
//	}
//}