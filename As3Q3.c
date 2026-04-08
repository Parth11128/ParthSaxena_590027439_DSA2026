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
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s->arr[(s->top)--];
    }
}

int main() {
    Stack s;
    char str[MAX];
    int i;

    init(&s);

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';

    // Push all characters into stack
    for (i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    // Pop characters to reverse string
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = pop(&s);
    }

    printf("Reversed string: %s\n", str);

    return 0;
} 
