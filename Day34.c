/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Push operation
void push(Node **top, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    Node *temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);

    return value;
}

int main() {
    char expr[200];

    fgets(expr, sizeof(expr), stdin);

    Node *top = NULL;

    char *token = strtok(expr, " \n");

    while (token != NULL) {

        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&top, atoi(token));
        }
        else {
            int b = pop(&top);
            int a = pop(&top);
            int result;

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                default:
                    printf("Invalid Operator\n");
                    return 0;
            }

            push(&top, result);
        }

        token = strtok(NULL, " \n");
    }

    printf("%d\n", pop(&top));

    return 0;
}