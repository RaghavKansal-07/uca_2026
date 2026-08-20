#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int evalPostfix(char expression[]) {
    int stack[MAX];
    int top = -1;

    char *token = strtok(expression, " ");

    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a + b;
        }
        else if (strcmp(token, "-") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a - b;
        }
        else if (strcmp(token, "*") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a * b;
        }
        else if (strcmp(token, "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = a / b;
        }
        else {
            stack[++top] = atoi(token);
        }

        token = strtok(NULL, " ");
    }

    return stack[top];
}

int main() {
    char expression[50];

    fgets(expression, sizeof(expression), stdin);

    printf("%d\n", evalPostfix(expression));

    return 0;
}
