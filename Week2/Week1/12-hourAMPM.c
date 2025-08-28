#include <stdio.h>

char* timeConversion(char* s) {
    static char result[10]; 
    int hour = (s[0]-'0')*10 + (s[1]-'0');

    if (s[8] == 'A' && hour == 12) hour = 0;   
    if (s[8] == 'P' && hour != 12) hour += 12; 
    
    snprintf(result, sizeof(result), "%02d:%c%c:%c%c",
             hour, s[3], s[4], s[6], s[7]);
    return result;
}

int main(void) {
    char s[11];
    if (scanf("%10s", s) != 1) return 0;
    printf("%s\n", timeConversion(s));
    return 0;
}