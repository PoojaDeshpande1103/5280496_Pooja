#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int), cmp);

    int minUnfair = arr[k-1] - arr[0];
    for (int i = 1; i <= arr_count - k; i++) {
        int diff = arr[i+k-1] - arr[i];
        if (diff < minUnfair) {
            minUnfair = diff;
        }
    }
    return minUnfair;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxMin(k, n, arr);
    printf("%d\n", result);
    return 0;
}
