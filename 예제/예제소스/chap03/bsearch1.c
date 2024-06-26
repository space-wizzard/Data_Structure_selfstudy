// bsearch 함수를 사용해 오름차순으로 정렬된 배열을 검색
#include <stdio.h>
#include <stdlib.h>

/*--- 정수를 비교하는 함수(오름차순) ---*/
int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

int main(void)
{
    int nx, ky;
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열을 생성

    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // 바로 앞의 값보다 작으면 다시 입력
    }
    printf("검색값: ");
    scanf("%d", &ky);
    int *p = bsearch(
                &ky,                            // 검색값에 대한 포인터
                x,                              // 배열
                nx,                             // 요소의 개수
                sizeof(int),                    // 요소의 크기
                (int (*)(const void *, const void *))int_cmp    // 비교 함수
             );
    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d은(는) x[%d]에 있습니다.\n", ky, (int)(p - x));
    free(x);                            // 배열 x를 해제
    return 0;
}
