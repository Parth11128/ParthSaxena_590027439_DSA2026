#include <stdio.h>
#define MAX 5

// Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Initialize queue
void init(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check empty
int isQueueEmpty(struct Queue *q) {
    return (q->front == -1);
}

// Check full
int isQueueFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

// Enqueue
void enqueue(struct Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = value;
}

// Dequeue
int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        return -1;
    }
    int val = q->arr[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return val;
}

// Global queues
struct Queue q1, q2;

// Push operation
void push(int x) {
    enqueue(&q2, x);

    // Move all elements from q1 to q2
    while (!isQueueEmpty(&q1)) {
        enqueue(&q2, dequeue(&q1));
    }

    // Swap q1 and q2
    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;

    printf("Pushed: %d\n", x);
}

// Pop operation
void pop() {
    if (isQueueEmpty(&q1)) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", dequeue(&q1));
}

// Peek operation
void peek() {
    if (isQueueEmpty(&q1)) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", q1.arr[q1.front]);
    }
}

// isEmpty
void isEmpty() {
    if (isQueueEmpty(&q1))
        printf("Stack is empty\n");
    else
        printf("Stack is NOT empty\n");
}

// Display stack
void display() {
    if (isQueueEmpty(&q1)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = q1.front; i <= q1.rear; i++) {
        printf("%d ", q1.arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    init(&q1);
    init(&q2);

    while (1) {
        printf("\n--- Stack using Two Queues ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                isEmpty();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
