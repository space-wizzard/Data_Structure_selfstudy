#include <stdio.h>

#define MAX_SIZE 1001

typedef struct _node
{
    int idx;
    int imp;
} node;

node queue[MAX_SIZE];
int idx_rear = 0, idx_front = 0;

void push(node x);
node pop();
int next_pos(int idx);
int is_empty();

int main()
{
    int tc, num_paper, target;

    scanf("%d", &tc);

    while (tc--)
    {
        int importance[10] = { 0 }; // �߿䵵�� 1~9 �߿䵵 ������ ��
        int cnt = 0;              // ���� �μ� ����
        scanf(" %d %d", &num_paper, &target);

        for (int i = 0; i < num_paper; i++) // push
        {
            node temp = { i, 0 };     // idx: i
            scanf("%d", &temp.imp); // imp: �Է�
            importance[temp.imp]++;

            push(temp);
        }

        for (;;) // ��� pop
        {
            int flag = 1; // ��� ���� ����
            node doc = pop();

            // pop�� ���� �߿䵵 ���� �� �߿��� ���� �ִ��� Ȯ��
            for (int k = doc.imp + 1; k < 10; k++)
            {
                if (importance[k] > 0)
                {
                    push(doc);
                    flag = 0;
                    break; // ���� ������
                }
            }

            if (flag == 1)
            {
                cnt++;
                importance[doc.imp]--;

                if (doc.idx == target)
                {
                    printf("%d\n", cnt);
                    break; // ���� �׽�Ʈ���̽���
                }
            }
        }

        // ť ���� <<< ������ �ڵ�
        while (!is_empty())
        {
            pop();
        }
    }

    return 0;
}

void push(node x)
{
    idx_rear = next_pos(idx_rear);
    queue[idx_rear] = x;
}

node pop()
{
    if (is_empty())
    {
        node t = { -1, -1 };
        return t;
    }
    else
    {
        idx_front = next_pos(idx_front);
        return queue[idx_front];
    }
}

int next_pos(int idx)
{
    return idx == MAX_SIZE ? 1 : idx + 1;
}

int is_empty()
{
    return idx_rear == idx_front ? 1 : 0;
}
