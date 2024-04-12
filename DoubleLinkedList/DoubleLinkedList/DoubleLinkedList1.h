#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ListNode {
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
}ListNode;

typedef struct {
	ListNode* head;
}HeadNode;

HeadNode* CreateLinkedList();
void PrintList(HeadNode*L);
ListNode* CreateNode();
void InsertNode(HeadNode* L);
ListNode* SearchNode(HeadNode* L, char* x);