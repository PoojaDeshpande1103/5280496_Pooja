#include <stdio.h>
#include <stdlib.h>

int cmpAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int cmpDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}
int main() {
    int q;
    scanf("%d", &q);
     while (q--) {
        int n, k, i, ok = 1;
        scanf("%d %d", &n, &k);
        int A[n], B[n];  
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &B[i]);
            qsort(A, n, sizeof(int), cmpAsc);
             qsort(B, n, sizeof(int), cmpDesc);
             for (i = 0; i < n; i++) {
                if (A[i] + B[i] < k) {
                    ok = 0;
                    break;
                     }
                     }
                      printf(ok ? "YES\n" : "NO\n");
                      }
                      return 0;
                      }
