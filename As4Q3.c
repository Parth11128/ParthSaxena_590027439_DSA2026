#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX];
int front = 0, rear = -1;

// Enqueue operation
void enqueue(char ch) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        rear++;
        queue[rear] = ch;
    }
}

// Dequeue operation
char dequeue() {
    if (front > rear) {
        return '\0';
    } else {
        return queue[front++];
    }
}

int main() {
    char str[MAX];
    int i, len, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // Insert characters into queue
    for (i = 0; i < len; i++) {
        enqueue(str[i]);
    }

    // Compare with reverse using array
    for (i = len - 1; i >= 0; i--) {
        char ch = dequeue();
        if (str[i] != ch) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("The string is a Palindrome\n");
    else
        printf("The string is NOT a Palindrome\n");

    return 0;
}
