#include <stdio.h>
#include <string.h>

int main() {
    int n, q, count = 0;
    scanf("%d", &n);

    char input[n][100]; 
    for (int i = 0; i < n; i++) {
        scanf("%s", input[i]); 
    }

    scanf("%d", &q);
    char query[q][100];
    int result[q];

    for (int i = 0; i < q; i++) {
        scanf("%s", query[i]); 
    }
    for (int i = 0; i < q; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(query[i], input[j]) == 0) {
                count++;
            }
        }
        result[i] = count;
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
