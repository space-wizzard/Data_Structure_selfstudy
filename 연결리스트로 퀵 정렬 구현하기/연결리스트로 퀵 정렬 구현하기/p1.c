#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

// ���� ����Ʈ�� ��� ��带 �����Ͽ� �ǹ����� ����, ����, ū ����� �����ϴ�.
struct ListNode* partition(struct ListNode* head, struct ListNode* end, struct ListNode** newHead, struct ListNode** newEnd) {
    struct ListNode* pivot = end;
    struct ListNode* prev = NULL, * cur = head, * tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else {
            if (prev)
                prev->next = cur->next;
            struct ListNode* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

// �� ������ ����Ͽ� ���� ����Ʈ�� �����մϴ�.
struct ListNode* quickSort(struct ListNode* head, struct ListNode* end) {
    if (!head || head == end)
        return head;

    struct ListNode* newHead = NULL, * newEnd = NULL;

    struct ListNode* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        struct ListNode* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSort(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSort(pivot->next, newEnd);

    return newHead;
}

// ���� ����Ʈ�� ���� ã���ϴ�.
struct ListNode* getTail(struct ListNode* head) {
    while (head != NULL && head->next != NULL)
        head = head->next;
    return head;
}

// ���� ����Ʈ�� ����մϴ�.
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    // ���� ����Ʈ�� ��� �߰� (����)
    for (int i = 10; i > 0; i--) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->data = i;
        newNode->next = NULL;
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Unsorted List: ");
    printList(head);

    struct ListNode* newHead = quickSort(head, getTail(head));

    printf("Sorted List: ");
    printList(newHead);

    // �޸� ����
    while (newHead) {
        struct ListNode* temp = newHead;
        newHead = newHead->next;
        free(temp);
    }

    return 0;
}
