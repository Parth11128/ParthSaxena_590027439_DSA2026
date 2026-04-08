#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Push
void push(Stack *s, char c) {
    s->arr[++(s->top)] = c;
}

// Pop
char pop(Stack *s) {
    return s->arr[(s->top)--];
}

// Peek
char peek(Stack *s) {
    return s->arr[s->top];
}

// Check if empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    init(&s);
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push
        else if (ch == '(') {
            push(&s, ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // remove '('
        }
        // Operator
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX] = "A+B*(C^D-E)^(F+G*H)-I";
    char postfix[MAX];

    infixToPostfix(infix, postfix);

    printf("Infix Expression : %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
