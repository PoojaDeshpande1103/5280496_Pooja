#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmpfunc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    int t;
    scanf("%d", &t);  

    while (t--) {
        int n;
        scanf("%d", &n); 

        char grid[n][n + 1]; 

        
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
            qsort(grid[i], n, sizeof(char), cmpfunc);
        }

     
        int valid = 1;
        for (int col = 0; col < n && valid; col++) {
            for (int row = 0; row < n - 1; row++) {
                if (grid[row][col] > grid[row + 1][col]) {
                    valid = 0;
                    break;
                }
            }
        }

        printf(valid ? "YES\n" : "NO\n");
    }

    return 0;
}
