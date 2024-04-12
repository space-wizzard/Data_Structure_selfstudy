//#include <stdio.h>
//#include <stdlib.h>
//
//int countWaysToSum(int n) {
//    // DP ���̺� �ʱ�ȭ
//    int* dp = calloc(n + 1, sizeof(int));
//    dp[0] = 1;  // 0�� ����� ����� �ƹ��͵� �������� �ʴ� ��� 1���� ���
//
//    // ��� ������ ���� 1, 2, 3�� �����ϴ� ����� ���� ����
//    for (int i = 1; i <= n; i++) {
//        dp[i] = 0;
//        for (int j = 1; j <= 3; j++) {
//            // ���� �������� ���� ��쿡�� ���� ����
//            if (i - j >= 0) {
//                dp[i] += dp[i - j];
//            }
//        }
//    }
//
//    return dp[n];
//}
//
//int main() {
//    printf("Test case:");
//    int n;
//    int target;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &target);
//        printf("%d\n", countWaysToSum(target));  // ���: 7 (1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, 3+1)
//    }
//    
//
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>


void Checksort(int n, int* x) {
	int tmp = x[0];
	for (int j = n; j > 0; j--) {
		int count = 0;
		for (int i = 0; i < j - 1; i++) {//���� ������(��������) �� �� �н��� ���� ������ ���ĵ� �����Ͱ��� �ϳ��� �þ��.(�н��� ������ �ϳ��� ���ĵǴ� ����)
			if (x[i] < x[i + 1]) {//���� j-1�� ������ ����� �Ǵ� ������ ������ �ϳ��� ���̰� �ִ�.
				tmp = x[i + 1];
				x[i + 1] = x[i];
				x[i] = tmp;
				count++;
			}
		}
		if (count == 0)//���� count�� 1�̶��, �ѹ��� �н����� ������ �ѹ��̶� �Ͼ ���̴�.
			break;		//�׷��� count�� 0�̶��, �ѹ��� �н����� ������ �ѹ��� �Ͼ�� �ʾҴ�.
	}
}

int Bin_Search(int n, int* x, int k) { //�迭�� �ε����� ���� start,end,middle�� �߰�, middle�� �˻����� ���� �޶����� while�� �ȿ� �ִ�.
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int middle = (start + end) / 2;
		if (x[middle] == k)
			return middle;

		else if (x[middle] < k) {
			start = middle + 1;//start�ϴ� �������� ��ġ�� middle�� �ٲ��. middle�� �˻� ��󿡼� ���ܵǴϱ� +1
			if (start == end) {	//�˰����� ��� ������ ���� start,middle,end ���� 1�� ���̳��� ������ �´�. �׶��� �� 3���� �ε��� ���� ��򰡿� �˻����� ���� ���̶� �Ҹ���.
				printf("�˻����� x[%d]�� x[%d] ���̿� �ֽ��ϴ�. ", middle, end);
			}
		}

		else {
			end = middle - 1;
			if (start + 1 == middle) {
				printf("�˻�����x[%d]�� x[%d]���̿� �ֽ��ϴ�.", start, middle);
			}
		}
	}
	return -1;
}

int main() {
	int n;
	printf("�迭 ���� �Է�: ");
	scanf("%d", &n);
	int* x = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("�迭 ��� �Է�:");
		scanf("%d", &x[i]);
	}
	Checksort(n, x);
	for (int i = 0; i < n; i++) {
		printf("%d\n", x[i]);
	}
	int key;
	printf("�˻� ���:");
	scanf("%d", &key);
	int i = Bin_Search(n, x, key);
	if (i == -1)
		printf("�˻��� �����߽��ϴ�.");
	else
		printf("�˻����� x[%d]�� �ֽ��ϴ�.", i);
	free(x);
	return 0;
}
