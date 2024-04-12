#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int coef;
    struct node* next;
} polynomial;

typedef struct {
    polynomial* head;
} polynomial_h;

void CreateNode(int coefficient, int degree, polynomial_h* top);
void InsertNodeLast(int loop, polynomial* node);
void addPoly(polynomial_h* a, polynomial_h* b, int a_degree_count, int b_degree_count);
void PrintPolynomial(int idx, int a_arr[], int b_arr[], polynomial* a_curr, polynomial* b_curr);
int* PrintNode(polynomial* node);
void FreeNode(polynomial* node);
