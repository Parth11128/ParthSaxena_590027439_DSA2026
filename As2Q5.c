#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void reverseData(struct Node* head) {
    int n = countNodes(head);
    if (n <= 1)
        return;

    int *arr = (int*)malloc(n * sizeof(int));
    struct Node* temp = head;

    for (int i = 0; i < n; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    temp = head;
    for (int i = n - 1; i >= 0; i--) {
        temp->data = arr[i];
        temp = temp->next;
    }

    free(arr);
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    reverseData(head);

    printf("\nList After Reversing Data:\n");
    display(head);

    return 0;
}
