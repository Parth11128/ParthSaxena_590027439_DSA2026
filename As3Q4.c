#include <stdio.h>
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

// Push operation
void push(Stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->arr[++(s->top)] = c;
    }
}

// Pop operation
char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';  // underflow case
    } else {
        return s->arr[(s->top)--];
    }
}

// Function to check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Function to check balanced expression
int isBalanced(char expr[]) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // If opening bracket, push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // If closing bracket, pop and check
        else if (ch == ')' || ch == '}' || ch == ']') {
            char top = pop(&s);

            if (top == '\0' || !isMatchingPair(top, ch)) {
                return 0; // not balanced
            }
        }
    }

    // If stack is empty → balanced
    return (s.top == -1);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);

    // Remove newline
    expr[strcspn(expr, "\n")] = '\0';

    if (isBalanced(expr)) {
        printf("Expression is Balanced\n");
    } else {
        printf("Expression is NOT Balanced\n");
    }

    return 0;
} 
