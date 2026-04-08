#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize
void init(Stack *s) {
    s->top = -1;
}

// Push
void push(Stack *s, int val) {
    s->arr[++(s->top)] = val;
}

// Pop
int pop(Stack *s) {
    return s->arr[(s->top)--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    Stack s;
    init(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If operand, push to stack
        if (isdigit(ch)) {
            push(&s, ch - '0');  // convert char to int
        }
        // If operator
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);

            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
            }
        }
    }

    return pop(&s); // final result
}

int main() {
    char exp[] = "23*54*+9-";

    int result = evaluatePostfix(exp);

    printf("Postfix Expression: %s\n", exp);
    printf("Result = %d\n", result);

    return 0;
}
