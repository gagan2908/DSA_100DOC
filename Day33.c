/* Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity */ 

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        }

        // If opening bracket, push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If closing bracket, pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();  // Remove '('
        }

        // If operator
        else {
            while (top != -1 &&
                   peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}