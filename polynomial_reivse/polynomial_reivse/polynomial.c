#include "polynomial.h"

void CreateNode(int coefficient, int degree, polynomial_h* top) {

    int in_coef;
    polynomial* newnode = malloc(sizeof(polynomial));
    if (newnode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newnode->coef = coefficient;
    newnode->next = NULL;
    newnode->next = top->head;
    top->head = newnode;
    if (degree == 0)
        return;
    if (coefficient == 0)
        in_coef = 0;
    else
        scanf("%d", &in_coef);
    CreateNode(in_coef, degree - 1, top);

}

void InsertNodeLast(int loop, polynomial* node) {
    if (loop == 0)
        return;
    polynomial* curr = node;
    polynomial* newnode = malloc(sizeof(polynomial));
    newnode->coef = 0;
    newnode->next = NULL;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newnode;
    InsertNodeLast(loop - 1, curr->next);

}

void addPoly(polynomial_h* a, polynomial_h* b, int a_degree_count, int b_degree_count) {
    int diff_index = abs(a_degree_count - b_degree_count);
    int idx = 0;
    // a 식의 차수가 큰 경우
    if (a_degree_count > b_degree_count) {
        InsertNodeLast(diff_index, b->head);
        idx = a_degree_count;
    }

    //b 식의 차수가 큰 경우
    else {
        InsertNodeLast(diff_index, a->head);
        idx = b_degree_count;
    }

    polynomial* a_curr = a->head;
    polynomial* b_curr = b->head;
    int* a_arr = calloc(10, sizeof(int));
    a_arr = PrintNode(a_curr);
    printf("a나옴\n");
    int* b_arr = calloc(10, sizeof(int));
    b_arr = PrintNode(b_curr);
    printf("b나옴\n");
    PrintPolynomial(idx, a_arr, b_arr, a_curr, b_curr);
}

void PrintPolynomial(int idx, int a_arr[], int b_arr[], polynomial* a_curr, polynomial* b_curr) {
    for (int i = 0; i <= idx; i++) {
        if (idx == i) {
            printf("%d", a_arr[i]);
            break;
        }

        if (a_arr[i] == 0)
            printf(" ");
        else
            printf("%dx^%d+", a_arr[i], idx - i);
    }
    printf(" + ");
    for (int i = 0; i <= idx; i++) {
        if (idx == i) {
            printf("%d", b_arr[i]);
            break;
        }

        if (b_arr[i] == 0)
            printf(" ");
        else
            printf("%dx^%d+", b_arr[i], idx - i);
    }
    printf(" = ");
    for (int i = 0; i <= idx; i++) {
        //printf("%d %d\n", a_arr[i], b_arr[i]);
        if (i == idx)
            printf("%d", a_arr[i] + b_arr[i]);
        else
            printf("%dx^%d+", a_arr[i] + b_arr[i], idx - i);

        a_curr = a_curr->next;
        b_curr = b_curr->next;
    }
}

int* PrintNode(polynomial* node) {
    polynomial* curr = NULL;
    curr = node;
    int count = 1;
    while (curr != NULL) {
        printf("node data");
        printf("%d\n", curr->coef);
        curr = curr->next;
        count++;
    }
    printf("COunt:%d\n", count);
    curr = node;
    int* arr = calloc(count, sizeof(int));
    int i = count - 2;
    while (curr != NULL) {
        arr[i] = curr->coef;
        printf("%d. %d\n", i, arr[i]);
        curr = curr->next;
        i--;
    }
    return arr;
}

void FreeNode(polynomial* node) {
    polynomial* curr = node;
    polynomial* temp = NULL;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}
