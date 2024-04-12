#include "polynomial.h"



int main() {
    int a_degree, b_degree;
    printf("Degree of A? ");
    scanf("%d", &a_degree);
    printf("Degree of B? ");
    scanf("%d", &b_degree);

    polynomial_h* A = malloc(sizeof(polynomial));
    A->head = NULL;
    polynomial_h* B = malloc(sizeof(polynomial));
    B->head = NULL;

    printf("Enter coefficients of A: ");
    int coef;
    scanf("%d", &coef);
    CreateNode(coef,a_degree,A);

    printf("Enter coefficients of B: ");
    scanf("%d", &coef);
   CreateNode(coef,b_degree,B);
    
    addPoly(A, B, a_degree, b_degree);
     //Free memory
    FreeNode(A->head);
    FreeNode(B->head);

    return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node {
//    int coef;
//    struct node* next;
//} polynomial;
//
//typedef struct {
//    polynomial* head;
//} polynomial_h;
//
//void CreateNode(int coefficient, int degree, polynomial_h* top) {
//    if (degree == 0)
//        return;
//    int in_coef;
//    polynomial* newnode = malloc(sizeof(polynomial));
//    if (newnode == NULL) {
//        fprintf(stderr, "Memory allocation failed\n");
//        exit(EXIT_FAILURE);
//    }
//    newnode->coef = coefficient;
//    newnode->next = top->head;
//    top->head = newnode;
//
//    if (coefficient == 0)
//        in_coef = 0;
//    else
//        scanf("%d", &in_coef);
//    CreateNode(in_coef, degree - 1, top);
//}
//
//void InsertNodeLast(int loop, polynomial* node) {
//    if (loop == 0)
//        return;
//    polynomial* curr = node;
//    polynomial* newnode = malloc(sizeof(polynomial));
//    newnode->coef = 0;
//    newnode->next = NULL;
//    while (curr->next != NULL)
//        curr = curr->next;
//    curr->next = newnode;
//    InsertNodeLast(loop - 1, curr->next);
//}
//
//void addPoly(polynomial_h* a, polynomial_h* b, int a_degree_count, int b_degree_count) {
//    int diff_index = abs(a_degree_count - b_degree_count);
//    int idx = (a_degree_count > b_degree_count) ? a_degree_count : b_degree_count;
//
//    if (a_degree_count > b_degree_count) {
//        InsertNodeLast(diff_index, b->head);
//    }
//    else {
//        InsertNodeLast(diff_index, a->head);
//    }
//
//    polynomial* a_curr = a->head;
//    polynomial* b_curr = b->head;
//    for (int i = 0; i <= idx; i++) {
//        int coef_a = (a_curr != NULL) ? a_curr->coef : 0;
//        int coef_b = (b_curr != NULL) ? b_curr->coef : 0;
//        printf("%dx^%d", coef_a + coef_b, idx - i);
//        if (i != idx)
//            printf(" + ");
//        if (a_curr != NULL) a_curr = a_curr->next;
//        if (b_curr != NULL) b_curr = b_curr->next;
//    }
//    printf("\n");
//}
//
//void FreeNode(polynomial* node) {
//    polynomial* curr = node;
//    polynomial* temp = NULL;
//    while (curr != NULL) {
//        temp = curr;
//        curr = curr->next;
//        free(temp);
//    }
//}
//
//int main() {
//    int a_degree, b_degree;
//    printf("Degree of A? ");
//    scanf("%d", &a_degree);
//    printf("Degree of B? ");
//    scanf("%d", &b_degree);
//
//    polynomial_h* A = malloc(sizeof(polynomial_h));
//    A->head = NULL;
//    polynomial_h* B = malloc(sizeof(polynomial_h));
//    B->head = NULL;
//
//    printf("Enter coefficients of A: ");
//    int coef;
//    scanf("%d", &coef);
//    CreateNode(coef, a_degree, A);
//
//    printf("Enter coefficients of B: ");
//    scanf("%d", &coef);
//    CreateNode(coef, b_degree, B);
//
//    addPoly(A, B, a_degree, b_degree);
//
//    // Free memory
//    FreeNode(A->head);
//    FreeNode(B->head);
//    free(A);
//    free(B);
//
//    return 0;
//}
