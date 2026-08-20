#include <stdio.h>

#define MAX 31

int isValid(char s[]) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else {
            if (top == -1) {
                return 0;
            }

            char top_char = stack[top--];

            if ((ch == ')' && top_char != '(') ||
                (ch == '}' && top_char != '{') ||
                (ch == ']' && top_char != '[')) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    char expression[MAX];

    scanf("%30s", expression);

    if (isValid(expression))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
