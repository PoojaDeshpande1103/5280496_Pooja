#include <stdio.h>
#include <string.h>
#define MAX 1000
char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}
char* isBalanced(char* s) {
    top = -1; 
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else {
            char popped = pop();
            if ((c == ')' && popped != '(') ||
                (c == '}' && popped != '{') ||
                (c == ']' && popped != '[')) {
                return "NO";
            }
        }
    }
    return (top == -1) ? "YES" : "NO";
}

int main() {
    int n;
    scanf("%d", &n);
    char s[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }
    return 0;
}
