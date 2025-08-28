#include <stdio.h>
#include <string.h>


long superDigit(long n) {
    if (n < 10) return n;
    long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return superDigit(sum);
}

int main() {
    char n[100001];  
    int k;
    scanf("%s %d", n, &k);

    long sum = 0;
    for (int i = 0; i < strlen(n); i++)
        sum += n[i] - '0';    
    sum *= k;  
    printf("%ld\n", superDigit(sum));
    return 0;
}
