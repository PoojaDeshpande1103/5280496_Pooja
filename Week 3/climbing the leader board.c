#include <stdio.h>
#include <stdlib.h>
int* climbingLeaderboard(int* ranked, int ranked_count, int* player, int player_count, int* result_count) {
    int* result = (int*)malloc(player_count * sizeof(int));
    *result_count = player_count;
    int* scores = (int*)malloc(ranked_count * sizeof(int));
    int n = 0;
    scores[n++] = ranked[0];
    for (int i = 1; i < ranked_count; i++) {
        if (ranked[i] != scores[n - 1]) {
            scores[n++] = ranked[i];
        }
    }
    int i = n - 1;
    for (int j = 0; j < player_count; j++) {
        while (i >= 0 && player[j] >= scores[i]) {
            i--;
        }
        result[j] = i + 2; 
    }
    free(scores);
    return result;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int ranked[n];
    for (int i = 0; i < n; i++) scanf("%d", &ranked[i]);
    scanf("%d", &m);
    int player[m];
    for (int i = 0; i < m; i++) scanf("%d", &player[i]);
    int result_count;
    int* result = climbingLeaderboard(ranked, n, player, m, &result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}
