#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

   
    int **arr = (int **)malloc(n * sizeof(int *));
    int *sizes = (int *)calloc(n, sizeof(int));     
    int *capacity = (int *)calloc(n, sizeof(int));  
    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            
            if (sizes[idx] == capacity[idx]) {
                capacity[idx] = (capacity[idx] == 0) ? 1 : capacity[idx] * 2;
                arr[idx] = (int *)realloc(arr[idx], capacity[idx] * sizeof(int));
            }
            arr[idx][sizes[idx]++] = y; // append y
        } else {
            lastAnswer = arr[idx][y % sizes[idx]];
            printf("%d\n", lastAnswer);
        }
    }

    return 0;
}
