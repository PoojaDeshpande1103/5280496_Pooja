#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** bomberMan(int n, int r, int c, char** grid) {
    char **full = malloc(r * sizeof(char*));
    char **after1 = malloc(r * sizeof(char*));
    char **after2 = malloc(r * sizeof(char*));

    for (int i = 0; i < r; i++) {
        full[i] = malloc(c + 1);
        after1[i] = malloc(c + 1);
        after2[i] = malloc(c + 1);
        for (int j = 0; j < c; j++) {
            full[i][j] = 'O';
            after1[i][j] = 'O';
            after2[i][j] = 'O';
        }
        full[i][c] = after1[i][c] = after2[i][c] = '\0';
    }
    if (n == 1) return grid;
    if (n % 2 == 0) return full;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'O') {
                after1[i][j] = '.';
                if (i > 0) after1[i-1][j] = '.';
                if (i < r-1) after1[i+1][j] = '.';
                if (j > 0) after1[i][j-1] = '.';
                if (j < c-1) after1[i][j+1] = '.';
            }
        }
    }
    if (n % 4 == 3) return after1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (after1[i][j] == 'O') {
                after2[i][j] = '.';
                if (i > 0) after2[i-1][j] = '.';
                if (i < r-1) after2[i+1][j] = '.';
                if (j > 0) after2[i][j-1] = '.';
                if (j < c-1) after2[i][j+1] = '.';
            }
        }
    }
    return after2;
}
int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);

    char **grid = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        grid[i] = malloc(c + 1);
        scanf("%s", grid[i]);
    }
    char **result = bomberMan(n, r, c, grid);
    for (int i = 0; i < r; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
