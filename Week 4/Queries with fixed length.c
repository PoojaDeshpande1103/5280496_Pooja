#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int query = 0; query < q; query++) {
        int d;
        scanf("%d", &d);

        int min_max = INT_MAX;
        for (int i = 0; i <= n - d; i++) {
            int max_val = arr[i];
            for (int j = i + 1; j < i + d; j++) {
                if (arr[j] > max_val) {
                    max_val = arr[j];
                }
            }
            if (max_val < min_max) {
                min_max = max_val;
            }
        }
        printf("%d\n", min_max);
    }

    free(arr);
    return 0;
}
