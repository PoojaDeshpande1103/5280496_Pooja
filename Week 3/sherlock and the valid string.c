#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* isValid(char* s) {
    static char result[4]; 
    int freq[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    int count[26], k = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            count[k++] = freq[i];
        }
    }
    int min = count[0], max = count[0];
    for (int i = 1; i < k; i++) {
        if (count[i] < min) min = count[i];
        if (count[i] > max) max = count[i];
    }
    if (min == max) {
        strcpy(result, "YES");
        return result;
    }
    int minCount = 0, maxCount = 0;
    for (int i = 0; i < k; i++) {
        if (count[i] == min) minCount++;
        else if (count[i] == max) maxCount++;
    }
    if (maxCount == 1 && (max - min == 1) && (minCount + maxCount == k)) {
        strcpy(result, "YES");
        return result;
    }
    if (minCount == 1 && min == 1 && (minCount + maxCount == k)) {
        strcpy(result, "YES");
        return result;
    }
    strcpy(result, "NO");
    return result;
}
int main() {
    char s[100005];
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}
