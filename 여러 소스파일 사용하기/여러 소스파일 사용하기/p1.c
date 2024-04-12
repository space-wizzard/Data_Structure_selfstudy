#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char person[30];
	int age;
}Person;

void CompareAge(const Person* p,int num) {
	int max = 0;
	int idx = 0;
	for (int i = 0; i < num - 1; i++) {
		if (p[i].age < p[i + 1].age) {
			max = p[i + 1].age;
			idx = i + 1;
		}
	}
	printf("%s", p[idx].person);
}
int main() {
	int num;
	scanf("%d", &num);
	Person* p = malloc(sizeof(Person) * num);
	for (int i = 0; i < num; i++) {
		scanf("%s", &p[i].person);
		scanf("%d", &p[i].age);
	}
	CompareAge(p,num);
	free(p);
}